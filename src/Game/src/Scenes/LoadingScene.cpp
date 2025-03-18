//
// Created by daydream on 10.02.25.
//

#include "LoadingScene.h"

#include <iostream>

LoadingScene::LoadingScene(const std::shared_ptr<FentEngine::AssetManager>& assetManager, const std::shared_ptr<FentEngine::AudioManager>& audioManager)
: m_assetManager(assetManager), m_audioManager(audioManager)  {}


void LoadingScene::initScene() {
    InitAudioDevice();

    m_mainMenuMusic = m_assetManager->loadMusic("marabu.mp3");
    m_audioManager->stopAllSounds();
    PlayMusicStream(m_mainMenuMusic);
}

void LoadingScene::cleanupScene() {
}

void LoadingScene::update(float deltaTime) {
    UpdateMusicStream(m_mainMenuMusic);
}

void LoadingScene::render(FentEngine::Renderer& renderer) {
    DrawText("Loading...", GetScreenWidth() / 2, GetScreenHeight() - 100, 32, WHITE);
}

// LoadingScene &LoadingScene::getInstance() {
//     static LoadingScene instance;
//     return instance;
// }
