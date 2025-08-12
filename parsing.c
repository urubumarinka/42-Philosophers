/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:43:50 by maborges          #+#    #+#             */
/*   Updated: 2025/08/12 20:35:18 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	char_checker(char *str)
{
	int	digit_count;

	digit_count = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13) || *str == '+'
		|| *str == '0')
		str++;
	while (*str)
	{
		if (*str == '-')
			return (1);
		else if (*str < '0' || *str > '9')
			return (1);
		else
		{
			digit_count++;
			str++;
		}
	}
	if (digit_count > 10)
		return (1);
	return (0);
}

long	ft_atol(char *str)
{
	long	nbr;

	nbr = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13) || *str == '+')
		str++;
	while (*str == '0')
		str++;
	if (!*str)
	{
		error_msg("Empty input after whitespace or input is 0");
		return (-1);
	}
	while (*str)
	{
		nbr = (nbr * 10) + *str - '0';
		str++;
	}
	if (nbr > INT_MAX)
	{
		error_msg("values must not be bigger than INT_MAX");
		return (-1);
	}
	return (nbr);
}

int	parsing_args(char **av, t_table *table)
{
	int		i;
	long	result;

	i = 0;
	table->nbr_must_eat = -1;
	while (av[++i])
	{
		if (char_checker(av[i]))
			return (error_msg("Inputs must be positive integers"), 1);
		result = ft_atol(av[i]);
		if (result == -1)
			return (1);
		else if (i == 1)
			table->philo_nbr = result;
		else if (i == 2)
			table->time_to_die = result;
		else if (i == 3)
			table->time_to_eat = result;
		else if (i == 4)
			table->time_to_sleep = result;
		else if (i == 5)
			table->nbr_must_eat = result;
	}
	return (0);
}
