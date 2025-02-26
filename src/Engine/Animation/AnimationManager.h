//
// Created by daydream on 16.02.25.
//

#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <raylib.h>
#include <string>
#include <vector>

struct Animation {
    std::string animationName;
    std::vector<Rectangle> animationFrames;
    bool isLooping;
};

struct AnimationState {
    Animation* animation;
    int currentFrame;
    [[maybe_unused]]bool isPlaying;
};

class AnimationManager {
private:


public:
    AnimationManager() = default;
    ~AnimationManager() = default;

};



#endif //ANIMATIONMANAGER_H
