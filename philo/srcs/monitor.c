/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:36:33 by maborges          #+#    #+#             */
/*   Updated: 2025/08/22 18:35:13 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/philo.h"

//TODO

// a thread to monitor in a loop checking each philos last_meal
// if it timed-out or ate already all their meals.
// set end simulation and print

void	*monitor(void *arg)
{
	int		i;
	t_table	*table;
	long	last_meal;
	int		meals;

	table = (t_table *)arg;
	while (!table->end_simulation)
	{
		i = -1;
		while (++i < table->philo_nbr)
		{
			safe_mutex(&table->philos[i].meal_lock, LOCK);
			last_meal = table->philos[i].last_meal;
			if (table->nbr_must_eat > 0)
				meals = table->philos[i].meals_eaten;
			safe_mutex(&table->philos[i].meal_lock, UNLOCK);
			if (now_ms() - last_meal > table->time_to_die)
				return (print_action(table, table->philos[i].id, A_DIED), NULL);
			if (table->nbr_must_eat > 0 && meals < table->nbr_must_eat) // inverted logic here
				table->philos[i].full = true; // wrote out of lock, datarace
		}
		if (table->nbr_must_eat > 0 && table->philos[i].full == true) //  this is wrong, out of bound
			return (table->end_simulation = true, NULL);
		usleep(1000);
	}
	return (NULL);
}
