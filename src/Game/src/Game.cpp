//
// Created by daydream on 10.02.25.
//

// Engine Includes
#include "../../Engine/Scene/SceneManager.h"
#include "Game.h"

#include "Game.h"

#include <iostream>

Game::Game() {
    m_assetManager = std::make_shared<FentEngine::AssetManager>();
    m_sceneManager->addScene("menu", std::make_shared<LoadingScene>(m_assetManager));
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
