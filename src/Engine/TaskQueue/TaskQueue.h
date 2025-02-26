//
// Created by daydream on 15.02.25.
//

#ifndef TASKQUEUE_H
#define TASKQUEUE_H

#include <condition_variable>
#include <functional>
#include <queue>

namespace FentEngine {
    class TaskQueue {
    private:
        std::queue<std::function<void()>> m_queue;
        mutable std::mutex m_mutex;
        std::condition_variable m_cv;

    public:
        using Task = std::function<void()>;

        TaskQueue() = default;
        ~TaskQueue() = default;

        bool isEmpty() const;
        void enqueueTask(const std::function<void()>& task);
        bool dequeTasks(Task& task, std::atomic_bool& stop);
        void executeNextTask();
        void executeAllTasks();
    };
}



#endif //TASKQUEUE_H
