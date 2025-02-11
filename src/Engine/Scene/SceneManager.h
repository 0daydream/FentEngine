//
// Created by daydream on 10.02.25.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../Renderer/Renderer.h"
#include "Scene.h"

#include <string>
#include <unordered_map>
#include <memory>

namespace FentEngine {
    class SceneManager {
    private:
        std::unordered_map<std::string, std::shared_ptr<Scene>> m_scenes;
        std::shared_ptr<Scene> m_currentScene;

    public:
        SceneManager() = default;
        ~SceneManager() = default;

        bool checkExistingScene(const std::string& name) const;

        void addScene(const std::string& name, const std::shared_ptr<FentEngine::Scene>& scene);
        void switchScene(const std::string& name);

        void update(float deltaTime);
        void render(Renderer& renderer);

        static std::unique_ptr<SceneManager> getInstance();

    };
}



#endif //SCENEMANAGER_H
