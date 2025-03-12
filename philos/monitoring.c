/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:08:08 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/12 17:49:52 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_last_meal_time(t_philo *philos, int i)
{
	if (get_current_time(philos[i].table) > get_units(&philos[i].mutex_philo,
			&philos[i].time_last_meal) + philos[i].table->time_to_die)
	{
		handle_prints(&philos[i], DIED);
		set_status(&philos[i].table->mutex_dead, &philos[i].table->is_dead,
			true);
		return (true);
	}
	return (false);
}

bool	check_philos_are_full(t_philo *philo, t_table *table,
	int *philos_are_full)
{
	if (get_units(&philo->mutex_philo,
			&philo->meals_eaten) >= table->nbr_of_meals)
		*philos_are_full = *philos_are_full + 1;
	if (*philos_are_full == table->nbr_of_philos)
	{
		set_status(&philo->table->mutex_full, &philo->table->are_full, true);
		return (true);
	}
	return (false);
}

void	*monitor_philos(void *args)
{
	int		i;
	int		philos_are_full;
	t_table	*table;
	t_philo	*philos;

	philos = (t_philo *)args;
	table = philos[0].table;
	while (true)
	{
		i = 0;
		philos_are_full = 0;
		while (i < table->nbr_of_philos)
		{
			if (table->nbr_of_meals)
			{
				if (check_philos_are_full(&philos[i], table, &philos_are_full))
					return (NULL);
			}
			if (check_last_meal_time(philos, i))
				return (NULL);
			i++;
		}
	}
}
