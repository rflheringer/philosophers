/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:51:54 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/06 17:57:37 by rafaelherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_fork(t_philo *philo, int first_fork, int second_fork)
{
	size_t	end_meal_time;

	if (get_status(&philo->table->mutex_dead, &philo->table->is_dead) || 
		get_status(&philo->table->mutex_full, &philo->table->are_full))
		return ;
	pthread_mutex_lock(&philo->table->mutex_fork[first_fork]);
	
}

void    eat(t_philo *philo)
{
    if (philo->id % 2 != 0)
        get_fork(philo, philo->fork_rigth, philo->fork_left);
    else
        get_fork(philo, philo->fork_left, philo->fork_rigth);
}

void    think(t_philo *philo)
{
    long	time_to_think;
	size_t	end_think_time;
		
}