/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:58:28 by maborges          #+#    #+#             */
/*   Updated: 2025/08/22 17:08:27 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static int	philos_create(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_nbr)
	{
		table->philos[i].last_meal = now_ms();
		if (safe_thread(table->philos[i].thread_id, NULL, CREATE) != 0)
			return (1);
		usleep(100);
	}
	if (safe_thread(table->monitor, NULL, monitor, table) != 0)
		return (1);
	return (0);
}

int	dinner_start(t_table *table)
{
	if (table->nbr_must_eat == 0)
		return (0);
	if (table->philo_nbr == 1)
		one_philo_routine(table);
	else
	{
		philos_create(table);
		philo_routine(table); //TODO create threads, monitor, join
	}
	table->start_simulation = now_ms();
	// set all_ready flag. table->start_time (ms timestamp)
	//and an atomic/all_ready flag (or mutex+cond).
	//Threads busy-wait on all_ready or check
	//start_time != 0 before proceeding.

	return (0);
}
