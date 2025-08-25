/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:24:48 by maborges          #+#    #+#             */
/*   Updated: 2025/08/25 13:24:43 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int ac, char **av)
{
	t_table	table;

	if (ac == 5 || ac == 6)
	{
		if (parsing_args(av, &table) || data_init(&table))
			return (1);
		if (dinner_start(&table))
			return (1);
		if (destroy_and_free(&table))
			return (1);
	}
	else
		return (error_msg("Usage: must have 4 or 5 args\n"), 1);

	return (0);
}
