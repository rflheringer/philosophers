/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:51:54 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/12 17:53:38 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*meal_alone(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	pthread_mutex_lock(&philo->table->mutex_fork[philo->fork_rigth]);
	handle_prints(philo, FORK);
	usleep(philo->table->time_to_die * 1000);
	pthread_mutex_unlock(&philo->table->mutex_fork[philo->fork_rigth]);
	handle_prints(philo, DIED);
	return (NULL);
}

void	get_fork(t_philo *philo, int first_fork, int second_fork)
{
	size_t	end_meal_time;

	if (get_status(&philo->table->mutex_dead,
			&philo->table->is_dead) || get_status(&philo->table->mutex_full,
			&philo->table->are_full))
		return ;
	pthread_mutex_lock(&philo->table->mutex_fork[first_fork]);
	handle_prints(philo, FORK);
	pthread_mutex_lock(&philo->table->mutex_fork[second_fork]);
	handle_prints(philo, FORK);
	handle_prints(philo, EAT);
	set_units(&philo->mutex_philo, &philo->time_last_meal,
		get_current_time(philo->table));
	end_meal_time = get_current_time(philo->table) + philo->table->time_to_eat;
	while (get_current_time(philo->table) < end_meal_time
		&& !get_status(&philo->table->mutex_dead, &philo->table->is_dead)
		&& !get_status(&philo->table->mutex_full, &philo->table->are_full))
		usleep(1000);
	set_units(&philo->mutex_philo, &philo->meals_eaten, philo->meals_eaten + 1);
	pthread_mutex_unlock(&philo->table->mutex_fork[first_fork]);
	pthread_mutex_unlock(&philo->table->mutex_fork[second_fork]);
}

void	eat(t_philo *philo)
{
	if (philo->id % 2 != 0)
		get_fork(philo, philo->fork_rigth, philo->fork_left);
	else
		get_fork(philo, philo->fork_left, philo->fork_rigth);
}

void	think(t_philo *philo)
{
	long	time_to_think;
	size_t	end_think_time;

	if (get_status(&philo->table->mutex_dead, &philo->table->is_dead)
		|| get_status(&philo->table->mutex_dead, &philo->table->are_full))
		return ;
	time_to_think = (long)(philo->table->time_to_die
			- (long)(get_current_time(philo->table)
				- (long)philo->time_last_meal)
			- (long)philo->table->time_to_eat) / 2;
	handle_prints(philo, THINK);
	if (time_to_think < 0)
		return ;
	if (time_to_think > 500)
		time_to_think = 500;
	end_think_time = get_current_time(philo->table) + time_to_think;
	while (get_current_time(philo->table) < end_think_time
		&& !get_status(&philo->table->mutex_dead, &philo->table->is_dead)
		&& !get_status(&philo->table->mutex_full, &philo->table->are_full))
		usleep(1000);
}

void	*start_meal(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (!get_status(&philo->table->mutex_dead,
			&philo->table->is_dead) && !get_status(&philo->table->mutex_full,
			&philo->table->are_full))
	{
		eat(philo);
		sleep_philo(philo);
		think(philo);
	}
	return (NULL);
}
