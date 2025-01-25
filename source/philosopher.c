/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:34:35 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/25 17:35:36 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*philosophers_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("philo number %d was created\n", philo->id);
	return (NULL);
}
