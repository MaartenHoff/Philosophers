/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:34:35 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/26 20:53:15 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_dead(t_philo *philo)
{
	if (ft_sim_terminated(philo))
		return (1);
	if (ft_get_time() - philo->last_meal > philo->args->time_to_die)
	{
		ft_print_state(philo, "died");
		pthread_mutex_lock(philo->grim_reaper_mutex);
		*philo->sim_terminated = 1;
		pthread_mutex_unlock(philo->grim_reaper_mutex);
		return (1);
	}
	return (0);
}

static void	philo_eat(t_philo *philo)
{
	if (ft_sim_terminated(philo) && philo_dead(philo))
		return ;
	if (philo->id % 2 == 0) 
	{
		pthread_mutex_lock(philo->left_fork);
		pthread_mutex_lock(philo->right_fork);
	}
	else 
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
	}
	philo_dead(philo);
	ft_print_state(philo, "has taken a fork");
	ft_print_state(philo, "has taken a fork");
	ft_print_state(philo, "is eating");
	philo->last_meal = ft_get_time();
	if (philo->args->time_to_eat >= philo->args->time_to_die)
		some_strange_ft_that_doesnt_fit_anywhere_else(philo);
	else
		usleep(philo->args->time_to_eat * 999);
	philo->times_eaten++;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	philo_sleep(t_philo *philo)
{
	if (ft_sim_terminated(philo) && philo_dead(philo))
		return ;
	ft_print_state(philo, "is sleeping");
	if (philo->args->time_to_sleep >= philo->args->time_to_die)
	{
		some_strange_ft_that_doesnt_fit_anywhere_else(philo);
		return ;
	}
	usleep(philo->args->time_to_sleep * 1000);
}

static void	philo_think(t_philo *philo)
{
	if (ft_sim_terminated(philo) && philo_dead(philo))
		return ;
	usleep(200);
	ft_print_state(philo, "is thinking");
}

void	*philosophers_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->args->num_of_philo == 1)
		return (kill_solo_philo(philo), NULL);
	philo->last_meal = ft_get_time();
	while (!ft_sim_terminated(philo) && !philo_dead(philo))
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
