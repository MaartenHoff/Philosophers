/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:30:02 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/26 19:25:00 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

# define ERR_NOMEM	12		// Memory allocation error
# define ERR_INVAL	22		// Invalid argument
# define ERR_ARGC	128		// Wrong number of arguments
# define ERR_THREAD 130		// Thread creation failed
# define ERR_MUTEX	131		// Mutex initialization/destroying failed

typedef struct s_args
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_each_philo_must_eat;
}	t_args;

typedef struct s_philo
{
	int				id;
	int				times_eaten;
	long long		last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*grim_reaper_mutex;
	pthread_mutex_t	*print_mutex;
	int				*sim_terminated;
	pthread_t		thread;
	long long		start_time;
	t_args			*args;
}	t_philo;

typedef struct s_table
{
	t_philo			**philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	grim_reaper_mutex;
	int				sim_terminated;
	pthread_mutex_t	print_mutex;
	t_args			*args;
}	t_table;

//main
int			parse_arguments(int argc, char **argv, t_args **args);
int			init(t_args *args, t_table **table);
void		*philosophers_life(void *arg);

// free/error
void		free_table(t_table *table);
void		handle_error(int error_code, t_args *args, t_table *table);

// utils
int			ft_atoi(const char *str);
long long	ft_get_time(void);
void		kill_solo_philo(t_philo *philo);
int			ft_sim_terminated(t_philo *philo);
void		ft_print_state(t_philo *philo, char *state);
void		some_strange_ft_that_doesnt_fit_anywhere_else(t_philo *philo);
int			philo_dead(t_philo *philo);

// test
void		print_args(t_args *args);

#endif