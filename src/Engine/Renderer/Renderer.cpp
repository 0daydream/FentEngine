//
// Created by daydream on 10.02.25.
//

#include "Renderer.h"

#include "../Asset/AssetManager.h"
#include <memory>

void FentEngine::Renderer::renderTexture(const std::string& fileName, const VapeTransform& transform, Color tint) {
    // Texture2D texture = AssetManager::getInstance().getTexture(fileName);
}

void FentEngine::Renderer::voidRenderTextureRec(const std::string& fileName, const VapeTransform& transform, Color tint) {
}

void FentEngine::Renderer::renderSprite() {
}

void FentEngine::Renderer::renderText() {
}

void FentEngine::Renderer::renderButton(const VapeButton& button) {
}

void FentEngine::Renderer::renderButtonTexture(const VapeButtonTexture& button) {
}

void FentEngine::Renderer::isButtonHovered(const Rectangle& bounds) {
}

FentEngine::Renderer& FentEngine::Renderer::getInstance() {
    static FentEngine::Renderer instance;
    return instance;
}
