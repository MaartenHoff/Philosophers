/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:24:58 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/26 14:50:31 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	start_sim(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->args->num_of_philo)
	{
		if (pthread_create(&table->philos[i]->thread, NULL, &philosophers_life, 
				table->philos[i]) != 0)
			return (ERR_THREAD);
		i++;
	}
	return (0);
}

static void	end_sim(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->args->num_of_philo)
	{
		pthread_join(table->philos[i]->thread, NULL);
		i++;
	}
	free_table(table);
}

int	main(int argc, char **argv)
{
	t_args	*args;
	t_table	*table;
	int		error_check;

	args = NULL;
	table = NULL;
	error_check = parse_arguments(argc, argv, &args);
	if (error_check)
		return (handle_error(error_check, args, table), 1);
	error_check = init(args, &table);
	if (error_check)
		return (handle_error(error_check, args, table), 1);
	error_check = start_sim(table);
	if (error_check)
		return (handle_error(error_check, args, table), 1);
	end_sim(table);
	return (0);
}
