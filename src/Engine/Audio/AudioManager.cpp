//
// Created by daydream on 11.03.25.
//

#include "AudioManager.hpp"

FentEngine::AudioManager::AudioManager(const std::shared_ptr<FentEngine::AssetManager>& assetManager) :
m_assetManager(assetManager) {}

void FentEngine::AudioManager::playSound(const std::string& fileName, const float volume) const {
    if (m_assetManager->checkExistingSound(fileName)) {
        const Sound sound = m_assetManager->getSound(fileName);
        SetSoundVolume(sound, volume);
        PlaySound(sound);
    }
}

void FentEngine::AudioManager::stopSound(const std::string& fileName) const {
    if (m_assetManager->checkExistingSound(fileName)) {
        const Sound sound = m_assetManager->getSound(fileName);
        StopSound(sound);
    }
}

void FentEngine::AudioManager::stopAllSounds() const {
    if (!m_assetManager) {
        std::cerr << "AudioManager::stopAllSounds: m_assetManager is null!\n";
        return;
    }

    const auto& hashmap = m_assetManager->getSoundHashmap();
    if (hashmap.empty()) {
        std::cerr << "AudioManager::stopAllSounds No sounds to stop!\n";
        return;
    }

    for (const auto& [key, sound] : hashmap) {
        StopSound(sound);
    }
}

void FentEngine::AudioManager::playMusic(const std::string& fileName, float volume) const {
    if (m_assetManager->checkExistingMusic(fileName)) {
        Music music = m_assetManager->loadMusic(fileName);
        SetMusicVolume(music, volume);
        PlayMusicStream(music);
    }
}

void FentEngine::AudioManager::stopMusic(const std::string& fileName) const {
    if (m_assetManager->checkExistingMusic(fileName)) {
        const Music music = m_assetManager->loadMusic(fileName);
        StopMusicStream(music);
    }
}

void FentEngine::AudioManager::pauseMusic() {
    if (!m_assetManager) {
        std::cerr << "AudioManager::stopAllSounds: m_assetManager is null!\n";
        return;
    }

    const auto& hashmap = m_assetManager->getMusicHashmap();
    if (hashmap.empty()) {
        std::cerr << "AudioManager::stopAllSounds No sounds to stop!\n";
        return;
    }

    for (const auto& [key, music] : hashmap) {
        PauseMusicStream(music);
    }
}

void FentEngine::AudioManager::resumeMusic() {

}


