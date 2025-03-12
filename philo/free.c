/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:03:48 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/11 21:04:58 by rafaelherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_and_close(t_philo *philos, t_table *table)
{
	free(table->mutex_fork);
	free(philos);
}