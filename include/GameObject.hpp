#ifndef GAMEOBJECT_HPP
#define GAMEOBJECT_HPP
#include "Scene.hpp"
#include "Transform.hpp"
class Scene;

class GameObject
{
    friend class Scene;

  public:
    bool enabled = true;
    bool physical = false; //to private & make accessors (setter! must remove from physObj in scene)
    size_t layer = 0;      //to private & make accessors (setter! must re-sort in scene)
    bool operator==(const GameObject &rhs) { return id == rhs.id; }
    std::string tag = "None";
    std::string idString = "None";
    size_t getId() { return id; }
    virtual ~GameObject(){}; //TO OVERRIDE

  private:
    static size_t counter;
    size_t id;

  protected:
    Transform transform;
    Scene *scene;
    virtual void init(Scene &scene) = 0;                //TO OVERRIDE
    virtual void update() = 0;                          //TO OVERRIDE
    virtual void render() = 0;                          //TO OVERRIDE
    virtual void onCollision(GameObject *other) = 0;    //TO OVERRIDE
    virtual void parseMessage(std::string message) = 0; //TO OVERRIDE
};

#endif // !GAMEOBJECT_HPP