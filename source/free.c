/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:48:02 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/26 17:30:02 by maahoff          ###   ########.fr       */
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
	pthread_mutex_destroy(&table->grim_reaper_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
	free(table->args);
	free(table);
}
