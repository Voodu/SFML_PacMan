#include "../include/Scene.hpp"
//protected

//public
void Scene::addGameObject(GameObject *go)
{
    addBuffer.push(go);
}

void Scene::removeGameObject(GameObject *go)
{
    removeBuffer.push(go);
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
        if (event.type == sf::Event::Closed)
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
    std::stack<GameObject *> copied = std::move(removeBuffer);
    while (!copied.empty())
    {
        if (copied.top()->physical)
        {
            std::vector<GameObject *>::iterator o = std::find(physicalObjects.begin(), physicalObjects.end(), copied.top());
            physicalObjects.erase(o);
        }
        std::vector<GameObject *>::iterator o = std::find(objects.begin(), objects.end(), copied.top());
        delete *o;
        objects.erase(o);
        copied.pop();
    }
}

void Scene::addGOs()
{
    std::stack<GameObject *> startCopy = addBuffer;
    std::stack<GameObject *> copied = std::move(addBuffer);
    while (!copied.empty())
    {
        if (copied.top()->physical)
        {
            physicalObjects.push_back(copied.top());
        }
        objects.push_back(copied.top());
        objects.back()->id = GameObject::counter++;
        objects.back()->scene = this;
        objects.back()->init();
        copied.pop();
    }
    while (!startCopy.empty())
    {
        startCopy.top()->start();
        startCopy.pop();
    }
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