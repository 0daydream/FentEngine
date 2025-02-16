//
// Created by daydream on 15.02.25.
//

#include "TaskQueue.h"


bool FentEngine::TaskQueue::isEmpty() const {
    std::unique_lock<std::mutex> lock(m_mutex);
    return m_queue.empty();
}

void FentEngine::TaskQueue::enqueueTask(const std::function<void()>& task) {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_queue.push(task);
    m_mutex.unlock();

    m_cv.notify_one();
}

void FentEngine::TaskQueue::executeNextTask() {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_cv.wait(lock, [this]() { return !m_queue.empty(); });

    Task task = m_queue.front();
    m_queue.pop();
    m_mutex.unlock();

    task();
}

void FentEngine::TaskQueue::executeAllTasks() {
    while (!isEmpty()) {
        Task task = m_queue.front();
        m_queue.pop();
        executeNextTask();
    };
    m_mutex.unlock();
}
