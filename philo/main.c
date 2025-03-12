/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:09:12 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/11 21:13:41 by rafaelherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		//wait_philos(&table, philos);
	}
	free_and_close(philos, &table);
}
