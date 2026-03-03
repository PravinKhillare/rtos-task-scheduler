#include <iostream>
#include <memory>
#include "Scheduler.hpp"

int main()
{
    // ------------------------------------------------------------
    // Create Scheduler Instance
    // ------------------------------------------------------------
    // The Scheduler is responsible for:
    //  - Managing tasks
    //  - Selecting next task based on priority
    //  - Executing tasks for a given number of cycles
    Scheduler scheduler;

    // ------------------------------------------------------------
    // Create Tasks with Different Priorities
    // ------------------------------------------------------------
    // Task constructor parameters (assumed):
    //  - Task name (for identification/logging)
    //  - Callable (task logic)
    //  - Priority (higher number = higher priority)
    //
    // std::make_shared is used to:
    //  - Enable shared ownership
    //  - Avoid manual memory management
    //  - Improve exception safety

    // High Priority Task (Priority = 3)
    auto task1 = std::make_shared<Task>(
        "HighPriorityTask",
        []()
        {
            std::cout << "  -> Executing High Priority Task\n";
        },
        3
    );

    // Medium Priority Task (Priority = 2)
    auto task2 = std::make_shared<Task>(
        "MediumPriorityTask",
        []()
        {
            std::cout << "  -> Executing Medium Priority Task\n";
        },
        2
    );

    // Low Priority Task (Priority = 1)
    auto task3 = std::make_shared<Task>(
        "LowPriorityTask",
        []()
        {
            std::cout << "  -> Executing Low Priority Task\n";
        },
        1
    );

    // ------------------------------------------------------------
    // Register Tasks with Scheduler
    // ------------------------------------------------------------
    // The scheduler stores tasks internally,
    // typically in a priority queue or ordered structure.
    scheduler.addTask(task1);
    scheduler.addTask(task2);
    scheduler.addTask(task3);

    // ------------------------------------------------------------
    // Start Scheduler Execution
    // ------------------------------------------------------------
    // Parameter: 15
    // Meaning (assumed):
    //  - Run scheduler loop for 15 cycles
    //  - Or execute 15 scheduling decisions
    //
    // Expected Behavior:
    //  - Higher priority tasks execute first
    //  - Lower priority tasks execute when higher ones yield
    //  - Demonstrates priority-based scheduling
    scheduler.start(15);

    // Program exits after scheduler completes execution cycles
    return 0;
}
