#include "philo.h"	//TODO: add function to header

//thread initialization
//
//get time of start of simulation
//start monitor thread to check when max meals eaten has reached (if needed)
//(or let the waiter/supervisor do that)
//
//Create each inidividual thread 

static void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_l);
	print_log(get_time(), philo, FORK);
	pthread_mutex_lock(philo->fork_r);

	pthread_mutex_lock(philo->lock);
	philo->last_eaten = get_time() - philo->data->start_time;
	pthread_mutex_unlock(philo->lock);

	print_log(get_time(), philo, EAT);
	ft_msleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}

static void	ft_sleep(t_philo *philo)
{
	print_log(get_time(), philo, SLEEP);
	ft_msleep(philo->data->time_to_sleep);
}

static void	ft_think(t_philo *philo)
{
	print_log(get_time(), philo, THINK);
}

void	*philo_routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	//Wait for startsignal
	philo->last_eaten = philo->data->start_time;
	while (true)	//TODO
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
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
