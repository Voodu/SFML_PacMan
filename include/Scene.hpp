#ifndef SCENE_HPP
#define SCENE_HPP

#include "Engine.hpp"
#include "GameObject.hpp"
#include "Transform.hpp"
#include <vector>
#include <algorithm>
#include <unordered_set>

typedef std::unordered_set<std::string> string_set;

class GameObject;

class Scene
{
    friend class Engine;

  protected:
    virtual std::vector<GameObject *> loadGameObjects() = 0; //adding all GO-s //TO OVERRIDE
    string_set triggeringTags;

  public:
    void addGameObject(GameObject *go);
    void removeGameObject(GameObject *go);
    void passMessage(std::string idString, std::string message);
    void passMessages(std::string tag, std::string message);
    void changeScene(Scene *newScene);
    bool isColliding(Transform &transform, string_set ignoredTags = string_set());
    void draw(sf::Drawable &object);
    std::vector<GameObject *> findObjectsByTag(std::string tag);
    GameObject *findObjectByIdString(std::string idString);
    virtual ~Scene();              //TO OVERRIDE
    std::vector<sf::Event> events; //to private and make accessor

  private:
    std::vector<GameObject *> objects; //TODO: change vectors to unordered_sets
    std::vector<GameObject *> physicalObjects;
    std::vector<GameObject *> addBuffer;
    std::vector<GameObject *> removeBuffer;
    sf::RenderWindow *window;
    Scene *nextScene = nullptr;
    void initGameObjects(); //adding all GO-s
    void collectEvents();
    void updatePhysics();           //called by act
    void updateStateAndRender();    //--
    void updateGameObjectsVector(); //--
    void removeGOs();
    void removeFromPhys(GameObject* go);
    void removeFromOrd(GameObject* go);
    void addGOs();
    void addToPhys(GameObject* go);
    void addToOrd(GameObject* go);
    void init(); //called by engine
    void act();  //--
    void sortByLayer();
};

#endif // !SCENE_HPP