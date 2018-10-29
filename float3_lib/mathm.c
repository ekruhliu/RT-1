/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:09:13 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/24 16:09:13 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"
#define SQ(x) ((x) * (x))

cl_float3	cross(cl_float3 *u, cl_float3 *v)
{
	cl_float3 res;

	res.x = u->y * v->z - u->z * v->y;
	res.y = -u->x * v->z + u->z * v->x;
	res.z = u->x * v->y - u->y * v->x;
	return (res);
}

float		dot(cl_float3 *v1, cl_float3 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

float		vector_len(cl_float3 *v)
{
	return (sqrt(SQ(v->x) + SQ(v->y) + SQ(v->z)));
}

void		mult_local(float sc, cl_float3 *to_mult)
{
	to_mult->x *= sc;
	to_mult->y *= sc;
	to_mult->z *= sc;
}
