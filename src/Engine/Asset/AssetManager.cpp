//
// Created by daydream on 10.02.25.
//

#include <iostream>
#include "AssetManager.h"

FentEngine::AssetManager::~AssetManager() {
    if (!m_textures.empty()) {
        std::cout << "AssetManager::~AssetManager: Unloading textures...\n";
        for (const auto& it : m_textures) {
            UnloadTexture(it.second);
        }
    }

    if (!m_fonts.empty()) {
        std::cout << "AssetManager::~AssetManager: Unloading fonts...\n";
        for (const auto& it : m_fonts) {
            UnloadFont(it.second);
        }
    }

    if (!m_sounds.empty()) {
        std::cout << "AssetManager::~AssetManager: Unloading sounds...\n";
        for (const auto& it : m_sounds) {
            UnloadSound(it.second);
        }
    }

    if (!m_music.empty()) {
        std::cout << "AssetManager::~AssetManager: Unloading music...\n";
        for (const auto& it : m_sounds) {
            UnloadSound(it.second);
        }
    }
    std::cout << "AssetManager::~AssetManager: All assets have been released!\n";
}


bool FentEngine::AssetManager::checkExistingTexture(const std::string& fileName) const {
    return m_textures.contains(fileName);
}

Texture2D FentEngine::AssetManager::loadTexture(const std::string& fileName) {
    if (!checkExistingTexture(fileName)) {
        m_assetsPath = std::filesystem::current_path().string() + TEXTURES_PATH + fileName;

        Image tempImage = LoadImage(m_assetsPath.c_str());
        if (!IsImageValid(tempImage)) {
            std::cerr << "AssetManager::loadTexture::IsImageValid: Failed to load image -> " << fileName << "\n";
            return {};
        }

        Texture2D tempTex = LoadTextureFromImage(tempImage);
        if (!IsTextureValid(tempTex)) {
            std::cerr << "AssetManager::loadTexture: Failed to load texture -> " << fileName << "\n";
            return {};
        }
        else {
            m_textures.insert(std::pair<std::string, Texture2D>(fileName, tempTex));
            return tempTex;
        }

        // UnloadImage(tempImage);
        // UnloadTexture(tempTex);
    }
    else {
        std::cerr << "AssetManager::loadTexture::checkExistingTexture: Texture already exists -> " << fileName << "\n";
        return {};
    }
}

void FentEngine::AssetManager::unloadTexture(const std::string& fileName) const {
    if (checkExistingTexture(fileName)) {
        UnloadTexture(m_textures.at(fileName));
    }
    else {
        std::cerr << "AssetManager::unloadTexture: Texture not found -> " << fileName << "\n";
    }
}

bool FentEngine::AssetManager::checkExistingFont(const std::string& fileName) const {
    ;
    return m_fonts.contains(fileName);
}

Font FentEngine::AssetManager::loadFont(const std::string& fileName) {
    if (!checkExistingFont(fileName)) {
        m_assetsPath = std::filesystem::current_path().string() + FONTS_PATH + fileName;

        Font tempFont = LoadFont(m_assetsPath.c_str());
        if (!IsFontValid(tempFont)) {
            std::cerr << "AssetManager::loadFont::IsFontValid: Failed to load font -> " << fileName << "\n";
            return {};
        }
        else {
            m_fonts.insert(std::pair<std::string, Font>(fileName, tempFont));
            return tempFont;
        }
    }
    else {
        std::cerr << "AssetManager::loadFont::checkExistingFont: Font already exists -> " << fileName << "\n";
        return {};
    }
}

void FentEngine::AssetManager::unloadFont(const std::string& fileName) const {
    if (checkExistingFont(fileName)) {
        UnloadFont(m_fonts.at(fileName));
    }
    else {
        std::cerr << "AssetManager::unloadFont::checkExistingFont: Font not found -> " << fileName << "\n";
    }
}


bool FentEngine::AssetManager::checkExistingSound(const std::string& fileName) const {
    return m_sounds.contains(fileName);
}

