//
// Created by daydream on 11.03.25.
//

#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include "../Asset/AssetManager.h"

#include <iostream>

namespace FentEngine {
    class AudioManager {
    private:
        std::shared_ptr<FentEngine::AssetManager> m_assetManager;

    public:
        explicit AudioManager(const std::shared_ptr<FentEngine::AssetManager>& assetManager);
        ~AudioManager() = default;

        // Sounding
        void playSound(const std::string& fileName, float volume = 1.0f) const;
        void stopSound(const std::string& fileName) const;
        [[maybe_unused]]void stopAllSounds() const;

        // Music
        void playMusic(const std::string& fileName, float volume = 1.0f) const;
        void loopMusic(const std::string& fileName, float volume = 1.0f);
        void stopMusic(const std::string& fileName = {}) const;
        void pauseMusic();
        void resumeMusic();

        void setGlobalVolume(float volume = 1.0f);
        float getGlobalVolume() const;

    };
}



#endif //AUDIO_HPP
