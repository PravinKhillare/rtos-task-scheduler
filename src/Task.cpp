#include "Task.hpp"

/*
 * Constructor
 * Initialises a task with:
 *  - name      : Identifier of the task
 *  - function  : Task body (callable)
 *  - priority  : Scheduling priority
 *
 * Default state is READY.
 * delayTicks_ is initialised to 0 (no delay).
 */
Task::Task(std::string name,
           std::function<void()> function,
           int priority)
    : name_(std::move(name)),          // Move to avoid unnecessary copy
      function_(std::move(function)),  // Store callable task body
      priority_(priority),            // Task priority
      state_(TaskState::READY),       // Initial state
      delayTicks_(0)                  // No delay initially
{
}

/*
 * Executes the task if it is in the READY state.
 *
 * State transition:
 * READY   -> RUNNING
 * RUNNING -> READY (after execution completes)
 *
 * Note:
 * This assumes cooperative scheduling.
 * No preemption handling is implemented here.
 */
void Task::run()
{
    if (state_ == TaskState::READY)
    {
        state_ = TaskState::RUNNING;

        function_();   // Execute task function

        state_ = TaskState::READY;
    }
}

/*
 * Delays the task for a specified number of ticks.
 *
 * Parameters:
 *  ticks: Number of scheduler ticks to block the task
 *
 * State transition:
 * READY/RUNNING -> BLOCKED
 */
void Task::delay(int ticks)
{
    if (ticks > 0)
    {
        delayTicks_ = ticks;
        state_ = TaskState::BLOCKED;
    }
}

/*
 * Updates the delay counter.
 * Should be called periodically by the scheduler tick handler.
 *
 * If the delay expires:
 * BLOCKED -> READY
 */
void Task::updateDelay()
{
    if (state_ == TaskState::BLOCKED && delayTicks_ > 0)
    {
        --delayTicks_;

        if (delayTicks_ == 0)
        {
            state_ = TaskState::READY;
        }
    }
}

/*
 * Returns true if the task is ready to execute.
 */
bool Task::isReady() const
{
    return state_ == TaskState::READY;
}

/*
 * Returns task priority.
 * Used by scheduler for priority-based scheduling.
 */
int Task::getPriority() const
{
    return priority_;
}

/*
 * Returns task name.
 * Useful for debugging, logging, or diagnostics.
 */
std::string Task::getName() const
{
    return name_;
}
