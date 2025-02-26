//
// Created by daydream on 15.02.25.
//

#include "TaskQueue.h"


bool FentEngine::TaskQueue::isEmpty() const {
    std::unique_lock<std::mutex> lock(m_mutex);
    return m_queue.empty();
}

void FentEngine::TaskQueue::enqueueTask(const Task& task) {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_queue.push(task);
    m_mutex.unlock();

    m_cv.notify_one();
}

bool FentEngine::TaskQueue::dequeTasks(Task &task, std::atomic_bool& stop) {
    std::unique_lock<std::mutex> lock(m_mutex);

    m_cv.wait(lock, [this, &stop] { return m_queue.empty() || stop; });

    if (stop && m_queue.empty()) {
        return false;
    }
    task = m_queue.front();
    m_queue.pop();
    return true;
}

void FentEngine::TaskQueue::executeNextTask() {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_cv.wait(lock, [this]() { return !m_queue.empty(); });

    Task task = m_queue.front();
    m_queue.pop();
    // m_mutex.unlock();

    task();
}

void FentEngine::TaskQueue::executeAllTasks() {
    std::unique_lock<std::mutex> lock(m_mutex);

    while (!isEmpty()) {
        Task task = m_queue.front();
        m_queue.pop();
        task();
    };
    // m_mutex.unlock();
}
