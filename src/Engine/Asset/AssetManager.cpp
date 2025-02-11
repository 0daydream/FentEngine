//
// Created by daydream on 10.02.25.
//

#include <iostream>
#include "AssetManager.h"

AssetManager::~AssetManager() {
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
    std::cout << "AssetManager::~AssetManager: All assets have been released!\n";
}


bool AssetManager::checkExistingTexture(const std::string& fileName) const {
    return m_textures.contains(fileName);
}

void AssetManager::loadTexture(const std::string& fileName) {
    if (!checkExistingTexture(fileName)) {
        m_assetsPath = std::filesystem::current_path().string() + TEXTURES_PATH;

        Image tempImage = LoadImage(m_assetsPath.c_str());
        if (!IsImageValid(tempImage)) {
            std::cout << "AssetManager::loadTexture::IsImageValid: Failed to load image -> " << fileName << "\n";
            return;
        }

        Texture2D tempTex = LoadTextureFromImage(tempImage);
        if (!IsTextureValid(tempTex)) {
            std::cout << "AssetManager::loadTexture: Failed to load texture -> " << fileName << "\n";
        }
        else {
            m_textures.insert(std::pair<std::string, Texture2D>(fileName, tempTex));
        }

        UnloadImage(tempImage);
        UnloadTexture(tempTex);
    }
    else {
        std::cout << "AssetManager::loadTexture::checkExistingTexture: Texture already exists -> " << fileName << "\n";
    }
}

void AssetManager::unloadTexture(const std::string& fileName) const {
    if (checkExistingTexture(fileName)) {
        UnloadTexture(m_textures.at(fileName));
    }
    else {
        std::cout << "AssetManager::unloadTexture: Texture not found -> " << fileName << "\n";
    }
}

bool AssetManager::checkExistingFont(const std::string& fileName) const {
    ;
    return m_fonts.contains(fileName);
}

void AssetManager::loadFont(const std::string& fileName) {
    if (!checkExistingFont(fileName)) {
        m_assetsPath = std::filesystem::current_path().string() + FONTS_PATH;

        Font tempFont = LoadFont(m_assetsPath.c_str());
        if (!IsFontValid(tempFont)) {
            std::cout << "AssetManager::loadFont::IsFontValid: Failed to load font -> " << fileName << "\n";
        }
        else {
            m_fonts.insert(std::pair<std::string, Font>(fileName, tempFont));
        }
        UnloadFont(tempFont);
    }
    else {
        std::cout << "AssetManager::loadFont::checkExistingFont: Font already exists -> " << fileName << "\n";
    }
}

void AssetManager::unloadFont(const std::string& fileName) const {
    if (checkExistingFont(fileName)) {
        UnloadFont(m_fonts.at(fileName));
    }
    else {
        std::cout << "AssetManager::unloadFont::checkExistingFont: Font not found -> " << fileName << "\n";
    }
}


bool AssetManager::checkExistingSound(const std::string& fileName) const {
    return m_sounds.contains(fileName);
}

void AssetManager::loadSound(const std::string& fileName) {
    if (!checkExistingSound(fileName)) {
        m_assetsPath = std::filesystem::current_path().string() + SOUNDS_PATH;

        Sound tempSound = LoadSound(m_assetsPath.c_str());
        if (!IsSoundValid(tempSound)) {
            std::cout << "AssetManager::loadSound::IsSoundValid: Failed to load sound -> " << fileName << "\n";
        }
        else {
            m_sounds.insert(std::pair<std::string, Sound>(fileName, tempSound));
        }

        UnloadSound(tempSound);
    }
    else {
        std::cout << "AssetManager::loadSound::checkExistingSound: Sound not found -> " << fileName << "\n";
    }
}

void AssetManager::unloadSound(const std::string& fileName) const {
    if (checkExistingSound(fileName)) {
        UnloadSound(m_sounds.at(fileName));
        std::cout << "AssetManager::unloadSound::checkExistingSound: Sound unloaded -> " << fileName << "\n";
    }
    else {
        std::cout << "AssetMaanger::unloadSound::checkExistingSound: Sound not found -> " << fileName << "\n";
    }
}


Texture2D AssetManager::getTexture(const std::string& fileName) {
    auto it = m_textures.find(fileName);

    if (it != m_textures.end()) {
        return it->second;
    }
    std::cout << "AssetManager::getTexture: Texture not found -> " << fileName << "\n";
    return {};
}

Font AssetManager::getFont(const std::string& fileName) {
    auto it = m_fonts.find(fileName);

    if (it != m_fonts.end()) {
        return it->second;
    }
    std::cout << "AssetManager::getFont: Texture not found -> " << fileName << "\n";
    return {};
}

Sound AssetManager::getSound(const std::string& fileName) {
    auto it = m_sounds.find(fileName);

    if (it != m_sounds.end()) {
        return it->second;
    }
    std::cout << "AssetManager::getSound: Texture not found -> " << fileName << "\n";
    return {};
}

AssetManager& AssetManager::getInstance() {
    static AssetManager instance;
    return instance;
}