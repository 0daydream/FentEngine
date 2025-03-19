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

    const auto& soundHashmap = m_assetManager->getSoundHashmap();
    if (soundHashmap.empty()) {
        std::cerr << "AudioManager::stopAllSounds No sounds to stop!\n";
        return;
    }

    for (const auto& [key, sound] : soundHashmap) {
        StopSound(sound);
    }
}

void FentEngine::AudioManager::playMusic(const std::string& fileName, const float volume) const {
    if (m_assetManager->checkExistingMusic(fileName)) {
        Music music = m_assetManager->loadMusic(fileName);
        SetMusicVolume(music, volume);
        PlayMusicStream(music);
    }
}

void FentEngine::AudioManager::loopMusic(const std::string& fileName, const float volume) const {
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

void FentEngine::AudioManager::pauseMusic() const {
    const auto& musicHashmap = m_assetManager->getMusicHashmap();
    if (musicHashmap.empty()) {
        std::cerr << "AudioManager::pauseMusic No sounds to stop!\n";
        return;
    }

    for (const auto& [key, music] : musicHashmap) {
        PauseMusicStream(music);
    }
}

void FentEngine::AudioManager::resumeMusic() const {
    const auto& musicHashmap = m_assetManager->getMusicHashmap();
    if (musicHashmap.empty()) {
        std::cerr << "AudioManager::resumeMusic No sounds to resume!\n";
        return;
    }

    for (const auto& [key, music] : musicHashmap) {
        ResumeMusicStream(music);
    }
}

void FentEngine::AudioManager::setSoundVolume(const float volume) const {
    const auto& soundHashmap = m_assetManager->getSoundHashmap();
    if (soundHashmap.empty()) {
        std::cerr << "AudioManager::setGlobalVolume No sounds to set volume.\n";
    }
    for (const auto& [key, sound] : soundHashmap) {
        SetSoundVolume(sound, volume);
    }
}

void FentEngine::AudioManager::setMusicVolume(const float volume) const {
    const auto& musicHashmap = m_assetManager->getMusicHashmap();

    if (musicHashmap.empty()) {
        std::cerr << "AudioManager::setGlobalVolume No sounds to set volume.\n";
        return;
    }
    for (const auto& [key, music] : musicHashmap) {
        SetMusicVolume(music, volume);
    }
}


void FentEngine::AudioManager::setGlobalVolume(const float volume) const {
    setSoundVolume(volume);
    setMusicVolume(volume);
}

float FentEngine::AudioManager::getGlobalVolume() const {

}