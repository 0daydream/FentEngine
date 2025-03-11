//
// Created by daydream on 11.03.25.
//

#ifndef AUDIO_HPP
#define AUDIO_HPP
#include "../Asset/AssetManager.h"


namespace FentEngine {
    class Sound {
    private:
    public:
        explicit Sound(const AssetManager& assetManager);
        ~Sound() = default;

        void loadAudio(const std::string& fileName);
        void playAudio(const std::string& fileName, float volume = 1.0f);
        void stopAudio(const std::string& fileName);
        void pauseAudio(const std::string& fileName);
        void resumeAudio(const std::string& fileName);
        void loopAudio(const std::string& fileName, float volume = 1.0f);
    };
}



#endif //AUDIO_HPP
