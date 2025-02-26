//
// Created by daydream on 25.02.25.
//

#ifndef THREADPOOL_HPP
#define THREADPOOL_HPP

#include "../TaskQueue/TaskQueue.h"

#include <functional>
#include <thread>

namespace FentEngine {
    class ThreadPool {
    private:
        void worker();

        std::vector<std::thread> m_worker;
        std::atomic_bool m_stop;

        FentEngine::TaskQueue m_taskQueue;

    public:
        explicit ThreadPool(
            size_t threadCount = std::thread::hardware_concurrency()
        );
        ~ThreadPool();

        ThreadPool(const ThreadPool&) = delete;
        ThreadPool& operator=(const ThreadPool&) = delete;

        void enqueueTask(const std::function<void()>& task);
    };
}



#endif //THREADPOOL_HPP
