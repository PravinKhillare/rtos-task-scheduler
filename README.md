# 🚀 RTOS Task Scheduler in C++

A minimal cooperative RTOS-style scheduler implemented in modern C++.

This project demonstrates core RTOS concepts:

- Task creation
- Task states (Ready, Running, Blocked)
- Priority-based scheduling
- Tick-driven execution
- Deterministic behavior

---

## 📚 Concepts Demonstrated

- Cooperative multitasking
- Priority scheduling
- State machine design
- Tick-based system simulation
- Embedded-style architecture

---

## 🧠 Architecture

Scheduler:
- Maintains task list
- Runs periodic tick
- Selects highest priority ready task
- Executes deterministically

Task:
- Name
- Function callback
- Priority
- State
- Delay mechanism

---

## 🛠 Build Instructions

### Using CMake

```bash
mkdir build
cd build
cmake ..
make
./rtos_scheduler
```

### Using g++

```bash
g++ -std=c++17 src/*.cpp -o rtos_scheduler
./rtos_scheduler
```

---

## 📈 Example Output

```
[Tick 0] Running: HighPriorityTask
  -> Executing High Priority Task
[Tick 1] Running: HighPriorityTask
  -> Executing High Priority Task
...
```

---

## 🎯 Why This Project Matters

This project demonstrates:

- RTOS fundamentals
- Scheduler design
- Embedded architecture thinking
- Clean modular C++ design
- Deterministic execution

Ideal for:
- Embedded developer interviews
- Firmware portfolio
- Systems programming showcase

---

## 🚀 Possible Enhancements

- Preemptive scheduling
- Time slicing
- Mutex implementation
- Semaphore support
- Task deletion
- Priority inheritance
- Multi-core simulation

---

## 📜 License

MIT License
