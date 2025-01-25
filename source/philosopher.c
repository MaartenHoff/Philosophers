/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:34:35 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/25 20:41:15 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("Philosopher %d has taken left fork\n", philo->id);
	pthread_mutex_lock(philo->right_fork);
	printf("Philosopher %d has taken right fork\n", philo->id);
	printf("Philospher %d is eating\n", philo->id);
	usleep(philo->args->time_to_eat * 1000);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	philo_sleep(t_philo *philo)
{
	printf("Philospher %d is sleeping\n", philo->id);
	usleep(philo->args->time_to_sleep * 1000);
}

static void	philo_think(t_philo *philo)
{
	printf("Philospher %d is thinking\n", philo->id);
}

void	*philosophers_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		if (philo->args->num_of_times_each_philo_must_eat > 0 && 
			philo->times_eaten >= philo->args->num_of_times_each_philo_must_eat)
			break ;
	}
	return (NULL);
}
