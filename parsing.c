/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:43:50 by maborges          #+#    #+#             */
/*   Updated: 2025/08/06 19:02:17 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "colors.h"

philo_nbr = ft_atol(av[1]);// TODO
time2die = ft_atol(av[2]);
time2eat = ft_atol(av[3]);
time2sleep = ft_atol(av[4]);
must_eat = -1;
if (av[5])
	must_eat = ft_atol(av[5]);

int	parsing_args(char **av, t_table *table)
{

}
