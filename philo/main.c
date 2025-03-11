/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:09:12 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/11 16:24:52 by rafaelherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool is_invalid(int argc)
{
	if (argc < 5 || argc > 6)
		return (false);
	return (true);
}

bool is_positive(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while(i++, argv[i])
	{
		j = -1;
		while(j++, argv[i][j])
			if (argv[i][j] == '-')
				return (false);
	}
	return (true);
}

bool	is_number(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while(i++, argv[i])
	{
		j = -1;
		while(j++, argv[i][j])
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (false);
	}
	return (true);
}

void	validate_args(char **argv)
{
	if (!is_positive(argv))
		printf("The ARGS must be positives\n");
	else if (!is_number(argv))
		printf("The ARGS must be positive numbers\n");
}

void validate_args2(int argc, char **argv)
{
	if (!is_positive(argv))
		printf("The ARGS must be positives\n");
	else if (!is_number(argv))
		printf("The ARGS must be positive numbers\n");
	else if (!is_invalid(argc))
		printf("It needs to have 4 or 5 arguments.\n");
}

int	main (int argc, char **argv)
{
	t_philo	*philos;
	t_table	table;
	
	validate_args2(argc, argv);
	init_philo(&table, &philos, argc, argv);
	if (table.nbr_of_philos == 1)
	{
		pthread_create(&philos[0].thread, NULL, meal_alone, &philos[0]);
		pthread_join(&philos[0].thread, NULL);
	}
	else 
	{
		create_thread_philos(&table, philos);
		wait_philos(&table, philos);
	}
	free_and_close(philos, &table);
}