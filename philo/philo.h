/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:57 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/06 17:25:05 by rafaelherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

# define RST "\033[0m"    /* Reset to default color */
# define RED "\033[1;31m" /* Bold Red */
# define GRE "\033[1;32m" /* Bold Green */
# define YEL "\033[1;33m" /* Bold Yellow */
# define BLU "\033[1;34m" /* Bold Blue */
# define MAG "\033[1;35m" /* Bold Magenta */

typedef struct s_philo {
    int					id;
	int					fork_left;
	int					fork_rigth;
    size_t 				time_last_meal;
	size_t				meals_eaten;
	pthread_mutex_t		mutex_philo;
	pthread_t			thread;
    t_table				*table;
} t_philo;

typedef struct s_table {
    int					nbr_of_philos;
    size_t				time_to_die;
    size_t				time_to_eat;
    size_t				time_to_sleep;
    size_t				nbr_of_meals;
	size_t				start_time;
    pthread_mutex_t		*mutex_fork;
	pthread_mutex_t		mutex_full;
	pthread_mutex_t		mutex_dead;
	pthread_mutex_t		mutex_print;
	bool				is_dead;
	bool				are_full;
	pthread_t			thread;
} t_table;

//ultis_function
size_t  ft_atol(const char *str);

//inits_funcionts
void    init_philo_mutex(t_table *table, t_philo **philos);

//time functions
size_t	get_current_time(t_table *table);


#endif