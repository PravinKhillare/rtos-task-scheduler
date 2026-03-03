#include "Scheduler.hpp"
#include <algorithm>
#include <iostream>
#include <thread>
#include <chrono>

// ------------------------------------------------------------
// Add Task to Scheduler
// ------------------------------------------------------------
// Stores the task inside the internal task container.
// Ownership is shared using std::shared_ptr to allow
// safe lifecycle management across the system.
void Scheduler::addTask(std::shared_ptr<Task> task)
{
    tasks_.push_back(task);
}

// ------------------------------------------------------------
// Start Scheduler
// ------------------------------------------------------------
// maxTicks:
//   Defines how many scheduling cycles the scheduler will run.
//
//Behaviour:
//   1. Update task states (tick)
//   2. Select the highest-priority ready task
//   3. Execute selected task
//   4. Wait for next cycle (simulated timer delay)
//
// This simulates a cooperative priority-based scheduler.
void Scheduler::start(int maxTicks)
{
    for (int i = 0; i < maxTicks; ++i)
    {
        // Update internal task timing/delay counters
        tick();

        // Select the highest-priority task that is ready to run
        auto task = selectHighestPriorityTask();

        if (task)
        {
            std::cout << "[Tick " << i << "] Running: "
                      << task->getName() << "\n";

            // Execute task (cooperative execution)
            task->run();
        }

        // Simulate system timer period (200 ms per tick)
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

// ------------------------------------------------------------
// Tick Function
// ------------------------------------------------------------
// Called once per scheduler cycle.
//
// Purpose:
//   - Update delay counters for all tasks
//   - Determine if tasks transition to the READY state
//
// Similar to RTOS system tick interrupt.
void Scheduler::tick()
{
    for (auto& task : tasks_)
    {
        task->updateDelay();
    }
}

// ------------------------------------------------------------
// Select Highest Priority Ready Task
// ------------------------------------------------------------
// Iterates over all tasks and selects:
//
//   - Only tasks that are READY
//   - Among them, the one with the highest priority
//
// Priority Rule:
//   Higher numeric value = Higher priority
//
// Returns:
//   - nullptr if no task is ready
//   - Shared pointer to selected task, otherwise
//
// This implements a simple priority-based scheduling algorithm.
// No preemption is performed (cooperative model).
std::shared_ptr<Task> Scheduler::selectHighestPriorityTask()
{
    std::shared_ptr<Task> selected = nullptr;

    for (auto& task : tasks_)
    {
        // Check if task is ready to execute
        if (task->isReady())
        {
            // Select task if:
            // 1. No task selected yet
            // 2. The current task has a higher priority
            if (!selected ||
                task->getPriority() > selected->getPriority())
            {
                selected = task;
            }
        }
    }

    return selected;
}
