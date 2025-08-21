/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_and_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:27:08 by maborges          #+#    #+#             */
/*   Updated: 2025/08/21 18:11:20 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	destroy_and_free(t_table *table)
{
	int	i;

	i = -1;
	if (!table)
		return ;
	if (table->forks)
		while (++i < table->philo_nbr)
			safe_mutex(&table->forks[i].fork, DESTROY);
    // If t_philo has per-philo mutexes, destroy them here:
    // if (table->philos) {
    // 	for (i = 0; i < table->philo_nbr; ++i)
    // 		safe_mutex(&table->philos[i].meal_lock, DESTROY);
    // }
	safe_mutex(&table->print_lock, DESTROY);
	if (table->forks)
	{
		free(table->forks);
		table->forks = NULL;
	}
	if (table->philos)
	{
		free(table->philos);
		table->philos = NULL;
	}
}

static void	ft_putstr_err(const char *error)
{
	size_t	len;

	len = 0;
	while (error[len])
		len++;
	write(2, error, len);
}

void	error_msg(const char *error)
{
	write(2, RED, 5);
	write(2, "Error:\n", 7);
	write(2, RESET, 4);
	ft_putstr_err(error);
	write(2, "\n", 1);
}
