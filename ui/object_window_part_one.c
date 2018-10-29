/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectWindowPartOne.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:07:16 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/23 15:07:16 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

static	void	part_one(t_sdl *main, t_scene *sc)
{
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 0 && BUTT.y <= 30))
	{
		main->data_type = 1;
		change_float_value(main, sc, &sc->objects[*(sc->closest)].centre.x,
			&main->old_pos.x);
		main->old_pos_x_ch = 1;
	}
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 31 && BUTT.y <= 60))
	{
		main->data_type = 1;
		change_float_value(main, sc, &sc->objects[*(sc->closest)].centre.y,
			&main->old_pos.y);
		main->old_pos_y_ch = 1;
	}
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 61 && BUTT.y <= 90))
	{
		main->data_type = 1;
		change_float_value(main, sc, &sc->objects[*(sc->closest)].centre.z,
			&main->old_pos.z);
		main->old_pos_y_ch = 1;
	}
}

static	void	part_two(t_sdl *main, t_scene *sc)
{
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 100 && BUTT.y <= 130))
	{
		main->data_type = 2;
		change_float_value(main, sc, &sc->objects[*(sc->closest)].color.x,
			&main->old_color.x);
		main->old_color_x_ch = 1;
	}
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 131 && BUTT.y <= 160))
	{
		main->data_type = 2;
		change_float_value(main, sc, &sc->objects[*(sc->closest)].color.y,
			&main->old_color.y);
		main->old_color_y_ch = 1;
	}
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 161 && BUTT.y <= 190))
	{
		main->data_type = 2;
		change_float_value(main, sc, &sc->objects[*(sc->closest)].color.z,
			&main->old_color.z);
		main->old_color_z_ch = 1;
	}
}

static	void	part_three(t_sdl *main, t_scene *sc)
{
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 200 && BUTT.y <= 230))
	{
		main->data_type = 3;
		change_float_value(main, sc, &sc->objects[*(sc->closest)].dir.x,
			&main->old_dir.x);
		main->old_dir_x_ch = 1;
	}
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 231 && BUTT.y <= 260))
	{
		main->data_type = 3;
		change_float_value(main, sc, &sc->objects[*(sc->closest)].dir.y,
			&main->old_dir.y);
		main->old_dir_y_ch = 1;
	}
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 261 && BUTT.y <= 290))
	{
		main->data_type = 3;
		change_float_value(main, sc, &sc->objects[*(sc->closest)].dir.z,
			&main->old_dir.z);
		main->old_dir_z_ch = 1;
	}
}

void			obj_window_part_one(t_sdl *main, t_scene *sc)
{
	part_one(main, sc);
	part_two(main, sc);
	part_three(main, sc);
}
