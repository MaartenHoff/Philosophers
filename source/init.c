/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:44:13 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/24 18:11:56 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philo(int i, t_philo **philos, t_args args)
{
	if(args.num_of_philo)
		philos[i]->id = i + 1;
	return (0);
}

int	init_philos(t_args args, t_philo **philos)
{
	int	i;

	i = 0;
	philos = malloc(sizeof(t_philo *) * (args.num_of_philo + 1));
	if (!philos)
		return (ERR_NOMEM);
	while (i < args.num_of_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return (free_philos(philos), ERR_NOMEM);
		if (!init_philo(i, philos, args))
			return (free_philos(philos), ERR_NOMEM);
		i++;
	}
	philos[i] = NULL;
	return (0);
}
