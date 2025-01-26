/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:09:06 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/26 19:24:17 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		pn;
	long	result;

	i = 0;
	pn = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pn *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - '0') + result * 10;
		i++;
	}
	return (pn * (int)result);
}

long long	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	kill_solo_philo(t_philo *philo)
{
	printf("[%lld] Philosopher %d has taken left fork\n", 
		(ft_get_time() - philo->start_time), philo->id);
	usleep(philo->args->time_to_die * 1000);
	printf("[%lld] Philosopher %d has died\n",
		(ft_get_time() - philo->start_time), philo->id);
}

int	ft_sim_terminated(t_philo *philo)
{
	pthread_mutex_lock(philo->grim_reaper_mutex);
	if (*philo->sim_terminated)
		return (pthread_mutex_unlock(philo->grim_reaper_mutex), 1);
	pthread_mutex_unlock(philo->grim_reaper_mutex);
	return (0);
}

void	ft_print_state(t_philo *philo, char *state)
{
	pthread_mutex_lock(philo->print_mutex);
	if (ft_sim_terminated(philo))
	{
		pthread_mutex_unlock(philo->print_mutex);
		return ;
	}
	printf("%lld %d %s\n", 
		(ft_get_time() - philo->start_time), philo->id + 1, state);
	pthread_mutex_unlock(philo->print_mutex);
}
