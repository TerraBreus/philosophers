#include "philo.h"	//TODO: add function to header

void	*philo_routine_even(void *philo)
{
	//lifespan of even philosopher
	//
	//Wait for startsignal
	//set time of last_eaten
	//
	//try to grab fork left/right
	//	lock mutex
	//	print message
	//else
	//	sleep 5 ms and try again?
	//
	//then try to grab other fork
	//	lock mutex
	//	print message
	//else
	//	sleep 5ms and try again?
	//
	//change state to EATING
	//	print message
	//	sleep for time2eat
	//
	//unlock both forks
	//change state to SLEEPING
	//	print message
	//	sleep for time2sleep
	//
	//change state to thinking
	//	print message
	//	set time of last_eaten
}

//The following code should be in a while loop like
//
//while (data->no_dead_philo == TRUE)
//	philo_routine_even(philo);
//
//if a philosopher dies, the manager can switch this variable
//(however it might need to mutex it so nothing happens?)
