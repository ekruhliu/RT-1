/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:51:57 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/23 16:51:58 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void				move_cam(t_move *move, cl_float3 *cam, cl_float3 *t_mat)
{
	move->f_dir.x = 0;
	move->f_dir.y = 0;
	move->f_dir.z = 1;
	move->l_dir.x = 1;
	move->l_dir.y = 0;
	move->l_dir.z = 0;
	move->u_dir.x = 0;
	move->u_dir.y = 1;
	move->u_dir.z = 0;
	rotate_local(&move->f_dir, t_mat);
	rotate_local(&move->l_dir, t_mat);
	rotate_local(&move->u_dir, t_mat);
	if (move->left)
		minus_to_first(cam, &move->l_dir);
	if (move->right)
		add_to_first(cam, &move->l_dir);
	if (move->up)
		add_to_first(cam, &move->u_dir);
	if (move->down)
		minus_to_first(cam, &move->u_dir);
	if (move->forward)
		add_to_first(cam, &move->f_dir);
	if (move->backward)
		minus_to_first(cam, &move->f_dir);
}

void				set_move(t_move *move, int scancode)
{
	if (scancode == SDL_SCANCODE_UP)
		move->forward = 1;
	if (scancode == SDL_SCANCODE_DOWN)
		move->backward = 1;
	if (scancode == SDL_SCANCODE_RSHIFT)
		move->up = 1;
	if (scancode == SDL_SCANCODE_RCTRL)
		move->down = 1;
	if (scancode == SDL_SCANCODE_LEFT)
		move->left = 1;
	if (scancode == SDL_SCANCODE_RIGHT)
		move->right = 1;
	if (scancode == SDL_SCANCODE_W)
		move->f_rot_x = 1;
	if (scancode == SDL_SCANCODE_S)
		move->b_rot_x = 1;
	if (scancode == SDL_SCANCODE_E)
		move->f_rot_z = 1;
	if (scancode == SDL_SCANCODE_Q)
		move->b_rot_z = 1;
	if (scancode == SDL_SCANCODE_A)
		move->f_rot_y = 1;
	if (scancode == SDL_SCANCODE_D)
		move->b_rot_y = 1;
}

void				remove_move(t_move *move, int scancode)
{
	if (scancode == SDL_SCANCODE_UP)
		move->forward = 0;
	if (scancode == SDL_SCANCODE_DOWN)
		move->backward = 0;
	if (scancode == SDL_SCANCODE_RSHIFT)
		move->up = 0;
	if (scancode == SDL_SCANCODE_RCTRL)
		move->down = 0;
	if (scancode == SDL_SCANCODE_LEFT)
		move->left = 0;
	if (scancode == SDL_SCANCODE_RIGHT)
		move->right = 0;
	if (scancode == SDL_SCANCODE_W)
		move->f_rot_x = 0;
	if (scancode == SDL_SCANCODE_S)
		move->b_rot_x = 0;
	if (scancode == SDL_SCANCODE_E)
		move->f_rot_z = 0;
	if (scancode == SDL_SCANCODE_Q)
		move->b_rot_z = 0;
	if (scancode == SDL_SCANCODE_A)
		move->f_rot_y = 0;
	if (scancode == SDL_SCANCODE_D)
		move->b_rot_y = 0;
}
