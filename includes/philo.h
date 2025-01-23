/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:30:02 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/23 19:33:41 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_NOMEM	12		// Memory allocation error
# define ERR_INVAL	22		// Invalid argument
# define ERR_ARGC	128		// Wrong number of arguments

typedef struct s_args
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_each_philo_must_eat;
}	t_args;

int		parse_arguments(int argc, char **argv, t_args **args);
void	handle_error(int error_code);
// utils
int		ft_atoi(const char *str);
// test
void	print_args(t_args *args);
#endif