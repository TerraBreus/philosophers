0509

Program crashes in debug/sanitize mode due to malloc not setting uninitialized values to NULL. Either do this manually or use calloc.

After that, it seems there is a segvault in the routine for philosophers with mutex_locking.

Also you're not switching to the next philosopher in thread_init
