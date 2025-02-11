//
// Created by daydream on 10.02.25.
//

#ifndef RENDERER_H
#define RENDERER_H

#include "../Structs.h"
#include "raylib.h"
#include <memory>
#include <string>


namespace FentEngine {
    class Renderer {
    private:

    public:
        Renderer() = default;
        ~Renderer() = default;

        void renderTexture(const std::string& fileName, const VapeTransform& transform, Color tint = WHITE);
        void voidRenderTextureRec(const std::string& fileName, const VapeTransform& transform, Color tint = WHITE);
        void renderSprite();
        void renderText();

        void renderButton(const VapeButton& button);
        void renderButtonTexture(const VapeButtonTexture& button);
        void isButtonHovered(const Rectangle& bounds);

        static Renderer& getInstance();

    };
}


#endif //RENDERER_H
