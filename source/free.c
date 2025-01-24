/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:48:02 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/24 16:50:04 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_philos(t_philo **philos)
{
	int	i;

	i = 0;
	while (philos[i])
	{
		free(philos[i]);
		philos[i] = NULL;
		i++;
	}
	free(philos);
}
