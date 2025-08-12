/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:47:22 by maborges          #+#    #+#             */
/*   Updated: 2025/08/12 22:34:54 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	data_init(t_table *table)
{
	table->end_simulation = false;
	table->philos = malloc(sizeof(t_philo) * table->philo_nbr);
	if (!table->philos == NULL)
	{
		error_msg("malloc failed");
		return (1);
	}
	//call here safe_mutex? sucess return is 0


}
