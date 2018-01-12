#include "../include/Scene.hpp"
//protected

//public
void Scene::addGameObject(GameObject *go)
{
    addBuffer.push_back(go);
}

void Scene::removeGameObject(GameObject *go)
{
    removeBuffer.push_back(go);
}

void Scene::passMessage(std::string idString, std::string message)
{
    for (auto object : objects)
    {
        if (object->idString == idString)
        {
            object->parseMessage(message);
            return;
        }
    }
}

void Scene::passMessages(std::string tag, std::string message)
{
    for (auto object : objects)
    {
        if (object->tag == tag)
        {
            object->parseMessage(message);
        }
    }
}

void Scene::changeScene(Scene *newScene)
{
    nextScene = newScene;
}

bool Scene::isColliding(Transform &transform, string_set ignoredTags)
{
    for (auto object : physicalObjects)
    {
        if (ignoredTags.find(object->tag) == ignoredTags.end())
        {
            if (object->transform.collides(transform))
            {
                return true;
            }
        }
    }

    return false;
}

void Scene::draw(sf::Drawable &object)
{
    window->draw(object);
}

std::vector<GameObject *> Scene::findObjectsByTag(std::string tag)
{
    std::vector<GameObject *> v;
    for (auto object : objects)
    {
        if (object->tag == tag)
        {
            v.push_back(object);
        }
    }

    return v;
}

GameObject *Scene::findObjectByIdString(std::string idString)
{
    for (auto object : objects)
    {
        if (object->idString == idString)
        {
            return object;
        }
    }

    return nullptr;
}

//private
void Scene::initGameObjects()
{
    for (auto object : objects)
    {
        object->id = GameObject::counter++;
        object->scene = this;
        object->init();

        if (object->physical)
        {
            physicalObjects.push_back(object);
        }
    }
    for (auto object : objects)
    {
        object->start();
    }
}

void Scene::collectEvents()
{
    sf::Event event;
    events.clear();
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Escape))
        {
            window->close();
        }
        events.push_back(event);
    }
}

void Scene::updatePhysics()
{
    for (auto physObMain : physicalObjects)
    {
        if (triggeringTags.find(physObMain->tag) != triggeringTags.end())
        {
            for (auto physObOther : physicalObjects)
            {
                if (physObMain != physObOther)
                {
                    if (physObMain->transform.collides(physObOther->transform))
                    {
                        physObMain->onCollision(physObOther);
                        physObOther->onCollision(physObMain);
                        break;
                    }
                }
            }
        }
    }
}

void Scene::updateStateAndRender()
{
    window->clear();
    for (auto object : objects)
    {
        if (object->enabled)
        {
            object->update();
            object->render();
        }
    }
    window->display();
}

void Scene::updateGameObjectsVector()
{
    removeGOs();
    addGOs();
    sortByLayer();
}

void Scene::removeGOs()
{
    std::vector<GameObject *> copied = std::move(removeBuffer);
    for (auto object : copied)
    {
        removeFromPhys(object);
        removeFromOrd(object);
    }
}

void Scene::removeFromPhys(GameObject *go)
{
    std::vector<GameObject *>::iterator o = std::find(physicalObjects.begin(), physicalObjects.end(), go);
    if (o != physicalObjects.end())
    {
        physicalObjects.erase(o);
    }
}

void Scene::removeFromOrd(GameObject *go)
{
    std::vector<GameObject *>::iterator o = std::find(objects.begin(), objects.end(), go);
    if (o != objects.end())
    {
        delete *o;
        objects.erase(o);
    }
}

void Scene::addGOs()
{
    std::vector<GameObject *> copied = std::move(addBuffer);
    for (auto object : copied)
    {
        addToPhys(object);
        addToOrd(object);
    }
    for (auto object : copied)
    {
        object->start();
    }
}

void Scene::addToPhys(GameObject *go)
{
    if (go->physical)
    {
        physicalObjects.push_back(go);
    }
}

void Scene::addToOrd(GameObject *go)
{
    objects.push_back(go);
    objects.back()->id = GameObject::counter++;
    objects.back()->scene = this;
    objects.back()->init();
}

void Scene::init()
{
    std::vector<GameObject *> temp = loadGameObjects();
    objects.insert(objects.begin(), temp.begin(), temp.end());
    initGameObjects();
    sortByLayer();
}

void Scene::act()
{
    collectEvents();
    updatePhysics();
    updateStateAndRender();
    updateGameObjectsVector();
}

void Scene::sortByLayer()
{
    std::sort(objects.begin(), objects.end(), [](auto &x, auto &y) { return x->layer < y->layer; });
}

Scene::~Scene()
{
    for (auto var : objects)
    {
        delete var;
    }
}