/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:44:13 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/26 14:16:09 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_philo(int i, t_philo ***philos, t_table *table)
{
	(*philos)[i]->id = i;
	(*philos)[i]->alive = 1;
	(*philos)[i]->times_eaten = 0;
	(*philos)[i]->last_meal = 0;
	(*philos)[i]->left_fork = &table->forks[i];
	(*philos)[i]->right_fork = &table->forks[(i + 1) % 
		table->args->num_of_philo];
	(*philos)[i]->start_time = ft_get_time();
	(*philos)[i]->args = table->args;
	return (0);
}

static int	init_philos(t_table **table)
{
	int	i;

	i = 0;
	(*table)->philos = malloc(sizeof(t_philo) * ((*table)->args->num_of_philo));
	if (!(*table)->philos)
		return (ERR_NOMEM);
	while (i < (*table)->args->num_of_philo)
	{
		((*table)->philos)[i] = malloc(sizeof(t_philo));
		if (!((*table)->philos)[i])
			return (ERR_NOMEM);
		if (init_philo(i, &(*table)->philos, *table))
			return (ERR_NOMEM);
		i++;
	}
	return (0);
}

static int	init_forks(t_table **table)
{
	int	i;

	(*table)->forks = malloc(sizeof(pthread_mutex_t) * 
			(*table)->args->num_of_philo);
	if (!(*table)->forks)
		return (ERR_NOMEM);
	i = 0;
	while (i < (*table)->args->num_of_philo)
	{
		if (pthread_mutex_init(&(*table)->forks[i], NULL) != 0)
			return (ERR_MUTEX);
		i++;
	}
	return (0);
}

int	init(t_args *args, t_table **table)
{
	int	error_check;

	error_check = 0;
	*table = malloc(sizeof(t_table));
	if (!*table)
		return (ERR_NOMEM);
	(*table)->args = args;
	error_check = init_forks(table);
	if (error_check)
		return (error_check);
	error_check = init_philos(table);
	if (error_check)
		return (error_check);
	return (error_check);
}
