/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:47:22 by maborges          #+#    #+#             */
/*   Updated: 2025/08/18 19:20:47 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	assign_forks(t_philo *philo, t_fork *fork, int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	if (philo->id % 2 == 0)
	{
		philo->right_fork = &fork[philo_position];
		philo->left_fork = &fork[philo->id % philo_nbr];
	}
	else
	{
		philo->left_fork = &fork[philo->id % philo_nbr];
		philo->right_fork = &fork[philo_position];
	}
}

int	data_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	i = -1;
	table->start_simulation = 0;
	table->end_simulation = false;
	table->all_threads_ready = false;
	table->philos = safe_malloc(sizeof(t_philo) * table->philo_nbr);
	table->forks = safe_malloc(sizeof(t_fork) * table->philo_nbr);
	while (++i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->nbr_meals = 0;
		philo->table = table;
		safe_mutex(&table->forks[i].fork, INIT);
		table->forks[i].fork_id = i;
		assign_forks(philo, table->forks, i);
	}
	return (0);
}
