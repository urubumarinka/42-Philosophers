/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:24:48 by maborges          #+#    #+#             */
/*   Updated: 2025/08/18 19:20:50 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		if (parsing_args(av, &table))
			return (1);
		if (data_init(&table))
			return (1);
	}
	else
	{
		printf(RED"Usage: must have 4 or 5 args"RESET);
		return (1);
	}
	return (0);
}
