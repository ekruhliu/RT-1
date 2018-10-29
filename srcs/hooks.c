/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 08:53:36 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/22 08:53:37 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

static	void	zeror(t_sdl *main)
{
	main->old_pos_x_ch = 0;
	main->old_pos_y_ch = 0;
	main->old_pos_z_ch = 0;
	main->old_color_x_ch = 0;
	main->old_color_y_ch = 0;
	main->old_color_z_ch = 0;
	main->old_dir_x_ch = 0;
	main->old_dir_y_ch = 0;
	main->old_dir_z_ch = 0;
	main->old_trans_ch = 0;
	main->old_spec_ch = 0;
	main->old_refr_ch = 0;
	main->old_refl_ch = 0;
	main->old_tex_ch = 0;
	main->old_tex_size_ch = 0;
	main->old_normal_map_ch = 0;
}

static	void	part_one(t_sdl *main, t_scene *sc)
{
	if (main->old_pos_x_ch == 1)
		sc->objects[*(sc->closest)].centre.x = main->old_pos.x;
	if (main->old_pos_y_ch == 1)
		sc->objects[*(sc->closest)].centre.y = main->old_pos.y;
	if (main->old_pos_z_ch == 1)
		sc->objects[*(sc->closest)].centre.z = main->old_pos.z;
	if (main->old_color_x_ch == 1)
		sc->objects[*(sc->closest)].color.x = main->old_color.x;
	if (main->old_color_y_ch == 1)
		sc->objects[*(sc->closest)].color.y = main->old_color.y;
	if (main->old_color_z_ch == 1)
		sc->objects[*(sc->closest)].color.z = main->old_color.z;
	if (main->old_dir_x_ch == 1)
		sc->objects[*(sc->closest)].dir.x = main->old_dir.x;
	if (main->old_dir_y_ch == 1)
		sc->objects[*(sc->closest)].dir.y = main->old_dir.y;
}

static	void	part_two(t_sdl *main, t_scene *sc)
{
	if (main->old_dir_z_ch == 1)
		sc->objects[*(sc->closest)].dir.z = main->old_dir.z;
	if (main->old_trans_ch == 1)
		sc->objects[*(sc->closest)].transp = main->old_trans;
	if (main->old_spec_ch == 1)
		sc->objects[*(sc->closest)].specular = main->old_spec;
	if (main->old_refr_ch == 1)
		sc->objects[*(sc->closest)].refr = main->old_refr;
	if (main->old_refl_ch == 1)
		sc->objects[*(sc->closest)].refl = main->old_refl;
	if (main->old_tex_ch == 1)
		sc->objects[*(sc->closest)].texture = main->old_tex;
	if (main->old_tex_size_ch == 1)
		sc->objects[*(sc->closest)].texture_size = main->old_tex_size;
	if (main->old_normal_map_ch == 1)
		sc->objects[*(sc->closest)].normal_map = main->old_normal_map;
}

static	void	obj_win_destroyer(t_sdl *main, t_scene *sc)
{
	SDL_DestroyRenderer(main->obj_rend);
	SDL_DestroyWindow(main->obj_win);
	main->obj_win_on = 0;
	main->block = 0;
	clear_ui(main);
	part_one(main, sc);
	part_two(main, sc);
	zeror(main);
}

void			key(t_sdl *main, t_move *move, t_scene *sc, t_cldata *cl)
{
	const Uint8	*keykey;

	keykey = SDL_GetKeyboardState(NULL);
	SDL_PollEvent(&main->event);
	if (keykey[SDL_SCANCODE_ESCAPE] || main->event.type == SDL_QUIT)
	{
		if (main->obj_win_on == 1)
			obj_win_destroyer(main, sc);
		else
			main->done = 1;
	}
	ui(main, sc, cl);
	if (main->event.type == SDL_KEYDOWN)
	{
		if (main->event.key.keysym.scancode == SDL_SCANCODE_SPACE)
			sc->is_sample = !sc->is_sample;
		set_move(move, main->event.key.keysym.scancode);
	}
	if (main->event.type == SDL_KEYUP)
		remove_move(move, main->event.key.keysym.scancode);
}
