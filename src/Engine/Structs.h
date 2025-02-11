//
// Created by daydream on 10.02.25.
//

#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include "raylib.h"

typedef struct VapeTransform {
    Vector2 position {};
    float rotation = 0.0f;
    float scale = 1.0f;
} VpaeTransform;

typedef struct VapeEntity {
    std::string textureName;
    std::string entityName;
    Texture2D textureFile {};
    VapeTransform transform;
    Rectangle hitbox {};
    Color tint = WHITE;
} VapeEntity;

typedef struct VapeFont {
    std::string text;
    Vector2 position;
    float rotation = 0.0f;
    float scale = 1.0f;
    Color color = WHITE;
} VapeFont;

// Experimental Stuff
typedef struct VapeSound {
    std::string fileName;
    Sound sound;
} VapeSound;

typedef struct VapeButton {
    Rectangle buttonRectangle{};
    VapeFont font;
    Color color = WHITE;
} VapeButton;

typedef struct VapeButtonTexture {
    Texture2D buttonRectangle{};
    VapeFont font;
    Color color = WHITE;
} VapeButtonTexture;

#endif //STRUCTS_H
