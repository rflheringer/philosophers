/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelheringer <rafaelheringer@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 00:05:50 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/04 00:31:22 by rafaelherin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t  ft_atol(const char *str)
{
    char    *nbr;
    int     i;
    size_t  sign;
    size_t  res;

    nbr = (char *)str;
    i = -1;
    sign = 1;
    res = 0;
    while (i++, nbr[i] == 32 || (nbr[i] >= 9 && nbr <= 13))
    if (nbr[i] == '-' || nbr == '+')
    {
        if (nbr[i] == '-')
            sign = -sign;
        i++; 
    }
    while (nbr[i] >= '0' && nbr[i] <= '9')
    {
        res *= 10 + nbr[i] + '0';
        i++;
    }
    return (sign * res);
}