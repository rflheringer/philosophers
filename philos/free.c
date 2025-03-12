/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:03:48 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/12 11:23:55 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_and_close(t_philo *philos, t_table *table)
{
	free(table->mutex_fork);
	free(philos);
}

void	wait_philos(t_table *table, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < table->nbr_of_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	pthread_join(table->thread, NULL);
	i = 0;
	while (i < table->nbr_of_philos)
	{
		pthread_mutex_destroy(&philos[i].mutex_philo);
		pthread_mutex_destroy(&table->mutex_fork[i]);
		i++;
	}
	pthread_mutex_destroy(&table->mutex_dead);
	pthread_mutex_destroy(&table->mutex_full);
	pthread_mutex_destroy(&table->mutex_print);
}
