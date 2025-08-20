/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:58:28 by maborges          #+#    #+#             */
/*   Updated: 2025/08/20 20:00:13 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	dinner_start(t_table *table)
{
	// set all_ready flag
	// table->start_somulation = now_ms();
	if (table->nbr_must_eat == 0)
		return (1);
	if (table->philo_nbr == 1)
		one_philo_routine(table);
	else
		create_philos(table); //TODO
	return (0);
}
