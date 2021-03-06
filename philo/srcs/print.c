#include "philo.h"

void	echo(int flag, char *str, uint64_t time, t_philo *ph)
{
	pthread_mutex_lock(&ph->data->output);
	printf("%ldms %d philo %s", time, ph->id + 1, str);
	if (flag)
		pthread_mutex_unlock(&ph->data->output);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	print_err(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}