Sound FentEngine::AssetManager::loadSound(const std::string& fileName) {
    if (!checkExistingSound(fileName)) {
        m_assetsPath = std::filesystem::current_path().string() + SOUNDS_PATH + fileName;

        Sound tempSound = LoadSound(m_assetsPath.c_str());
        if (!IsSoundValid(tempSound)) {
            std::cerr << "AssetManager::loadSound::IsSoundValid: Failed to load sound -> " << fileName << "\n";
            return {};
        }
        else {
            m_sounds.insert(std::pair<std::string, Sound>(fileName, tempSound));
            return tempSound;
        }
    }
    else {
        std::cerr << "AssetManager::loadSound::checkExistingSound: Audio not found -> " << fileName << "\n";
        return {};
    }
}

void FentEngine::AssetManager::unloadSound(const std::string& fileName) const {
    if (checkExistingSound(fileName)) {
        UnloadSound(m_sounds.at(fileName));
        std::cout << "AssetManager::unloadSound::checkExistingSound: Audio unloaded -> " << fileName << "\n";
    }
    else {
        std::cerr << "AssetManager::unloadSound::checkExistingSound: Audio not found -> " << fileName << "\n";
    }
}

bool FentEngine::AssetManager::checkExistingMusic(const std::string& fileName) const {
    return m_music.contains(fileName);
}

Music FentEngine::AssetManager::loadMusic(const std::string& fileName) {
    if (!checkExistingSound(fileName)) {
        m_assetsPath = std::filesystem::current_path().string() + MUSIC_PATH + fileName;

        Music tempMusic = LoadMusicStream(m_assetsPath.c_str());
        if (!IsMusicValid(tempMusic)) {
            std::cerr << "AssetManager::loadMusic::IsSoundValid: Failed to load sound -> " << fileName << "\n";
            return {};
        }
        else {
            m_music.insert(std::pair<std::string, Music>(fileName, tempMusic));
            return tempMusic;
        }
    }
    else {
        std::cerr << "AssetManager::loadMusic::checkExistingSound: Audio not found -> " << fileName << "\n";
        return {};
    }
}

void FentEngine::AssetManager::unloadMusic(const std::string& fileName) const {
    if (checkExistingMusic(fileName)) {
        UnloadMusicStream(m_music.at(fileName));
        std::cerr << "AssetManager::unloadMusic::checkExistingMusic: Music unloaded -> " << fileName << "\n";
    } else {
        std::cerr << "AssetManager::unloadMusic::checkExistingMusic: Music not found -> " << fileName << "\n";
    }
}


Texture2D FentEngine::AssetManager::getTexture(const std::string& fileName) {
    auto it = m_textures.find(fileName);

    if (it != m_textures.end()) {
        return it->second;
    }
    std::cerr << "AssetManager::getTexture: Texture not found -> " << fileName << "\n";
    return {};
}

Font FentEngine::AssetManager::getFont(const std::string& fileName) {
    auto it = m_fonts.find(fileName);

    if (it != m_fonts.end()) {
        return it->second;
    }
    std::cerr << "AssetManager::getFont: Texture not found -> " << fileName << "\n";
    return {};
}

Sound FentEngine::AssetManager::getSound(const std::string& fileName) {
    auto it = m_sounds.find(fileName);

    if (it != m_sounds.end()) {
        return it->second;
    }
    std::cerr << "AssetManager::getSound: Texture not found -> " << fileName << "\n";
    return {};
}

Music FentEngine::AssetManager::getMusic(const std::string& fileName) {
    auto it = m_music.find(fileName);

    if (it != m_music.end()) {
        return it->second;
    }
    std::cerr<< "AssetManager::getMusic: Music not found -> " << fileName << "\n";
    return {};
}

const std::unordered_map<std::string, Texture2D>& FentEngine::AssetManager::getTextureHashmap() const {
    return m_textures;
}

const std::unordered_map<std::string, Font>& FentEngine::AssetManager::getFontHashmap() const {
    return m_fonts;
}

const std::unordered_map<std::string, Sound>& FentEngine::AssetManager::getSoundHashmap() const {
    return m_sounds;
}

const std::unordered_map<std::string, Music>& FentEngine::AssetManager::getMusicHashmap() const {
    return m_music;
}

// FentEngine::AssetManager& FentEngine::AssetManager::getInstance() {
//     static FentEngine::AssetManager instance;
//     return instance;
// }
