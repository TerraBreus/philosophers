CHATGPT WARNING!!! This was used as a guiding tool. Please refrain from expectations based on this roadmap.
---

## 🔧 Assumptions & Constraints

* Total time: \~70 hours.
* Timeframe: 14 days.
* Daily availability: You didn’t specify, so I’ll assume **5–6 hours/day average**, with some days heavier.
* Buffer: Add \~15% extra time (\~10 hours) for bugs, confusion, burnout, etc.

So, the **working target is \~80 hours over 14 days.**

---

## 🗺️ Two-Week Roadmap Overview

| **Week** | **Goal**                                                              | **Milestones**                                                                                                        |
| -------- | --------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------- |
| Week 1   | Research, Design, Setup, Core Coding                                  | Understand the problem, constraints, and rules. Design threading and timing logic. Get a working base implementation. |
| Week 2   | Full implementation, debugging, stress testing, evaluation, polishing | Make it robust, handle edge cases, refine timing, avoid race conditions, and get peer/mentor review.                  |

---

## 📅 Realistic Day-by-Day Breakdown

Each day will have: **objective**, **task(s)**, and **time estimate**.

---

### 🔹 **Day 1 – Understand the Problem (5h)**

* **Objective:** Deep comprehension of project scope and constraints.
* Tasks:

  * Read the subject PDF 2–3x slowly.
  * Write down key constraints (e.g., max wait time, precise timing rules).
  * Note edge-case scenarios the evaluator might test.
  * Read at least one successful repo’s README and ignore the code.
* **Time:** 5h

---

### 🔹 **Day 2 – Research & Tooling Setup (6h)**

* **Objective:** Set up development environment, learn what tools and functions you’ll need.
* Tasks:

  * Create Makefile + main file.
  * Read pthreads documentation (mutexes, pthread\_create, join, detach, etc.)
  * Learn about `gettimeofday`, `usleep`, and how to make timing precise.
  * Set up timer utility and logging framework.
* **Time:** 6h

---

### 🔹 **Day 3 – Architecture Design (5h)**

* **Objective:** Design system architecture (avoid spaghetti logic).
* Tasks:

  * Diagram process/thread lifecycle.
  * Decide if you’ll use a thread per philosopher or something more sophisticated.
  * Sketch how synchronization will work: forks as mutexes? How many?
  * Start pseudocode skeleton for main loop.
* **Time:** 5h

---

### 🔹 **Day 4 – Implement Threading Skeleton (6h)**

* **Objective:** Get threads running and identifiable.
* Tasks:

  * Create philosopher structs.
  * Spawn threads with proper IDs.
  * Log timestamps and IDs to stdout.
  * Begin implementing monitor/observer logic if needed.
* **Time:** 6h

---

### 🔹 **Day 5 – Add Mutex Logic (5h)**

* **Objective:** Add correct fork-grabbing logic.
* Tasks:

  * Implement fork mutexes.
  * Use locking order to prevent deadlock.
  * Make philosophers "think", "eat", "sleep" in correct sequence.
* **Time:** 5h

---

### 🔹 **Day 6 – Implement Death Detection (6h)**

* **Objective:** Handle philosopher death (core mechanic).
* Tasks:

  * Track last meal time.
  * Add global monitor or per-thread checks.
  * Clean up thread properly on death.
  * Print correct logs.
* **Time:** 6h

---

### 🔹 **Day 7 – Buffer Day + Basic Testing (4h)**

* **Objective:** Leave time for debugging, refactor, or catch-up.
* Tasks:

  * Run with 1–5 philosophers.
  * Add basic error checks (invalid args, etc.)
  * Revisit Makefile and code structure.
* **Time:** 4h

---

### 🔹 **Day 8 – Edge Case Handling (6h)**

* **Objective:** Pass edge cases like:

  * One philosopher (can’t eat),
  * Philosophers with time\_to\_die == 0,
  * Precise timing issues.
* Tasks:

  * Write unit tests or print checks.
  * Improve mutex logic to avoid timing drift.
* **Time:** 6h

---

### 🔹 **Day 9 – Stress Testing (6h)**

* **Objective:** Simulate heavy loads or weird conditions.
* Tasks:

  * Run with high number of philosophers (50–200).
  * Add timers to detect timing drift.
  * Log resource usage.
* **Time:** 6h

---

### 🔹 **Day 10 – Memory and Leak Testing (5h)**

* **Objective:** Make sure you're clean.
* Tasks:

  * Use Valgrind (or leaks for mac).
  * Free all mallocs.
  * Handle edge exits gracefully.
* **Time:** 5h

---

### 🔹 **Day 11 – Code Review + Commenting (4h)**

* **Objective:** Clean, comment, and prep for review.
* Tasks:

  * Go function by function.
  * Ensure you follow Norm.
  * Add README and code usage instructions.
* **Time:** 4h

---

### 🔹 **Day 12 – Peer Review / External Feedback (4h)**

* **Objective:** Get another set of eyes.
* Tasks:

  * Ask a peer for a quick review or dry-run evaluation.
  * Validate that Makefile, compilation, and usage are rock-solid.
* **Time:** 4h

---

### 🔹 **Day 13 – Final Polish + Extra Tests (4h)**

* **Objective:** Lock down presentation.
* Tasks:

  * Run through evaluation checklist.
  * Check logging clarity.
  * Verify thread termination on all paths.
* **Time:** 4h

---

### 🔹 **Day 14 – Rest or Bug Hunt (5h)**

* **Objective:** Time for final bug fixes or recovery.
* Tasks:

  * Do nothing if confident. Otherwise...
  * Stress test again.
  * Rewrite confusing parts.
* **Time:** 5h

---

## ✅ Deliverables by End

* Robust `philo` binary with zero memory leaks, stable threading, clean logs, good performance.
* README with:

  * Description of implementation.
  * Compile instructions.
  * Known limitations.
* Evaluation readiness.

---

## ⏱️ Total Time Breakdown

| Category          | Time    |
| ----------------- | ------- |
| Research          | 10h     |
| Design            | 5h      |
| Coding Core       | 25h     |
| Debugging/Testing | 20h     |
| Polish/Evaluation | 10h     |
| Buffer Time       | 10h     |
| **Total**         | **80h** |

---

Let me know if you want a printable or trackable format (e.g., Notion, CSV, Obsidian task list), or if you want to adapt the schedule to different working hours.
