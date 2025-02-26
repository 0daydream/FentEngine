//
// Created by daydream on 25.02.25.
//

#include "ThreadPool.hpp"

FentEngine::ThreadPool::ThreadPool(size_t threadCount) : m_stop(false) {
  for (size_t i = 0; i < threadCount; ++i) {
    m_worker.emplace_back(&ThreadPool::m_worker, this);
  }
}

FentEngine::ThreadPool::~ThreadPool() {
  m_stop = true;

  for (size_t i = 0; i < m_worker.size(); ++i) {
    m_taskQueue.enqueueTask([]{});
  }

  for (std::thread& worker : m_worker) {
    worker.join();
  }
}

void FentEngine::ThreadPool::enqueueTask(const std::function<void()>& task) {
    m_taskQueue.enqueueTask(task);
}

void FentEngine::ThreadPool::worker() {
    while (true) {
        TaskQueue::Task task;
        if (!m_taskQueue.dequeTasks(task, m_stop)) {
            break;
        }

        task();
    }
}


