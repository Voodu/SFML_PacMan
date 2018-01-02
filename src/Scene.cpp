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

void Scene::changeScene(Scene* newScene)
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

//private
void Scene::initGameObjects()
{
    for (auto object : objects)
    {
        object->id = GameObject::counter++;
        object->init(*this);
        if (object->physical)
        {
            std::cout << "Added physical\n";
            physicalObjects.push_back(object);
        }
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
        if (true) //(physOb->tag == "None") TODO
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
    while (!removeBuffer.empty())
    {
        if (removeBuffer.top()->physical)
        {
            std::vector<GameObject *>::iterator o = std::find(physicalObjects.begin(), physicalObjects.end(), removeBuffer.top());
            delete *o;
            physicalObjects.erase(o);
        }

        std::vector<GameObject *>::iterator o = std::find(objects.begin(), objects.end(), removeBuffer.top());
        delete *o;
        objects.erase(o);
        removeBuffer.pop();
    }
}

void Scene::addGOs()
{
    while (!addBuffer.empty())
    {
        if (addBuffer.top()->physical)
        {
            physicalObjects.push_back(addBuffer.top());
        }

        objects.push_back(addBuffer.top());
        objects.back()->init(*this);
        addBuffer.pop();
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