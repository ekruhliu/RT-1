/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 08:53:50 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/22 08:53:51 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void	valid_obj(t_cl_object *obj)
{
	int	cond;

	cond = obj->refl < 0 || obj->transp < 0 || obj->refr < 0 || obj->radius < 0;
	cond = cond || (obj->transp + obj->refl > 1);
	cond = cond || obj->color.x < 0 \
	|| obj->color.y < 0 || obj->color.z < 0;
	cond = cond || obj->color.x > 0xff \
	|| obj->color.y > 0xff || obj->color.z > 0xff;
	if (obj->limited && obj->type == PLANE)
		cond = cond || !is_trinagle(&obj->centre, &obj->centre1, &obj->centre2);
	if (cond)
	{
		ft_putendl("ERROR OBJECT!");
		exit(0);
	}
}

void	valid_light(t_cl_light *light)
{
	int cond;

	cond = light->intens.x > 1 || light->intens.y > 1 \
	|| light->intens.z > 1;
	cond = cond || light->intens.x < 0 || light->intens.y < 0 \
	|| light->intens.z < 0;
	if (light->type == PARAL || light->type == DIRECT)
		cond = cond || (light->dir.x == 0 && \
		light->dir.y == 0 && light->dir.z == 0);
	if (cond)
	{
		ft_putendl("ERROR LIGHT!");
		exit(0);
	}
}
