Program crashes in debug/sanitize mode due to malloc not setting uninitialized values to NULL. Either do this manually or use calloc.
NB: Calloc is not allowed!!!

---

Check roadmap to see where you are about.
clean and exit function that takes the data dn cleans everything up. Make it accesible for any point in the program (aka check for NULL in order to avoid segvaults)
monitoring

scenario for 1 philo.

checks for thread creatin malloc creation, mutex creation etc.

---

Monitor logic.

Main idea is to check whether the philosopher has died.
A philosopher has died if (current time) - (last time eaten) >= time2die.
If it has, it needs to change a (locked?) variable so that all other philosophers will end their execution.
It also needs to print a message stating the philosopher has died.

Monitor pseudocode:

While (true)
    mutex->lock -> philo->lock;
    if get_time - last_time_eaten >= time2die;
        mutex_lock -> data->should_stop
        should_stop = true;
        mutex_unlock should_stop
        break;
    mutex_unlock philo->lock;
    else
        i++;
        philo = philo->philo_r;

NEXT TIME
Implement thread initialization of the ober and try to run it!

---

It seems a philosopher can die even though it is eating. Have a look at this log:

./philo 5 23 23 23

0 1 has taken a fork.
1 2 has taken a fork.
1 2 is eating.
1 4 has taken a fork.
1 4 is eating.
11 2 has died.              *How come it dies here???*
24 5 has taken a fork.
24 3 has taken a fork.
24 3 is eating.
24 1 is eating.
47 5 is eating.   


AHA! It seems that philo->last_eaten gets reset not from current start_time.

---

15-09-25
- Let uneven philosophers sleep for a couple of seconds to avoid deadlocking. -> DONE
- Usage of atomic variables instead of constant mutex locks -> only forks need to be mutexed really.
- Philosophers keep hanging somewhere. They are not joining/ending properly.

