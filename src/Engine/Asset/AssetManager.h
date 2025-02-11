//
// Created by daydream on 10.02.25.
//

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <memory>
#include <string>
#include <unordered_map>
#include <filesystem>
#include "raylib.h"


constexpr const char* TEXTURES_PATH = "/src/assets/textures/";
constexpr const char* FONTS_PATH = "/src/assets/fonts/";
constexpr const char* SOUNDS_PATH = "/src/assets/sounds/";

class AssetManager {
private:
    std::unordered_map<std::string, Texture2D> m_textures;
    std::unordered_map<std::string, Font> m_fonts;
    std::unordered_map<std::string, Sound> m_sounds;

    std::string m_assetsPath;

public:
    AssetManager() = default;
    ~AssetManager();

    bool checkExistingTexture(const std::string& fileName) const;
    void loadTexture(const std::string& fileName);
    void unloadTexture(const std::string& fileName) const;

    bool checkExistingFont(const std::string& fileName) const;
    void loadFont(const std::string& fileName);
    void unloadFont(const std::string& fileName) const;

    bool checkExistingSound(const std::string& fileName) const;
    void loadSound(const std::string& fileName);
    void unloadSound(const std::string& fileName) const;

    Texture2D getTexture(const std::string& fileName);
    Font getFont(const std::string& fileName);
    Sound getSound(const std::string& fileName);
    static AssetManager& getInstance();
};



#endif //ASSETMANAGER_H
