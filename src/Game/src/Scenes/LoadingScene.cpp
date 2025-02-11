//
// Created by daydream on 10.02.25.
//

#include "LoadingScene.h"

#include <iostream>

LoadingScene::LoadingScene() {
    speed = 500;

    rect.height = 50;
    rect.width = 50;
    rect.x = 20;
    rect.y = 20;
}


void LoadingScene::initScene() {
}

void LoadingScene::cleanupScene() {
}

void LoadingScene::update(float deltaTime) {
}

void LoadingScene::render(FentEngine::Renderer& renderer) {
    DrawText("Loading...", GetScreenWidth() / 2, GetScreenHeight() - 100, 32, WHITE);
}

// LoadingScene &LoadingScene::getInstance() {
//     static LoadingScene instance;
//     return instance;
// }
