/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_to_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:56:00 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/24 16:56:01 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void	set_obj_normal1(t_cl_object *obj)
{
	if (obj->dir.y != 0)
	{
		obj->normal1.x = 1;
		obj->normal1.z = 1;
		obj->normal1.y = -(obj->dir.x + obj->dir.z) / obj->dir.y;
	}
	else if (obj->dir.x != 0)
	{
		obj->normal1.y = 1;
		obj->normal1.z = 1;
		obj->normal1.x = -obj->dir.z / obj->dir.x;
	}
	else
	{
		obj->normal1.y = 1;
		obj->normal1.x = 1;
		obj->normal1.z = -obj->dir.x / obj->dir.z;
	}
}

void	set_obj_normals(t_cl_object *obj)
{
	set_obj_normal1(obj);
	normalize_local(&obj->normal1);
	obj->normal2 = cross(&obj->normal1, &obj->dir);
	normalize_local(&obj->normal2);
}

void	obj_to_normal(t_cl_object *obj, double angle)
{
	if (obj->dir.x == 0 && obj->dir.y == 0 && obj->dir.z == 0)
		obj->dir = vector_by_points(&obj->centre, &obj->centre1);
	if ((obj->limited && obj->type == PLANE))
		obj->dir = get_normal_to_plane(&obj->centre, &obj->centre1,
			&obj->centre2);
	if (obj->type == CONE && angle != 0)
	{
		angle = angle * M_PI / 180.0f;
		obj->sq_cos = (float)cos(angle);
		obj->sq_sin = (float)sin(angle);
		if (obj->limited)
			obj->radius = vector_len(&obj->dir) * obj->sq_sin / obj->sq_cos;
		obj->sq_cos *= obj->sq_cos;
		obj->sq_sin *= obj->sq_sin;
	}
	if (obj->type == CONE || obj->type == CYLINDER)
		set_obj_normals(obj);
	normalize_local(&obj->dir);
	valid_obj(obj);
}
