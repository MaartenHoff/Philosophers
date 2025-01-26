/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:34:35 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/26 14:34:59 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("[%lld] Philosopher %d has taken left fork\n", 
		(ft_get_time() - philo->start_time), philo->id);
	pthread_mutex_lock(philo->right_fork);
	printf("[%lld] Philosopher %d has taken right fork\n", 
		(ft_get_time() - philo->start_time), philo->id);
	printf("[%lld] Philospher %d is eating\n", 
		(ft_get_time() - philo->start_time), philo->id);
	philo->last_meal = ft_get_time();
	usleep(philo->args->time_to_eat * 1000);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	philo_sleep(t_philo *philo)
{
	printf("[%lld] Philospher %d is sleeping\n", 
		(ft_get_time() - philo->start_time), philo->id);
	usleep(philo->args->time_to_sleep * 1000);
}

static void	philo_think(t_philo *philo)
{
	printf("[%lld] Philospher %d is thinking\n", 
		(ft_get_time() - philo->start_time), philo->id);
}

void	*philosophers_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->args->num_of_philo == 1)
		return (kill_solo_philo(philo), NULL);
	if ((philo->id + 1) % 2 == 0)
		usleep(philo->args->time_to_eat);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		if (philo->args->num_of_times_each_philo_must_eat > 0 && 
			philo->times_eaten >= philo->args->num_of_times_each_philo_must_eat)
			break ;
		if (ft_get_time() - philo->last_meal > philo->args->time_to_die)
		{
			philo->alive = 0;
			printf("[%lld] Philosopher %d has died\n",
				(ft_get_time() - philo->start_time), philo->id);
			break ;
		}
	}
	return (NULL);
}
