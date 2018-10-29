/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_val_and_cams.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:43:07 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/26 15:43:07 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

int			int_val(const nx_json *nod)
{
	if (nod != NULL && nod->type == NX_JSON_INTEGER)
		return ((int)nod->int_value);
	return (0);
}

float		flt_val(const nx_json *nod)
{
	if (nod != NULL
		&& (nod->type == NX_JSON_DOUBLE || nod->type == NX_JSON_INTEGER))
		return ((float)nod->dbl_value);
	return (0.0f);
}

cl_float3	flt3_val(const nx_json *ar)
{
	cl_float3 res;

	bzero(&res, sizeof(cl_float3));
	if (ar != NULL && ar->type == NX_JSON_ARRAY)
	{
		res.x = flt_val(nx_json_item(ar, 0));
		res.y = flt_val(nx_json_item(ar, 1));
		res.z = flt_val(nx_json_item(ar, 2));
	}
	return (res);
}

int			parce_cam(const nx_json *nod, void *dst)
{
	t_rt_cam	*cam;

	cam = (t_rt_cam*)dst;
	cam->center = flt3_val(nx_json_get(nod, "center"));
	cam->transp_rotate_matrix[0].x = 1;
	cam->transp_rotate_matrix[0].y = 0;
	cam->transp_rotate_matrix[0].z = 0;
	cam->transp_rotate_matrix[1].x = 0;
	cam->transp_rotate_matrix[1].y = 1;
	cam->transp_rotate_matrix[1].z = 0;
	cam->transp_rotate_matrix[2].x = 0;
	cam->transp_rotate_matrix[2].y = 0;
	cam->transp_rotate_matrix[2].z = 1;
	return (0);
}
