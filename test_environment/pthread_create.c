#include <pthread.h>
#include <stdio.h>

typedef struct s_tid {
	pthread_t	tid;
}	t_tid;

void	*routine(void *some_struct)
{
	t_tid	*result;
	result = (t_tid *)some_struct;
	printf("%ld\n", result->tid);
	return (some_struct);
}

int	main()
{
	t_tid	tid1;
	t_tid	tid2;

	pthread_create(&(tid1.tid), NULL, &routine, &tid1);
	pthread_create(&(tid2.tid), NULL, &routine, &tid2);
	pthread_join(tid1.tid, NULL);
	pthread_join(tid2.tid, NULL);
	printf("exiting\n");
	return (0);
}
