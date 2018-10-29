/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_json.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 19:56:28 by akokoshk          #+#    #+#             */
/*   Updated: 2018/09/20 20:23:55 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

static int			parce_lgt(const nx_json *nod, void *dst)
{
	t_cl_light	*lgt;
	double		angle;

	lgt = (t_cl_light*)dst;
	lgt->type = int_val(nx_json_get(nod, "type"));
	lgt->centre = flt3_val(nx_json_get(nod, "center"));
	lgt->dir = flt3_val(nx_json_get(nod, "dir"));
	if (lgt->type == PARAL)
		normalize_local(&lgt->dir);
	lgt->intens = flt3_val(nx_json_get(nod, "intens"));
	angle = flt_val(nx_json_get(nod, "angle")) * M_PI / 180.0f;
	lgt->cos_a = (float)cos(angle);
	valid_light(lgt);
	return (0);
}

static int			parce_obj(const nx_json *nod, void *dst)
{
	t_cl_object	*obj;

	obj = (t_cl_object*)dst;
	obj->type = int_val(nx_json_get(nod, "type"));
	obj->texture = int_val(nx_json_get(nod, "texture"));
	obj->limited = int_val(nx_json_get(nod, "limited"));
	obj->centre = flt3_val(nx_json_get(nod, "center"));
	obj->centre1 = flt3_val(nx_json_get(nod, "center1"));
	obj->centre2 = flt3_val(nx_json_get(nod, "center2"));
	obj->dir = flt3_val(nx_json_get(nod, "direction"));
	obj->refl = flt_val(nx_json_get(nod, "reflection"));
	obj->color = flt3_val(nx_json_get(nod, "color"));
	obj->radius = flt_val(nx_json_get(nod, "radius"));
	obj->specular = int_val(nx_json_get(nod, "specular"));
	obj->transp = flt_val(nx_json_get(nod, "transparency"));
	obj->refr = flt_val(nx_json_get(nod, "refraction"));
	obj->texture_size = int_val(nx_json_get(nod, "texture size"));
	obj->normal_map = int_val(nx_json_get(nod, "normal map"));
	obj_to_normal(obj, flt_val(nx_json_get(nod, "angle")));
	return (0);
}

static int			perse_jarr(const nx_json *jarr,\
	int (*func)(const nx_json *nod, void *dst), size_t elemlen, void **dst)
{
	int i;

	i = -1;
	if (jarr->type == NX_JSON_ARRAY && jarr->length > 0)
	{
		*dst = ft_memalloc(elemlen * jarr->length);
		while (++i < jarr->length)
			if ((func(nx_json_item(jarr, i), *dst + (i * elemlen))) < 0)
				return (-1);
	}
	else if (jarr->type == NX_JSON_ARRAY && jarr->length == 0)
	{
		*dst = NULL;
		return (0);
	}
	return (i);
}

t_scene				*parse_json_scene(const nx_json *json)
{
	t_scene	*res;

	if (json == NULL || json->type != NX_JSON_OBJECT)
		return (NULL);
	if (!(res = ft_memalloc(sizeof(t_scene))))
		return (NULL);
	res->shadow = int_val(nx_json_get(json, "SHADOW"));
	res->cam_num = perse_jarr(nx_json_get(json, "CAM"), parce_cam,\
		sizeof(t_rt_cam), (void**)&res->cam);
	res->light_cnt = perse_jarr(nx_json_get(json, "LIGHTS"), parce_lgt,\
		sizeof(t_cl_light), (void**)&res->lights);
	res->obj_cnt = perse_jarr(nx_json_get(json, "OBJECTS"), parce_obj,\
		sizeof(t_cl_object), (void**)&res->objects);
	if (res->cam_num < 0 || res->light_cnt < 0 || res->obj_cnt < 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}
