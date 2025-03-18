//
// Created by daydream on 10.02.25.
//

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <memory>
#include <string>
#include <unordered_map>
#include <filesystem>
#include <optional>

#include "raylib.h"


constexpr const char* TEXTURES_PATH = "/src/Game/assets/textures/";
constexpr const char* FONTS_PATH = "/src/Game/assets/fonts/";
constexpr const char* SOUNDS_PATH = "/src/Game/assets/sounds/";
constexpr const char* MUSIC_PATH = "/src/Game/assets/music/";

namespace FentEngine {
    class AssetManager {
    private:
        std::unordered_map<std::string, Texture2D> m_textures;
        std::unordered_map<std::string, Font> m_fonts;
        std::unordered_map<std::string, Sound> m_sounds;
        std::unordered_map<std::string, Music> m_music;

        std::string m_assetsPath;

    public:
        AssetManager() = default;
        ~AssetManager();

        // Texture Assets
        bool checkExistingTexture(const std::string& fileName) const;
        Texture2D loadTexture(const std::string& fileName);
        void unloadTexture(const std::string& fileName) const;
        bool isTextureMapEmpty() const;

        // Font Assets
        bool checkExistingFont(const std::string& fileName) const;
        Font loadFont(const std::string& fileName);
        void unloadFont(const std::string& fileName) const;

        // Audio Assets
        bool checkExistingSound(const std::string& fileName) const;
        Sound loadSound(const std::string& fileName);
        void unloadSound(const std::string& fileName) const;

        // Music Assets
        bool checkExistingMusic(const std::string& fileName) const;
        Music loadMusic(const std::string& fileName);
        void unloadMusic(const std::string& fileName) const;

        // Getter functions for the assets
        Texture2D getTexture(const std::string& fileName);
        Font getFont(const std::string& fileName);
        Sound getSound(const std::string& fileName);
        Music getMusic(const std::string& fileName);

        const std::unordered_map<std::string, Texture2D>& getTextureHashmap() const;
        const std::unordered_map<std::string, Font>& getFontHashmap() const;
        const std::unordered_map<std::string, Sound>& getSoundHashmap() const;
        const std::unordered_map<std::string, Music>& getMusicHashmap() const;

        // static AssetManager& getInstance();
    };
}



#endif //ASSETMANAGER_H
