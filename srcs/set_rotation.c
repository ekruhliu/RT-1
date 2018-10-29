/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:48:16 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/23 16:48:17 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void			set_rotation(t_move *move, cl_float3 *transp_matrix)
{
	static float	alpha;
	static float	beta;
	static float	gama;
	cl_float3		buff[3];

	move->f_rot_x ? alpha += 0.0174 : 0;
	move->b_rot_x ? alpha -= 0.0174 : 0;
	move->f_rot_y ? beta += 0.0174 : 0;
	move->b_rot_y ? beta -= 0.0174 : 0;
	move->f_rot_z ? gama += 0.0174 : 0;
	move->b_rot_z ? gama -= 0.0174 : 0;
	if (move->f_rot_x || move->b_rot_x || move->f_rot_y || move->f_rot_z ||
		move->b_rot_y || move->b_rot_z)
	{
		set_rotate_x(transp_matrix, alpha);
		set_rotate_y(buff, beta);
		mult_to_first_second(transp_matrix, buff);
		set_rotate_z(buff, gama);
		mult_to_first_second(transp_matrix, buff);
		transp_local(transp_matrix);
	}
}
