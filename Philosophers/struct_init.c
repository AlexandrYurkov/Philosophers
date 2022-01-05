#include "philosophers.h"

int	struct_init(char **argv, t_data *data)
{
	data->num_of_phil = is_number(argv[1]);
	data->time_die = is_number(argv[2]);
	data->time_eat = is_number(argv[3]);
	data->time_sleep = is_number(argv[4]);
	if (argv[5])
		data->must_eat = is_number(argv[5]);
	else
		data->must_eat = -1;
	if (data->num_of_phil == 0 || data->must_eat == 0
		|| data->num_of_phil > 200 || data->time_die < 60
		|| data->time_eat < 60 || data->time_sleep < 60)
		print_err(ERROR_DATA);
	return (1);
}