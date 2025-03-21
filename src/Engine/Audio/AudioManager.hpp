//
// Created by daydream on 11.03.25.
//

#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include "../Asset/AssetManager.h"

#include <iostream>
#include <vector>

#include "../Structs.h"

namespace FentEngine {
    class AudioManager {
    private:
        std::shared_ptr<FentEngine::AssetManager> m_assetManager;
        std::vector<FentSound> m_soundVec;
        std::vector<FentSound> m_musicVec;

    public:
        explicit AudioManager(const std::shared_ptr<FentEngine::AssetManager>& assetManager);
        ~AudioManager() = default;

        // Sounding
        void playSound(const std::string& fileName, float volume = 1.0f) const;
        void stopSound(const std::string& fileName) const;
        [[maybe_unused]]void stopAllSounds() const;

        // Music
        void playMusic(const std::string& fileName, float volume = 1.0f) const;
        void loopMusic(const std::string& fileName, float volume = 1.0f) const;
        void stopMusic(const std::string& fileName = {}) const;
        void pauseMusic() const;
        void resumeMusic() const;

        // TODO: Set volume based on settings
        // Add Settings
        void setSoundVolume(float volume = 1.0f) const;
        void setMusicVolume(float volume = 1.0f) const;
        void setGlobalVolume(float volume = 1.0f) const;
        float getGlobalVolume() const;
        float getSoundVolume() const;
        float getMusicVolume() const;

    };
}



#endif //AUDIO_HPP
