/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:51:55 by maborges          #+#    #+#             */
/*   Updated: 2025/08/13 22:35:47 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	handle_mutex_error(int status, t_opcode opcode)
{
	if (status == EINVAL && (opcode == LOCK || opcode == UNLOCK
			|| opcode == DESTROY))
		error_msg("The value specified by mutex is invalid.");
	else if (status == EINVAL && opcode == INIT)
		error_msg("The value specified by attr is invalid.");
	else if (status == EDEADLK)
		error_msg("Deadlock would occur if thread blocked waiting for mutex.");
	else if (status == EBUSY)
		error_msg("Mutex is locked");
	else if (status == EPERM)
		error_msg("The current thread does not hold a lock on mutex.");
	else if (status == ENOMEM)
		error_msg("Process cant alloc enough memory to create another mutex.");
	else
		return (0);
	return (1);
}

int	safe_mutex(t_mtx *mutex, t_opcode opcode)
{
	if (opcode == INIT)
		return (handle_mutex_error(pthread_mutex_init(mutex, NULL), opcode));
	else if (opcode == DESTROY)
		return (handle_mutex_error(pthread_mutex_destroy(mutex), opcode));
	else if (opcode == LOCK)
		return (handle_mutex_error(pthread_mutex_lock(mutex), opcode));
	else if (opcode == UNLOCK)
		return (handle_mutex_error(pthread_mutex_unlock(mutex), opcode));
	return (0);
}

static int	handle_thread_error(int status, t_opcode opcode)
{
	if (status == EINVAL && opcode == CREATE)
		error_msg("The value specified by attr is invalid.");
	else if (status == EINVAL && (opcode == JOIN || opcode == DETACH))
		error_msg("The value specified by is not joinable");
	else if (status == EDEADLK)
		error_msg("Deadlck detected or value of thread specifies calling thrd");
	else if (status == EAGAIN)
		error_msg("System lacked necessary resources to create another thread");
	else if (status == EPERM)
		error_msg(" The caller does not have appropriate permission");
	else if (status == ESRCH)
		error_msg("No thread found corresponding to the given thread ID");
	else
		return (0);
	return (1);
}



int	safe_thread(pthread_t *thread, void *(*foo)(void *), void *data,
				t_opcode opcode)
{
	if (opcode == CREATE)
		return (handle_thread_error(pthread_create(thread, NULL, foo, data),
				opcode));
	else if (opcode == JOIN)
		return (handle_thread_error(pthread_join(*thread, NULL), opcode));
	else if (opcode == DETACH)
		return (handle_thread_error(pthread_detach(*thread), opcode));
	return (1);
}
