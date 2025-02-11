//
// Created by daydream on 10.02.25.
//

#ifndef SCENE_H
#define SCENE_H

#include "../Renderer/Renderer.h"

namespace FentEngine {
    class Scene {
    private:

    public:
        Scene() = default;
        virtual ~Scene() = default;

        // I don't know what to do with these functions.
        // I could use them in the future, maybe.
        virtual void initScene() = 0;
        virtual void cleanupScene() = 0;

        virtual void update(float deltaTime) = 0;
        virtual void render(Renderer& renderer) = 0;

    };
}

#endif //SCENE_H
