/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 17:13:59 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/24 17:14:00 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void		ocl_error(int err)
{
	if (err == 1)
		WRITE("\033[1;31mError: Failed to create a device group!\n\e[m");
	else if (err == 2)
		WRITE("\033[1;31mError: Failed to create a compute context!\n\e[m");
	else if (err == 3)
		WRITE("\033[1;31mError: Failed to create a command commands!\n\e[m");
	else if (err == 4)
		WRITE("\033[1;31mError: Failed to create compute program!\n\e[m");
	else if (err == 5)
		WRITE("\033[1;31mError: Failed to build program executable!\n\e[m");
	else if (err == 6)
		WRITE("\033[1;31mError: Failed to create compute kernel!\n\e[m");
	else if (err == 7)
		WRITE("\033[1;31mError: Failed to allocate device memory!\n\e[m");
	else if (err == 8)
		WRITE("\033[1;31mError: Failed to write to source array!\n\e[m");
	else if (err == 9)
		WRITE("\033[1;31mError: Failed to set kernel arguments!\n\e[m");
	else if (err == 10)
		WRITE("\033[1;31mError: Failed to execute kernel!\n\e[m");
	else if (err == 11)
		WRITE("\033[1;31mError: Failed to read output array!\n\e[m");
	exit(0);
}
