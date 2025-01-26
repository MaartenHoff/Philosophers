/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:01:51 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/26 19:00:56 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	some_strange_ft_that_doesnt_fit_anywhere_else(t_philo *philo)
{
	while (ft_get_time() - philo->start_time < philo->args->time_to_die)
		continue ;
	ft_print_state(philo, "has died");
	pthread_mutex_lock(philo->grim_reaper_mutex);
	*philo->sim_terminated = 1;
	pthread_mutex_unlock(philo->grim_reaper_mutex);
	return ;
}

static int	validate_args(t_args args, int argc)
{
	if (args.num_of_philo <= 0 || args.time_to_die <= 0 || 
		args.time_to_eat <= 0 || args.time_to_sleep <= 0)
		return (ERR_INVAL);
	if (argc == 6 && args.num_of_times_each_philo_must_eat <= 0)
		return (ERR_INVAL);
	return (0);
}

int	parse_arguments(int argc, char **argv, t_args **args)
{
	if (argc < 5 || argc > 6)
		return (ERR_ARGC);
	*args = malloc(sizeof(t_args));
	if (!args)
		return (ERR_NOMEM);
	(*args)->num_of_philo = ft_atoi(argv[1]);
	(*args)->time_to_die = ft_atoi(argv[2]);
	(*args)->time_to_eat = ft_atoi(argv[3]);
	(*args)->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*args)->num_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		(*args)->num_of_times_each_philo_must_eat = 0;
	return (validate_args(**args, argc));
}
