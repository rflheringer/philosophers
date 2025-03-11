/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:28:21 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/06 17:07:25 by rafaelherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

size_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

size_t	get_current_time(t_table *table)
{
	size_t	current_time;

	current_time = get_time_in_ms() - table->start_time;
	return (current_time);
}
