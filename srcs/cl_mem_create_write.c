/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_mem_create_write.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:42:04 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/25 16:42:05 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

cl_mem		cl_mem_create(t_cldata *cl, cl_mem_flags rw, size_t size)
{
	cl_mem res;

	res = clCreateBuffer(cl->cntxt, rw, size, NULL, NULL);
	if (!res)
		ocl_error(7);
	return (res);
}

cl_mem		cl_mem_write(t_cldata *cl, cl_mem mem, size_t size, void *dat)
{
	if (dat != NULL)
		if (clEnqueueWriteBuffer(cl->commands, mem, CL_TRUE, 0, size,\
			dat, 0, NULL, NULL) != MCL_OK)
			ocl_error(8);
	return (mem);
}
