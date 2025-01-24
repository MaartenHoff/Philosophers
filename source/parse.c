/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:01:51 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/24 16:06:23 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	validate_args(t_args args, int argc)
{
	if (args.num_of_philo <= 0 || args.time_to_die <= 0 || 
		args.time_to_eat <= 0 || args.time_to_sleep <= 0)
		return (ERR_INVAL);
	if (argc == 6 && args.num_of_times_each_philo_must_eat <= 0)
		return (ERR_INVAL);
	return (0);
}

int	parse_arguments(int argc, char **argv, t_args *args)
{
	int	error_check;

	error_check = 0;
	if (argc < 5 || argc > 6)
		return (ERR_ARGC);
	args = malloc(sizeof(t_args));
	if (!args)
		return (ERR_NOMEM);
	args->num_of_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->num_of_times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		args->num_of_times_each_philo_must_eat = 0;
	error_check = validate_args(*args, argc);
	if (error_check)
		return (free(args), error_check);
	return (0);
}
