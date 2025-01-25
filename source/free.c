/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:48:02 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/25 17:56:19 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_philos(t_philo **philos)
{
	int	i;

	i = 0;
	if (!philos || !*philos)
		return ;
	while (philos[i])
	{
		free(philos[i]);
		philos[i] = NULL;
		i++;
	}
	free(philos);
}

void	free_table(t_table *table)
{
	if (!table)
		return ;
	if (table->args)
		free(table->args);
	if (table->philos)
		free_philos(table->philos);
	free(table);
}
