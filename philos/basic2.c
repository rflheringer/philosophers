/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:00:04 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/12 16:13:05 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_philo(t_philo *philo)
{
	size_t	end_sleep_time;

	if (get_status(&philo->table->mutex_dead, &philo->table->is_dead)
		|| get_status(&philo->table->mutex_full, &philo->table->are_full))
		return ;
	handle_prints(philo, SLEEP);
	end_sleep_time = get_current_time(philo->table) + philo->table->time_to_eat;
	while (get_current_time(philo->table) < end_sleep_time
		&& !get_status(&philo->table->mutex_dead, &philo->table->is_dead)
		&& !get_status(&philo->table->mutex_full, &philo->table->are_full))
		usleep(1000);
}
