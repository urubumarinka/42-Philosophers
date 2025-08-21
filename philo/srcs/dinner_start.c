/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:58:28 by maborges          #+#    #+#             */
/*   Updated: 2025/08/21 18:47:49 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	dinner_start(t_table *table)
{
	// set all_ready flag
	if (table->nbr_must_eat == 0)
		return (0);
	table->start_simulation = now_ms();
	if (table->philo_nbr == 1)
		one_philo_routine(table);
	else
		create_philos(table); //TODO create threads, monitor, join
	return (0);
}
