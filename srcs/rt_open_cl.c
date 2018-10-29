/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_open_cl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 21:36:24 by akokoshk          #+#    #+#             */
/*   Updated: 2018/08/27 22:09:18 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

t_cldata	*ocl_init(char *progstr, char *kernel, size_t size, size_t cnt)
{
	t_cldata	*r;

	if (!(r = malloc(sizeof(t_cldata))))
		return (NULL);
	r->cnt = cnt;
	r->bytlen = size;
	if (clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 1, &r->dev_id, NULL) != MCL_OK)
		ocl_error(1);
	if (!(r->cntxt = clCreateContext(0, 1, &r->dev_id, NULL, NULL, &r->err)))
		ocl_error(2);
	if (!(r->commands = clCreateCommandQueue(r->cntxt, r->dev_id, 0, &r->err)))
		ocl_error(3);
	r->src = progstr;
	if (!(r->program = clCreateProgramWithSource(r->cntxt, 1,
		(const char**)&r->src, NULL, &r->err)))
		ocl_error(4);
	if (clBuildProgram(r->program, 0, NULL, NULL, NULL, NULL) != MCL_OK)
		ocl_error(5);
	if (!(r->kernel = clCreateKernel(r->program, kernel, &r->err)) ||
		r->err != MCL_OK)
		ocl_error(6);
	return (r);
}

void		create_cl_data(t_cldata *cl, t_scene *scene)
{
	cl->inp = cl_mem_create(cl, MCL_RDO, sizeof(t_cl_object) *\
		scene->obj_cnt);
	cl->lights = cl_mem_create(cl, MCL_RDO, sizeof(t_cl_object) *\
		scene->light_cnt);
	cl->filters = cl_mem_create(cl, MCL_RDO, sizeof(t_filters_on));
	cl->out = cl_mem_create(cl, MCL_WRO, sizeof(int) * scene->width *\
		scene->height);
	cl->sample_out = cl_mem_create(cl, MCL_WRO, sizeof(int) * 4 *\
		scene->width * scene->height);
	cl->closest = cl_mem_create(cl, MCL_WRO, sizeof(int));
	cl->rotate_matrix = cl_mem_create(cl, MCL_RDO, sizeof(cl_float3) * 3);
	cl->earth = cl_mem_create(cl, MCL_RDO, sizeof(int) * (512 * 512));
	cl->iron = cl_mem_create(cl, MCL_RDO, sizeof(int) * (512 * 512));
	cl->iron_normal = cl_mem_create(cl, MCL_RDO, sizeof(int) * (512 * 512));
	cl->earth_normal = cl_mem_create(cl, MCL_RDO, sizeof(int) * (512 * 512));
	cl->stone = cl_mem_create(cl, MCL_RDO, sizeof(int) * (512 * 512));
	cl->stone_normal = cl_mem_create(cl, MCL_RDO, sizeof(int) * (512 * 512));
	cl->perlin = cl_mem_create(cl, MCL_RDO, sizeof(int) * (512 * 512));
	cl->sun = cl_mem_create(cl, MCL_RDO, sizeof(int) * (512 * 512));
	cl->mars = cl_mem_create(cl, MCL_RDO, sizeof(int) * (512 * 512));
	cl->merc = cl_mem_create(cl, MCL_RDO, sizeof(int) * (512 * 512));
	cl->neptune = cl_mem_create(cl, MCL_RDO, sizeof(int) * (512 * 512));
}

void		execute_and_read(t_cldata *cl, size_t res_blen, void *res,\
	t_scene *sc)
{
	size_t dim_size[2];

	dim_size[0] = sc->width;
	dim_size[1] = sc->height;
	if (clEnqueueNDRangeKernel(cl->commands, cl->kernel, 2, NULL, dim_size,
		NULL, 0, NULL, NULL))
		ocl_error(10);
	if (cl->err != MCL_OK)
		ocl_error(5);
	clFinish(cl->commands);
	if (sc->is_sample)
		cl->err = clEnqueueReadBuffer(cl->commands, cl->sample_out, CL_TRUE,\
			0, res_blen, res, 0, NULL, NULL);
	else
		cl->err = clEnqueueReadBuffer(cl->commands, cl->out, CL_TRUE, 0,\
			res_blen, res, 0, NULL, NULL);
	cl->err = clEnqueueReadBuffer(cl->commands, cl->closest, CL_TRUE, 0,
		sizeof(int), sc->closest, 0, NULL, NULL);
	if (cl->err != MCL_OK)
		ocl_error(11);
}

void		clear_cl(t_cldata *cl)
{
	clReleaseContext(cl->cntxt);
	clReleaseKernel(cl->kernel);
	free(cl);
}
