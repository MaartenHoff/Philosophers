/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maahoff <maahoff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 19:04:23 by maahoff           #+#    #+#             */
/*   Updated: 2025/01/25 18:04:44 by maahoff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	handle_error(int error_code, t_args *args, t_table *table)
{
	if (args)
		free(args);
	if (table)
		free_table(table);
	if (error_code == ERR_ARGC)
		write(2, "Error: Wrong number of arguments\n", 33);
	else if (error_code == ERR_INVAL)
		write(2, "Error: Invalid argument\n", 25);
	else if (error_code == ERR_NOMEM)
		write(2, "Error: Memory allocation failed\n", 32);
	else if (error_code == ERR_THREAD)
		write(2, "Error: Thread creation failed\n", 30);
	else
		write(2, "Error: Unknown error\n", 22);
}
