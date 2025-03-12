/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:37:23 by rheringe          #+#    #+#             */
/*   Updated: 2025/03/12 17:54:09 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

typedef struct s_table	t_table;

typedef struct s_philo {
	int					id;
	int					fork_left;
	int					fork_rigth;
	size_t				time_last_meal;
	size_t				meals_eaten;
	pthread_mutex_t		mutex_philo;
	pthread_t			thread;
	t_table				*table;
}	t_philo;

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
}	t_table;

typedef enum e_condition
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIED,
}	t_condition;

//ultis_function
size_t	ft_atol(const char *str);
void	error_exit(char *error);
int		ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(const char *s);

//inits_funcionts
void	init_philo_mutex(t_table *table, t_philo **philos);
void	init_philo(t_table *table, t_philo **philos, int argc, char **argv);
void	create_thread_philos(t_table *table, t_philo *philos);

//time functions
size_t	get_current_time(t_table *table);

//basics_functions
bool	get_status(pthread_mutex_t *mutex, bool *var);
void	*meal_alone(void *args);
void	get_fork(t_philo *philo, int first_fork, int second_fork);
void	*start_meal(void *args);

//status_functions
void	set_units(pthread_mutex_t *mutex, size_t *variable, size_t update);
void	handle_prints(t_philo *philo, t_condition condition);
void	set_status(pthread_mutex_t *mutex, bool *var, bool update);
size_t	get_units(pthread_mutex_t *mutex, size_t *var);

//monitoring_functions
void	*monitor_philos(void *args);
bool	check_philos_are_full(t_philo *philo,
			t_table *table, int *philos_are_full);
void	sleep_philo(t_philo *philo);
void	free_and_close(t_philo *philos, t_table *table);
void	wait_philos(t_table *table, t_philo *philos);
size_t	get_time_in_ms(void);

//validate_functions
void	check_sign(char *argv[], int i, int *j, bool *sign);
void	check_zero(int argc, char *argv[]);
void	check_size(char *str);
void	validate_arguments(int argc, char *argv[]);	

#endif