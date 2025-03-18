//
// Created by daydream on 10.02.25.
//

// Engine Includes
#include "../../Engine/Scene/SceneManager.h"
#include "Game.h"

#include "Game.h"

#include <iostream>

Game::Game() {
    //Initialize instances
    m_assetManager = std::make_shared<FentEngine::AssetManager>();
    m_audioManager = std::make_shared<FentEngine::AudioManager>(m_assetManager);

    m_sceneManager->addScene("menu", std::make_shared<LoadingScene>(m_assetManager, m_audioManager));
}

void Game::init() {
    std::cout<<"Initializing..."<<std::endl;

    m_sceneManager->switchScene("menu");
}

void Game::update(float deltaTime) {
    m_sceneManager->update(deltaTime);
}

void Game::render() {
    m_sceneManager->render(m_renderer);
}

void Game::cleanup() {
}
