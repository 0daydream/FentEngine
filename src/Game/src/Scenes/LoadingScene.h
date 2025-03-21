//
// Created by daydream on 10.02.25.
//

#ifndef LOADINGSCENE_H
#define LOADINGSCENE_H

// Engine Includes
#include "../../../Engine/Asset/AssetManager.h"
#include "../../../Engine/Audio/AudioManager.hpp"
#include "../../../Engine/Scene/Scene.h"
#include "../../../Engine/Renderer/Renderer.h"

#include "raylib.h"


class LoadingScene : public FentEngine::Scene {
private:
    std::shared_ptr<FentEngine::AssetManager> m_assetManager;
    std::shared_ptr<FentEngine::AudioManager> m_audioManager;

    // Make struct out of it!!!
    Music m_mainMenuMusic;

public:
    explicit LoadingScene(
        const std::shared_ptr<FentEngine::AssetManager>& assetManager,
        const std::shared_ptr<FentEngine::AudioManager>& audioManager
        );
    ~LoadingScene() override = default;

    void initScene() override;
    void cleanupScene() override;

    void update(float deltaTime) override;
    void render(FentEngine::Renderer& renderer) override;

    // static LoadingScene& getInstance();

};


#endif //LOADINGSCENE_H
