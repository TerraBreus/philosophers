# Notes from the subject file.
## Overview
- One or more philosophers. -> 1+. ft_atoi, no negative numbers.
- three modes: Eating, thinking or sleeping. They can only be one state at a time.
- As many forks as there are philosophers. they cannot share forks. -> mutex your variables.
- In order to eat, a philosopher must need two forks. It can grab one fork and wait for the second one, it does not need to grab two at the same time. Once it is done eating, it lets go of both forks.
- After eating, a philosopher starts sleeping (a set amount of time). Once it wakes up, it starts thinking/waiting. Once it has two fforks, it will start eating again. presumably we will have to force it to think for at least a little while without eating.
- Simulation should stop once a philosopher dies -> How will we do this? Philosophers cannot communicate with each other and do not know if another philosopher is about to die. -> Do we have to monitor them constantly?
- Every philosopher needs to eat and should never starve (if it can avoid doing so).
## Global rules
- No global variables.
- `n_philosophers time2die time2eat time2sleep [optional argument*]`
    *: Optional argument is for the amount of times a philosopher will eat after which the simulation will stop. Otherwise the program never stops (unless ofcourse a philosopher dies).
    **All time arguments are in miliseconds!
- Philosophers rank from 1 to `n_philosophers` and sit next to each other in order (meaning philosopher 1 sits next to 2 and n_philosopher)
- Logs on any state change of a philosopher must be announced as such:
```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```
**timestamp_in_ms should be the timestamp in ms (...) and X should be the number of the philosopher**

- Displayed messages must not overlap (and should be in order?)
- A message of a philosophers death must be within 10 ms of their actual death.
    Thus if time2die is 200 ms and at timestamp 2400 philosopher has started thinking, their death announcement should be no later than at 2610 ms
- no data races allowed
## Mandatory part
Specific rules

- Each philosopher is represented as a seperate thread -> What? So if we have four threads, we can only have four philosophers changing state at the same time? What this mean boi?
- Only one fork between a pair philosophers -> One philosopher only has one fork (and will die). 
- Mutex a fork's state!

External functions

- memset
- printf
- malloc
- free
- write
- usleep
- gettimeofday
- pthread_create
- pthread_detach
- pthread_join
- pthread_mutex_init
- pthread_mutex_destroy
- pthread_mutex_lock
- pthread_mutex_unlock

# Exercises

**1. Basic Thread Creation**
```
Write a C program that:
   Creates 3 threads.
   Each thread prints a message and its own thread ID.
   The main thread waits for all threads to complete.
```
**2. Shared Variable Trap**
```
Create two threads that both increment a shared int variable 1,000,000 times.
   Do not use synchronization (like mutexes).
   What result do you expect to see?
   What do you actually see?
   Why?

Now, try fixing the race condition using a pthread_mutex_t.
```
**3. Deadlock Detection (Conceptual)**
```
Sketch out a situation where two threads both need two resources (mutexes) but acquire them in opposite orders.
   What could go wrong?
   What conditions must be true for a deadlock to occur?
```
