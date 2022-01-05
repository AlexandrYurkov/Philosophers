#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (init(argv, &data))
			philo(&data);
	}
	else
		print_err(ERROR_COUNT);
}
