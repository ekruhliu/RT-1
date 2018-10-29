/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:10:41 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/24 16:10:42 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void	add_to_first_sc(cl_float3 *first, cl_float3 *second, float sc)
{
	first->x += sc * second->x;
	first->y += sc * second->y;
	first->z += sc * second->z;
}

void	add_to_first(cl_float3 *first, cl_float3 *second)
{
	add_to_first_sc(first, second, 1);
}

void	minus_to_first(cl_float3 *first, cl_float3 *second)
{
	add_to_first_sc(first, second, -1);
}

void	mult_to_first_second(cl_float3 *first, cl_float3 *second)
{
	cl_float3	buff[3];
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		memcpy(&buff[i], &first[i], sizeof(cl_float3));
		i++;
	}
	transp_local(second);
	while (j < 3)
	{
		first[j].x = dot(&buff[j], &second[0]);
		first[j].y = dot(&buff[j], &second[1]);
		first[j].z = dot(&buff[j], &second[2]);
		j++;
	}
}
