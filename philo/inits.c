/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:02:36 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/11 19:11:52 by rafaelherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    init_philo_mutex(t_table *table, t_philo **philos)
{
    int i;

    i = 0;
    while (i < table->nbr_of_philos)
    {
        (*philos)[i].id = i + 1;
        (*philos)[i].fork_left = i;
        (*philos)[i].fork_rigth = (*philos)[i].id % table->nbr_of_philos;
        (*philos)[i].table = table;
        (*philos)[i].time_last_meal = 0;
        (*philos)[i].meals_eaten = 0;
        pthread_mutex_init(&(*philos)[i].mutex_philo, NULL);
		pthread_mutex_init(&table->mutex_fork[i], NULL);
        i++;
    }
}

void    init_philo(t_table *table, t_philo **philos, int argc, char **argv)
{
    //need change all argvs for int
    table->nbr_of_philos = (int)ft_atol(argv[1]);
    table->time_to_die = ft_atol(argv[2]);
    table->time_to_eat = ft_atol(argv[3]);
    table->time_to_sleep = ft_atol(argv[4]);
    if (argc == 6)
        table->nbr_of_meals = ft_atol(argv[5]);
    table->mutex_fork = malloc(table->nbr_of_philos * sizeof(pthread_mutex_t));
    *philos = malloc(table->nbr_of_philos * sizeof(t_philo));
    init_philo_mutex(table, philos);
    pthread_mutex_init(&table->mutex_dead, NULL);
	pthread_mutex_init(&table->mutex_full, NULL);
	pthread_mutex_init(&table->mutex_print, NULL);
    table->is_dead = false;
    table->are_full = false;
    table->start_time = get_time();
}

void    create_thread_philos(t_philo *philos, t_table *table)
{
    int i;

    i = -1;
    while(i++, i < table->nbr_of_philos)
        pthread_create(&philos[i].thread, NULL, start_meal, &philos[i]);
    pthread_create(&table->thread, NULL, monitor_philos, (void *)philos);
}