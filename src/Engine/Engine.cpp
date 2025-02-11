//
// Created by daydream on 10.02.25.
//

#include "raylib.h"
#include "Engine.h"

void Engine::init()
{
    InitWindow(1080, 720, "test");
    SetTargetFPS(60);

    m_game.init();
}

void Engine::cleanup() {
    m_game.cleanup();
    CloseWindow();
}

void Engine::run() {
    init();

    while (WindowShouldClose() == false) {
        m_deltaTime = GetFrameTime();
        m_game.update(m_deltaTime);

        BeginDrawing();
        ClearBackground(BLACK);

        m_game.render();

        EndDrawing();
    }

    cleanup();
}