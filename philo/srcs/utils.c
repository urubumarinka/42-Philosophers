/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:30:13 by maborges          #+#    #+#             */
/*   Updated: 2025/08/20 20:05:27 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static const char *action_str(t_action a)
{
	if (a == A_TAKE_FORK) return "has taken a fork";
	if (a == A_EAT)       return "is eating";
	if (a == A_SLEEP)     return "is sleeping";
	if (a == A_THINK)     return "is thinking";
	return "died";
}

void print_action(t_table *table, int philo_id, t_action action)
{
	long ts;

	pthread_mutex_lock(&table->print_lock);
	// Allow exactly one "died" line even when ending; suppress others.
	if (table->end_simulation && action != A_DIED)
	{
		pthread_mutex_unlock(&table->print_lock);
		return ;
	}
	ts = since_start_ms(table);
	printf("%ld %d %s\n", ts, philo_id, action_str(action));
	if (action == A_DIED)
		table->end_simulation = true;
	pthread_mutex_unlock(&table->print_lock);
}

long	now_ms(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));

}

long	since_start_ms(t_table *table)
{
	return (now_ms() - table->start_simulation);
}

// Sleep for ms milliseconds with decent precision (avoids long usleep drift)
void	ft_usleep(long ms)
{
	long	end = now_ms() + ms;

	while (now_ms() < end)
	{
		long	remaining;

		remaining = end - now_ms();
		if (remaining > 10)
			usleep(5000); // 5 ms
		else
			usleep(100); // 0.1 ms to finish
	}
}
