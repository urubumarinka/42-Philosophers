/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:05:19 by maborges          #+#    #+#             */
/*   Updated: 2025/08/22 17:07:56 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	one_philo_routine(t_table *table)
{
	safe_mutex(&table->forks[0].fork, LOCK);
	print_action(table, 1, A_TAKE_FORK);
	ft_usleep(table->time_to_die);
	print_action(table, 1, A_DIED);
	safe_mutex(&table->forks[0].fork, UNLOCK);
}

// Temporary stub to allow compilation until routines are implemented
static void philo_think(t_table *table, int i)
{
	(void)table;
	(void)i;
}

void	routine(t_table *table)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < table->philo_nbr)
		{
			philo_think(table, i); // TODO: implement routine actions
			if (table->end_simulation == true)
				break ;

		}

	}

}
