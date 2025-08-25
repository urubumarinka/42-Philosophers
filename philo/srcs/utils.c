/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:27:08 by maborges          #+#    #+#             */
/*   Updated: 2025/08/25 16:31:46 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static const char *action_str(t_action a)
{
	if (a == A_TAKE_FORK)
		return ("has taken a fork");
	if (a == A_EAT)
		return ("is eating");
	if (a == A_SLEEP)
		return ("is sleeping");
	if (a == A_THINK)
		return ("is thinking");
	return ("died");
}

void print_action(t_table *table, int philo_id, t_action action)
{
	long	ts;

	safe_mutex(&table->print_lock, LOCK);
	// Allow exactly one "died" line even when ending; suppress others.
	if (table->end_simulation && action != A_DIED)
	{
		safe_mutex(&table->print_lock, UNLOCK);
		return ;
	}
	ts = since_start_ms(table);
	printf("%ld %d %s\n", ts, philo_id, action_str(action));
	if (action == A_DIED)
		table->end_simulation = true;
	safe_mutex(&table->print_lock, UNLOCK);
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
int	ft_usleep(long ms, t_table *table)
{
	long	remaining;
	long	end;

	end = now_ms() + ms;

	while (now_ms() < end)
	{
		if (read_bool(&table->table_mutex, &table->end_simulation) != true)
			return (1);
		remaining = end - now_ms();
		if (remaining > 10)
			usleep(remaining * 1000/ 2); // 5 ms
		else
			usleep(100); // 0.1 ms to finish
	}
	return (0);
}
