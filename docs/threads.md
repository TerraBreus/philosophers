## Explaining threads
Imagine a student flat...

At the moment, it only houses one student — Zack. Zack is the main thread: he has tasks to do, he can use the kitchen (memory), write on the whiteboard (global variables), etc.

If you’re familiar with fork(), you know it’s like cloning Zack — and the entire apartment. Now you have Zack#1 in flat #1 and Zack#2 in flat #2. They look the same, but they live in completely separate spaces. If Zack#1 leaves a note on his fridge, Zack#2 won’t see it — because his fridge is a copy. No shared memory. No shared whiteboard. If the two want to communicate, they have to call or text each other — IPC, like in minitalk.

Threading is a little different. Instead of cloning the apartment, threading adds another student to the same flat. Say hello to Anna. Anna is a thread — just like Zack — with her own to-do list, her own schedule, and her own personal call stack. But she and Zack live in the same place. That means:
- One shared kitchen (heap)
- One shared whiteboard (global variables)
- One set of shared appliances (file descriptors)

If Zack puts a carton of milk in the fridge, Anna can drink from it. If she spills something on the floor (data corruption), Zack might slip on it (unexpected behavior). That’s the tradeoff: easy cooperation comes with the risk of stepping on each other's toes.

So threading makes multitasking inside a program cheaper and more efficient — but also more dangerous. Everyone shares everything. No walls. No isolation.

## Why use threads?

Try to think of your own example! If you can't I am sure chatGPT can help you :)

Otherwise this should probably say enough:
```c
download_webpage(some_file, update_struct);
update_status_bar(update_struct);
```

If it doesn't... well, the problem here is that code gets executed in order. So we first download the whole file and then update the status bar. How could we update the status bar while downloading the file at the same time???
