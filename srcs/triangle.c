/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 08:53:44 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/22 08:53:45 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

int		is_trinagle(cl_float3 *p, cl_float3 *p1, cl_float3 *p2)
{
	cl_float3	sides[3];
	float		lenghts[3];
	int			i;

	i = 0;
	sides[0] = vector_by_points(p, p1);
	sides[1] = vector_by_points(p, p2);
	sides[2] = vector_by_points(p1, p2);
	while (i < 3)
	{
		lenghts[i] = vector_len(&sides[i]);
		i++;
	}
	return (lenghts[0] + lenghts[1] > lenghts[2] && \
			lenghts[0] + lenghts[2] > lenghts[1] && \
			lenghts[1] + lenghts[2] > lenghts[0]);
}
