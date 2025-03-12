/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:24:20 by rafaelherin       #+#    #+#             */
/*   Updated: 2025/03/12 16:12:57 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_sign(char *argv[], int i, int *j, bool *sign)
{
	if (argv[i][*j] == '+' || argv[i][*j] == '-')
	{
		*sign = true;
		if (argv[i][*j] == '-')
			error_exit("Invalid negative number.");
		else
			*j = *j + 1;
	}
}

void	check_zero(int argc, char *argv[])
{
	if (ft_atol(argv[1]) == 0)
		error_exit("Number of philosophers must be bigger than 0");
	if (argc == 6 && ft_atol(argv[5]) == 0)
		exit(0);
}

void	check_size(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len > 10 || (len == 10 && ft_strcmp(str, "2147483647") > 0))
		error_exit("Argument is too big");
}

void	validate_arguments(int argc, char *argv[])
{
	int		i;
	int		j;
	bool	sign;

	if (argc < 5 || argc > 6)
		error_exit("Invalid number of arguments.");
	i = 1;
	sign = false;
	while (argv[i])
	{
		j = 0;
		check_sign(argv, i, &j, &sign);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				error_exit("Invalid number.");
			j++;
		}
		check_size(argv[i]);
		i++;
	}
	check_zero(argc, argv);
}
