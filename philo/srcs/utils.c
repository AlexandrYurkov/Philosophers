#include "philo.h"

void	free_threads(pthread_t **treads, t_data *data, int flag)
{
	int	i;

	i = data->must_eat;
	if (flag)
		pthread_mutex_lock(&data->output);
	while (i > 0)
	{
		pthread_detach((*treads)[i - 1]);
		i--;
	}
	free(*treads);
	return ;
}

void	usleep_fixed(uint64_t time)
{
	uint64_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(500);
}

void	eating(t_philo *ph)
{
	pthread_mutex_lock(ph->left);
	echo(1, LEFT_FORK, current_time(get_time(), ph->data->first_time), ph);
	pthread_mutex_lock(ph->right);
	echo(1, RIGHT_FORK, current_time(get_time(), ph->data->first_time), ph);
	ph->last_eat = get_time();
	pthread_mutex_lock(&ph->mute);
	echo(1, EAT, current_time(ph->last_eat, ph->data->first_time), ph);
	pthread_mutex_unlock(&ph->mute);
	usleep_fixed(ph->data->time_to_eat);
	ph->count_eat++;
	pthread_mutex_unlock(ph->right);
	pthread_mutex_unlock(ph->left);
}

void	sleeping(t_philo *ph)
{
	echo(1, SLEEP, current_time(get_time(), ph->data->first_time), ph);
	usleep_fixed(ph->data->time_to_sleep);
}

void	thinking(t_philo *ph)
{
	echo(1, THINK, current_time(get_time(), ph->data->first_time), ph);
}
