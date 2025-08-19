/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maborges <maborges@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 14:27:08 by maborges          #+#    #+#             */
/*   Updated: 2025/08/18 19:21:02 by maborges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

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
