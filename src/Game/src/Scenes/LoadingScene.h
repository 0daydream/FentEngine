//
// Created by daydream on 10.02.25.
//

#ifndef LOADINGSCENE_H
#define LOADINGSCENE_H

// Engine Includes
#include "../../../Engine/Scene/Scene.h"
#include "../../../Engine/Renderer/Renderer.h"

#include "raylib.h"


class LoadingScene : public FentEngine::Scene {
private:
    Rectangle rect;
    int speed;

public:
    LoadingScene();
    ~LoadingScene() override = default;

    void initScene() override;
    void cleanupScene() override;

    void update(float deltaTime) override;
    void render(FentEngine::Renderer& renderer) override;

    // static LoadingScene& getInstance();

};


#endif //LOADINGSCENE_H
