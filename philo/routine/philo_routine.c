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
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}

static void	ft_sleep(t_philo *philo)
{
	print_log(get_time(), philo, SLEEP);
	ft_usleep(philo->data->time_to_sleep);
}

static void	ft_think(t_philo *philo)
{
	print_log(get_time(), philo, THINK);
}

/*
void	*philo_routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	philo->last_eaten = philo->data->start_time;
	while (true)
	{
		pthread_mutex_lock(philo->data->lock);
		if (philo->data->should_stop == true)
		{
			pthread_mutex_unlock(philo->data->lock);
			break;
		}
		pthread_mutex_unlock(philo->data->lock);	//TODO: there must be a better way for this
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
*/

bool	should_stop(bool stop_sign, pthread_mutex_t *lock)
{
	bool	result;

	result = false;
	pthread_mutex_lock(lock);
	if (stop_sign == true)
		result = true;
	pthread_mutex_unlock(lock);
	return (result);
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)ptr;
	philo->last_eaten = philo->data->start_time;
	data = philo->data;

	while (true)
	{
		if (should_stop(data->should_stop, data->lock) == true)
			break;
		ft_eat(philo);
		if (should_stop(data->should_stop, data->lock) == true)
			break;
		ft_sleep(philo);
		if (should_stop(data->should_stop, data->lock) == true)
			break;
		ft_think(philo);
	}
	return (NULL);
}
