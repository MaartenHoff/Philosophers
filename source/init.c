/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:44:13 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/25 17:56:11 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	init_philo(int i, t_philo ***philos, t_args *args)
{
	(*philos)[i]->id = i;
	(*philos)[i]->times_eaten = 0;
	(*philos)[i]->last_meal = 0;
	(*philos)[i]->args = args;
	return (0);
}

static int	init_philos(t_args *args, t_philo ***philos)
{
	int	i;

	i = 0;
	*philos = malloc(sizeof(t_philo) * (args->num_of_philo));
	if (!*philos)
		return (ERR_NOMEM);
	while (i < args->num_of_philo)
	{
		(*philos)[i] = malloc(sizeof(t_philo));
		if (!(*philos)[i])
			return (free_philos((*philos)), ERR_NOMEM);
		if (init_philo(i, philos, args))
			return (free_philos((*philos)), ERR_NOMEM);
		i++;
	}
	return (0);
}

int	init(t_args *args, t_table **table)
{
	*table = malloc(sizeof(t_table));
	if (!*table)
		return (ERR_NOMEM);
	(*table)->philos = NULL;
	(*table)->args = args;
	return (init_philos(args, &((*table)->philos)));
}
