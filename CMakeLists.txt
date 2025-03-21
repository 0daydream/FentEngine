cmake_minimum_required(VERSION 3.30)
project(FentEngine)

set(CMAKE_CXX_STANDARD 20)

add_executable(FentEngine src/main.cpp
        src/Engine/Engine.cpp
        src/Engine/Engine.h
        src/Game/src/Game.cpp
        src/Game/src/Game.h
        src/Game/src/Scenes/LoadingScene.cpp
        src/Game/src/Scenes/LoadingScene.h
        src/Engine/Scene/SceneManager.cpp
        src/Engine/Scene/SceneManager.h
        src/Engine/Structs.h
        src/Engine/Scene/Scene.h
        src/Engine/Renderer/Renderer.cpp
        src/Engine/Renderer/Renderer.h
        src/Engine/Entity/Entity.cpp
        src/Engine/Entity/Entity.h
        src/Engine/Asset/AssetManager.cpp
        src/Engine/Asset/AssetManager.h
        src/Engine/Audio/AudioManager.cpp
        src/Engine/Audio/AudioManager.hpp
        src/Engine/TaskQueue/TaskQueue.cpp
        src/Engine/TaskQueue/TaskQueue.h
        src/Engine/ThreadPool/ThreadPool.cpp
        src/Engine/ThreadPool/ThreadPool.hpp
        src/Engine/Settings/Settings.cpp
        src/Engine/Settings/Settings.hpp
)

# IMPORTANT: Use vcpkg to use these libraries :3
find_package(glfw3 CONFIG REQUIRED)
find_package(raylib CONFIG REQUIRED)
target_link_libraries(FentEngine PRIVATE raylib glfw)

set_target_properties(FentEngine PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)