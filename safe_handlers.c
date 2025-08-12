/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:51:55 by maborges          #+#    #+#             */
/*   Updated: 2025/08/12 20:17:32 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_mutex(t_mtx *mutex, t_mtx_code mtx_code)
{
	if (mtx_code == INIT)
		pthread_mutex_init(mutex, NULL);
	else if (mtx_code == DESTROY)
		pthread_mutex_destroy(mutex);
	else if (mtx_code == LOCK)
		pthread_mutex_lock(mutex);
	else if (mtx_code == UNLOCK)
		pthread_mutex_unlock(mutex);
	else
	{
		error_msg("wrong mtx_code for mtx handler");
		return (0);
	}

}
