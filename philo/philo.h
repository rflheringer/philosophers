/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:21:57 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/11 21:12:01 by rafaelherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

# define RST "\033[0m"    /* Reset to default color */
# define RED "\033[1;31m" /* Bold Red */
# define GRE "\033[1;32m" /* Bold Green */
# define YEL "\033[1;33m" /* Bold Yellow */
# define BLU "\033[1;34m" /* Bold Blue */
# define MAG "\033[1;35m" /* Bold Magenta */

typedef struct s_table	t_table;

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

typedef enum e_condition
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIED,
} t_condition;


//ultis_function
size_t  ft_atol(const char *str);

//inits_funcionts
void    init_philo_mutex(t_table *table, t_philo **philos);
void    init_philo(t_table *table, t_philo **philos, int argc, char **argv);
void    create_thread_philos(t_philo *philos, t_table *table);

//time functions
size_t	get_current_time(t_table *table);

//basics_functions
bool    get_status(pthread_mutex_t *mutex, bool *var);
void	meal_alone(void *args);
void	get_fork(t_philo *philo, int first_fork, int second_fork);
void	*start_meal(void *args);

//status_functions
void	set_units(pthread_mutex_t *mutex, size_t *variable, size_t update);
void    handle_prints(t_philo *philo, t_condition condition);

//monitoring_functions
void    *monitor_philos(void *args);
bool    check_philos_are_full(t_philo *philo, t_table *table,
    int *philos_are_full);

void	sleep_philo(t_philo *philo);

void	free_and_close(t_philo *philos, t_table *table);

size_t	get_time_in_ms(void);

//validate_functions
void	validate_args(char **argv);
void validate_args2(int argc, char **argv);
bool	is_number(char **argv);
bool is_positive(char **argv);
bool is_invalid(int argc);

#endif