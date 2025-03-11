/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:03:32 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/11 18:04:33 by rafaelherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    handle_prints(t_philo *philo, t_condition condition)
{
    if(get_status(&philo->table->mutex_full, &philo->table->are_full) ||
        get_status(&philo->table->mutex_dead, &philo->table->is_dead))
        return ;
    pthread_mutex_lock(&philo->table->mutex_print);
    if (condition == FORK)
        printf("%zu %d has taken a fork\n" ,get_current_time(philo->table), 
            philo->id);
    else if (condition == EAT)
        printf("%zu %d is eating\n",get_current_time(philo->table), philo->id);
    else if (condition == SLEEP)
        printf("%zu %d is sleeping\n",get_current_time(philo->table),
            philo->id);
    else if (condition == THINK)
        printf("%zu %d is thinking\n",get_current_time(philo->table),
            philo->id);
    else if (condition == DIED)
        printf("%zu %d died",get_current_time(philo->table), philo->id);
    pthread_mutex_unlock(&philo->table->mutex_print);    
}

bool    get_status(pthread_mutex_t *mutex, bool *var)
{
    bool    status;

    pthread_mutex_lock(*var);
    status = *var;
    pthread_mutex_unlock(*var);
    return (status);
}

void	set_units(pthread_mutex_t *mutex, size_t *variable, size_t update)
{
	pthread_mutex_lock(mutex);
	*variable = update;
	pthread_mutex_unlock(mutex);
}