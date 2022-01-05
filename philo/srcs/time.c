#include "philo.h"

uint64_t	get_time(void) // find_the_time
{
	static struct timeval	time;

	if (gettimeofday(&time, NULL))
		print_err(ERROR);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

uint64_t	current_time(uint64_t now /*now_time*/, uint64_t start) //actual_time
{
	return (now - start);
}
