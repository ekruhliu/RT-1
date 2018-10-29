/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_cl_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 19:10:49 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/24 19:10:50 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

static	void	part_one(t_cldata *cl, t_scene *sc)
{
	cl->inp = cl_mem_write(cl, cl->inp, sizeof(t_cl_object) * sc->obj_cnt,\
		sc->objects);
	cl->err = SET_KERNEL(cl->kernel, 0, sizeof(cl_mem), &cl->inp);
	cl->lights = cl_mem_write(cl, cl->lights, sizeof(t_cl_object)\
		* sc->light_cnt, sc->lights);
	cl->filters = cl_mem_write(cl, cl->filters, sizeof(t_filters_on),\
		sc->filters);
	cl->closest = cl_mem_write(cl, cl->closest, sizeof(int), sc->closest);
	cl->err |= SET_KERNEL(cl->kernel, 17, sizeof(cl_mem), &cl->closest);
	cl->err |= SET_KERNEL(cl->kernel, 18, sizeof(cl_mem), &cl->filters);
	cl->err |= SET_KERNEL(cl->kernel, 4, sizeof(cl_mem), &cl->lights);
	cl->err |= SET_KERNEL(cl->kernel, 19, sizeof(int), &sc->mouse_x);
	cl->err |= SET_KERNEL(cl->kernel, 20, sizeof(int), &sc->mouse_y);
	cl->err = SET_KERNEL(cl->kernel, 3, sizeof(cl_float3),\
		&sc->cam->center);
	cl->rotate_matrix = cl_mem_write(cl, cl->rotate_matrix, sizeof(cl_float3)\
		* 3, sc->cam->transp_rotate_matrix);
	cl->err |= SET_KERNEL(cl->kernel, 7, sizeof(cl_mem),\
		&cl->rotate_matrix);
	cl->err |= SET_KERNEL(cl->kernel, 8, sizeof(int), &sc->width);
	cl->err |= SET_KERNEL(cl->kernel, 9, sizeof(int), &sc->height);
	if (sc->is_sample)
		cl->err |= SET_KERNEL(cl->kernel, 1, sizeof(cl_mem), &cl->sample_out);
	else
		cl->err |= SET_KERNEL(cl->kernel, 1, sizeof(cl_mem), &cl->out);
}

static	void	part_two(t_cldata *cl, t_scene *sc)
{
	cl->earth = cl_mem_write(cl, cl->earth, sizeof(int) * (512 * 512),\
		sc->earth);
	cl->iron = cl_mem_write(cl, cl->iron, sizeof(int) * (512 * 512), sc->iron);
	cl->iron_normal = cl_mem_write(cl, cl->iron_normal, sizeof(int)\
		* (512 * 512), sc->iron_normal);
	cl->earth_normal = cl_mem_write(cl, cl->earth_normal, sizeof(int)\
		* (512 * 512), sc->earth_normal);
	cl->stone = cl_mem_write(cl, cl->stone, sizeof(int) * (512 * 512),\
		sc->stone);
	cl->stone_normal = cl_mem_write(cl, cl->stone_normal, sizeof(int)\
		* (512 * 512), sc->stone_normal);
	cl->perlin = cl_mem_write(cl, cl->perlin, sizeof(int) * (512 * 512),\
		sc->perlin);
	cl->sun = cl_mem_write(cl, cl->sun, sizeof(int) * (512 * 512),\
		sc->sun);
	cl->mars = cl_mem_write(cl, cl->mars, sizeof(int) * (512 * 512),\
		sc->mars);
	cl->merc = cl_mem_write(cl, cl->merc, sizeof(int) * (512 * 512),\
		sc->merc);
	cl->neptune = cl_mem_write(cl, cl->neptune, sizeof(int) * (512 * 512),\
		sc->neptune);
}

static	void	part_three(t_cldata *cl, t_scene *sc)
{
	cl->err = 0;
	cl->err |= SET_KERNEL(cl->kernel, 1, sizeof(cl_mem), &cl->out);
	cl->err |= SET_KERNEL(cl->kernel, 2, sizeof(int), &cl->cnt);
	cl->err |= SET_KERNEL(cl->kernel, 3, sizeof(cl_float3),\
		&sc->cam->center);
	cl->err |= SET_KERNEL(cl->kernel, 5, sizeof(int), &sc->light_cnt);
	cl->err |= SET_KERNEL(cl->kernel, 6, sizeof(int), &sc->shadow);
	cl->err |= SET_KERNEL(cl->kernel, 7, sizeof(cl_mem),\
		&cl->rotate_matrix);
	cl->err |= SET_KERNEL(cl->kernel, 8, sizeof(int), &sc->width);
	cl->err |= SET_KERNEL(cl->kernel, 9, sizeof(int), &sc->height);
	cl->err |= SET_KERNEL(cl->kernel, 10, sizeof(cl_mem), &cl->earth);
	cl->err |= SET_KERNEL(cl->kernel, 11, sizeof(cl_mem),\
		&cl->earth_normal);
	cl->err |= SET_KERNEL(cl->kernel, 12, sizeof(cl_mem), &cl->iron);
	cl->err |= SET_KERNEL(cl->kernel, 13, sizeof(cl_mem), &cl->iron_normal);
	cl->err |= SET_KERNEL(cl->kernel, 14, sizeof(cl_mem), &cl->stone);
	cl->err |= SET_KERNEL(cl->kernel, 15, sizeof(cl_mem),\
		&cl->stone_normal);
	cl->err |= SET_KERNEL(cl->kernel, 16, sizeof(cl_mem), &cl->perlin);
	cl->err |= SET_KERNEL(cl->kernel, 17, sizeof(cl_mem), &cl->closest);
	cl->err |= clSetKernelArg(cl->kernel, 21, sizeof(cl_mem), &cl->sun);
	cl->err |= clSetKernelArg(cl->kernel, 22, sizeof(cl_mem), &cl->merc);
	cl->err |= clSetKernelArg(cl->kernel, 23, sizeof(cl_mem), &cl->mars);
	cl->err |= clSetKernelArg(cl->kernel, 24, sizeof(cl_mem), &cl->neptune);
}

void			write_cl_data(t_cldata *cl, t_scene *sc, int push)
{
	part_one(cl, sc);
	if (push)
	{
		if (cl->err != MCL_OK)
			ocl_error(9);
		return ;
	}
	part_two(cl, sc);
	part_three(cl, sc);
	if (cl->err != MCL_OK)
		ocl_error(9);
}
