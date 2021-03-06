#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include <iostream>
#include "Scene.hpp"
#include "Transform.hpp"
class Scene;

class GameObject
{
    friend class Scene;

  public:
    GameObject();
    GameObject(Transform transform);
    bool enabled = true;
    bool physical = false; //to private & make accessors (setter! must remove from physObj in scene)
    size_t layer = 0;      //to private & make accessors (setter! must re-sort in scene)
    bool operator==(const GameObject &rhs) { return id == rhs.id; }
    std::string tag = "None";
    std::string idString = "None";
    size_t getId() { return id; }
    virtual ~GameObject(){}; //TO OVERRIDE
    Transform transform;

  private:
    static size_t counter;
    size_t id;

  protected:
    Scene *scene;
    virtual void init() = 0;                            //TO OVERRIDE, other objects may not be spawned yet
    virtual void start() = 0;                           //TO OVERRIDE, can look for other objects on scene
    virtual void update() = 0;                          //TO OVERRIDE
    virtual void render() = 0;                          //TO OVERRIDE
    virtual void onCollision(GameObject *other) = 0;    //TO OVERRIDE
    virtual void parseMessage(std::string message) = 0; //TO OVERRIDE
};

#endif // !GAMEOBJECT_HPP