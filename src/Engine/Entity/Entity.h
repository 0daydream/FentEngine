//
// Created by daydream on 10.02.25.
//

#ifndef ENTITY_H
#define ENTITY_H

#include "../Renderer/Renderer.h"
#include "../Structs.h"

#include <utility>

class Entity {
private:

public:
    Entity() = default;
    virtual ~Entity() = default;

    virtual void update(float deltaTime) = 0;
    virtual void render(FentEngine::Renderer& renderer) = 0;

    // Getter Functions
    virtual Rectangle getEntityHitbox() = 0;
    virtual VapeEntity& getVapeEntity() = 0;

};


#endif //ENTITY_H
