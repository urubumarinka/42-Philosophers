/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_reads_writes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:37:10 by maborges          #+#    #+#             */
/*   Updated: 2025/08/25 13:43:45 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	write_bool(t_mtx *mutex, bool *new_value, bool value)
{
	safe_mutex(mutex, LOCK);
	*new_value = value;
	safe_mutex(mutex, UNLOCK);
}

bool	read_bool(t_mtx *mutex, bool *value)
{
	bool	read_value;

	safe_mutex(mutex, LOCK);
	read_value = *value;
	safe_mutex(mutex, UNLOCK);
	return (read_value);
}

void	write_long(t_mtx *mutex, long *new_value, long value)
{
	safe_mutex(mutex, LOCK);
	*new_value = value;
	safe_mutex(mutex, UNLOCK);
}

bool	read_long(t_mtx *mutex, long *value)
{
	long	read_value;

	safe_mutex(mutex, LOCK);
	read_value = *value;
	safe_mutex(mutex, UNLOCK);
	return (read_value);
}


