#ifndef TASK_HPP
#define TASK_HPP

#include <functional>
#include <string>

// ------------------------------------------------------------
// Task State Enumeration
// ------------------------------------------------------------
// Represents the execution state of a task.
//
// READY  : Task is eligible for execution.
// RUNNING: Task is currently being executed.
// BLOCKED: Task is delayed or waiting for an event.
//
enum class TaskState
{
    READY,
    RUNNING,
    BLOCKED
};

// ------------------------------------------------------------
// Task Class
// ------------------------------------------------------------
// Represents a schedulable unit of work.
//
// Each task contains:
//  - A name (for identification/logging)
//  - A callable function (task logic)
//  - A priority (higher value = higher priority)
//  - Current state
//  - Delay counter (for tick-based blocking)
//
// This models a simplified RTOS-style task control block (TCB).
//
class Task
{
public:
    // --------------------------------------------------------
    // Constructor
    // --------------------------------------------------------
    // name     : Unique identifier for logging/debugging
    // function : Task logic to execute
    // priority  : Scheduling priority (higher = more important)
    //
    Task(std::string name,
         std::function<void()> function,
         int priority);

    // --------------------------------------------------------
    // Execute Task
    // --------------------------------------------------------
    // Runs the task's function if in the READY state.
    // Typically sets the state to RUNNING during execution.
    //
    void run();

    // --------------------------------------------------------
    // Delay Task
    // --------------------------------------------------------
    // Blocks the task for a specified number of scheduler ticks.
    // Moves state to BLOCKED.
    //
    void delay(int ticks);

    // --------------------------------------------------------
    // Update Delay Counter
    // --------------------------------------------------------
    // Called by scheduler each tick.
    // Decrements delay counter.
    // Transitions task from BLOCKED → READY when delay expires.
    //
    void updateDelay();

    // --------------------------------------------------------
    // Query Functions
    // --------------------------------------------------------

    // Returns true if task is READY to execute.
    bool isReady() const;

    // Returns task priority.
    int getPriority() const;

    // Returns task name (used for logging/debugging).
    std::string getName() const;

private:
    // --------------------------------------------------------
    // Task Control Block (TCB)-like Members
    // --------------------------------------------------------

    std::string name_;                 // Task identifier
    std::function<void()> function_;   // Task execution logic
    int priority_;                     // Scheduling priority
    TaskState state_;                  // Current task state
    int delayTicks_;                   // Remaining delay ticks
};

#endif // TASK_HPP
