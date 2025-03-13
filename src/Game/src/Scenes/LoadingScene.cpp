//
// Created by daydream on 10.02.25.
//

#include "LoadingScene.h"

#include <iostream>

LoadingScene::LoadingScene(const std::shared_ptr<FentEngine::AssetManager>& assetManager) : m_assetManager(assetManager) {}


void LoadingScene::initScene() {

    m_assetManager->loadSound("main_menu_theme.mp3");
    PlaySound(m_mainMenuMusic);
    m_assetManager->test();
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
