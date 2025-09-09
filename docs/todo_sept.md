0509

Program crashes in debug/sanitize mode due to malloc not setting uninitialized values to NULL. Either do this manually or use calloc.

After that, it seems there is a segvault in the routine for philosophers with mutex_locking.

Check roadmap to see where you are about.
clean and exit function that takes the data dn cleans everything up. Make it accesible for any point in the program (aka check for NULL in order to avoid segvaults)
monitoring

scenario for 1 philo.

checks for thread creatin malloc creation, mutex creation etc.
