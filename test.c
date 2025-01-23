/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:15:19 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/23 19:36:17 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	print_args(t_args *args)
{
	if (!args)
		return ;
	printf("args:\nnum_of_philo: %d\ntime_to_die: %d\ntime_to_eat: %d \
		\ntime_to_sleep: %d\nnum_of_times_each_philo_must_eat: %d\n", 
		args->num_of_philo, args->time_to_die, args->time_to_eat, 
		args->time_to_sleep, args->num_of_times_each_philo_must_eat);
}
