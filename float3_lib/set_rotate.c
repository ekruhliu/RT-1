/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:06:52 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/24 16:06:53 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void	set_rotate_x(cl_float3 *buff, float angle)
{
	bzero(buff, sizeof(cl_float3));
	bzero(buff + 1, sizeof(cl_float3));
	bzero(buff + 2, sizeof(cl_float3));
	buff[0].x = 1;
	buff[1].y = cos(angle);
	buff[1].z = -sin(angle);
	buff[2].y = -buff[1].z;
	buff[2].z = buff[1].y;
}

void	set_rotate_y(cl_float3 *buff, float angle)
{
	bzero(buff, sizeof(cl_float3));
	bzero(buff + 1, sizeof(cl_float3));
	bzero(buff + 2, sizeof(cl_float3));
	buff[0].x = cos(angle);
	buff[0].z = sin(angle);
	buff[1].y = 1;
	buff[2].x = -buff[0].z;
	buff[2].z = buff[0].x;
}

void	set_rotate_z(cl_float3 *buff, float angle)
{
	bzero(buff, sizeof(cl_float3));
	bzero(buff + 1, sizeof(cl_float3));
	bzero(buff + 2, sizeof(cl_float3));
	buff[0].x = cos(angle);
	buff[0].y = -sin(angle);
	buff[1].x = -buff[0].y;
	buff[1].y = buff[0].x;
	buff[2].z = 1;
}

void	rotate_local(cl_float3 *v, cl_float3 *transp_matrix)
{
	cl_float3 buff;

	buff.x = dot(v, &transp_matrix[0]);
	buff.y = dot(v, &transp_matrix[1]);
	buff.z = dot(v, &transp_matrix[2]);
	v->x = buff.x;
	v->y = buff.y;
	v->z = buff.z;
}
