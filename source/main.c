/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:24:58 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/23 19:33:12 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_args	*args;
	int		error_check;

	args = NULL;
	error_check = parse_arguments(argc, argv, &args);
	if (error_check)
		return (handle_error(error_check), 1);
	print_args(args);
	free(args);
	return (0);
}
