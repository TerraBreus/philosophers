## External Functions

*usleep()*
---
From `<unistd.h>` library.


`int usleep(useconds_t usec);`

Quite a simple function suspending the calling thread from execution for (at least) `usec` microseconds (one millionth of a second).

**NB: The function may extend (quite easily) over the amount given due to timing errors or other system activity.**

Function can fail in two different ways, for which it will return -1 (on success function returns 0). 
- Interrupted by SIGINT.
- usec is greater than or equal to 1 000 000 (1 whole second) which is not always allowed on some systems.

The type useconds_t is an unsigned integer type capable of holding integers in the range [0,1000000].  Programs will be more portable if they never mention this type explicitly.

*gettimeofday()*
---
`#include <sys/time.h>`

`int gettimeofday(struct timeval *tv, struct timezone *tz);`

Number of seconds since the epoch! (1st of January 1970
The structure is already defined by calling the header. Said structure has the following two elements
- tv_sec: gives the time passed in seconds
- tv_usec: gives time passed in microseconds.

*pthread_create*
---
From `<pthread.h>`

`int  pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*routine) (void *), void *arg);`

This looks more difficult than it is. If you need to understand threads, I refer you to [this](./threads) page

