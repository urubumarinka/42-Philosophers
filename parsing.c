/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:43:50 by maborges          #+#    #+#             */
/*   Updated: 2025/08/06 19:14:58 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parsing_args(char **av, t_table *table)
{
	//1) check if its a digit
	//2) check if its smaller than INT

	table->philo_nbr = ft_atol(av[1]);// TODO
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	table->nbr_must_eat = -1;
	if (av[5])
		table->nbr_must_eat = ft_atol(av[5]);

}
