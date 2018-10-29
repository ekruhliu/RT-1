/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float3_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 08:53:26 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/22 08:53:27 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void		normalize_local(cl_float3 *to_normalize)
{
	float len;

	len = vector_len(to_normalize);
	mult_local(1.0 / len, to_normalize);
}

cl_float3	get_normal_to_plane(cl_float3 *p, cl_float3 *p1, cl_float3 *p2)
{
	cl_float3 v1;
	cl_float3 v2;

	v1 = vector_by_points(p, p2);
	v2 = vector_by_points(p, p1);
	return (cross(&v1, &v2));
}

cl_float3	vector_by_points(cl_float3 *p, cl_float3 *p1)
{
	cl_float3 res;

	res.x = p1->x - p->x;
	res.y = p1->y - p->y;
	res.z = p1->z - p->z;
	return (res);
}

cl_float3	norm_vector_by_points(cl_float3 *p, cl_float3 *p1)
{
	cl_float3 res;

	res = vector_by_points(p, p1);
	normalize_local(&res);
	return (res);
}

void		transp_local(cl_float3 *matrix)
{
	cl_float3	buff[3];
	int			i;

	i = 0;
	buff[0].x = matrix[0].x;
	buff[1].x = matrix[0].y;
	buff[2].x = matrix[0].z;
	buff[0].y = matrix[1].x;
	buff[1].y = matrix[1].y;
	buff[2].y = matrix[1].z;
	buff[0].z = matrix[2].x;
	buff[1].z = matrix[2].y;
	buff[2].z = matrix[2].z;
	while (i < 3)
	{
		memcpy(&matrix[i], &buff[i], sizeof(cl_float3));
		i++;
	}
}
