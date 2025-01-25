/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:48:02 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/25 20:18:07 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_table(t_table *table)
{
	int	i;

	i = 0;
	if (!table)
		return ;
	while (i < table->args->num_of_philo)
	{
		if (table->philos[i])
			free(table->philos[i]);
		if (&table->forks[i])
			pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
	free(table->args);
	free(table);
}
