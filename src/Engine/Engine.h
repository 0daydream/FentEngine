//
// Created by daydream on 10.02.25.
//

#ifndef ENGINE_H
#define ENGINE_H

#include "../Game/src/Game.h"

class Engine {
private:
    float m_deltaTime;

    Game m_game;

public:
    Engine() = default;
    ~Engine() = default;

    void init();
    void cleanup();
    void run();

};



#endif //ENGINE_H
