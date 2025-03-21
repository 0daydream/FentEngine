//
// Created by daydream on 10.02.25.
//

#ifndef GAME_H
#define GAME_H

// Engine Includes
#include "../../Engine/Asset/AssetManager.h"
#include "../../Engine/Scene/SceneManager.h"
#include "../../Engine/Audio/AudioManager.hpp"

#include "Scenes/LoadingScene.h"
#include "raylib.h"

class Game {
private:
    FentEngine::Renderer m_renderer;

    std::unique_ptr<FentEngine::SceneManager> m_sceneManager = std::make_unique<FentEngine::SceneManager>();
    std::shared_ptr<FentEngine::AssetManager> m_assetManager;
    std::shared_ptr<FentEngine::AudioManager> m_audioManager;

public:
    Game();
    ~Game() = default;

    void init();
    void update(float deltaTime);
    void render();
    void cleanup();

};

#endif //GAME_H
