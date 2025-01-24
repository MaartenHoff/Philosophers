/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:24:58 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/24 16:39:28 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_args	*args;	
	t_philo	**philos;
	int		error_check;

	args = NULL;
	philos = NULL;
	error_check = parse_arguments(argc, argv, args);
	if (error_check)
		return (handle_error(error_check), 1);
	error_check = init_philos(*args, philos);
	if (error_check)
		return (handle_error(error_check), 1);
	free(args);
	return (0);
}
