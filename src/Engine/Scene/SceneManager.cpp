//
// Created by daydream on 10.02.25.
//

#include "SceneManager.h"

#include <iostream>

bool FentEngine::SceneManager::checkExistingScene(const std::string& name) const {
    return m_scenes.contains(name);
}

void FentEngine::SceneManager::addScene(const std::string& name, const std::shared_ptr<Scene>& scene) {
    auto [iter, inserted] = m_scenes.try_emplace(name, scene);
    if (!inserted) {
        std::cout << "FentEngine::SceneManager::addScene() -> '" << name << ": Scene already exists!\n";
    } else {
        std::cout << "FentEngine::SceneManager::addScene() -> '" << name << ": Scene successfully added.\n";
    }
}

void FentEngine::SceneManager::switchScene(const std::string& name) {
    if (checkExistingScene(name))
    {
        if (m_currentScene) {
            m_currentScene->cleanupScene();
        }
        m_currentScene = m_scenes[name];
        m_currentScene->initScene();
    }
    else {}
}

void FentEngine::SceneManager::update(float deltaTime) {
    m_currentScene->update(deltaTime);
}

void FentEngine::SceneManager::render(Renderer& renderer) {
    m_currentScene->render(renderer);
}

std::unique_ptr<FentEngine::SceneManager> FentEngine::SceneManager::getInstance()
{
    std::unique_ptr<SceneManager> instance = std::make_unique<SceneManager>();
    return instance;
}