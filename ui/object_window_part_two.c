/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectWindowPartTwo.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:07:20 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/23 15:07:21 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

static	void	part_one(t_sdl *main, t_scene *sc)
{
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 300 && BUTT.y <= 330))
	{
		main->data_type = 4;
		change_float_value(main, sc, &sc->objects[*(sc->closest)].transp,
			&main->old_trans);
		main->old_trans_ch = 1;
	}
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 331 && BUTT.y <= 360))
	{
		main->data_type = 5;
		change_int_value(main, sc, &sc->objects[*(sc->closest)].specular,
			&main->old_spec);
		main->old_spec_ch = 1;
	}
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 361 && BUTT.y <= 390))
	{
		main->data_type = 6;
		change_float_value(main, sc, &sc->objects[*(sc->closest)].refr,
			&main->old_refr);
		main->old_refr_ch = 1;
	}
}

static	void	part_two(t_sdl *main, t_scene *sc)
{
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 391 && BUTT.y <= 420))
	{
		main->data_type = 7;
		change_float_value(main, sc, &sc->objects[*(sc->closest)].refl,
			&main->old_refl);
		main->old_refl_ch = 1;
	}
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 430 && BUTT.y <= 460))
	{
		main->data_type = 8;
		change_int_value(main, sc, &sc->objects[*(sc->closest)].texture,
			&main->old_tex);
		main->old_tex_ch = 1;
	}
}

static	void	part_three(t_sdl *main, t_scene *sc)
{
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 461 && BUTT.y <= 490))
	{
		main->data_type = 9;
		change_int_value(main, sc, &sc->objects[*(sc->closest)].texture_size,
			&main->old_tex_size);
		main->old_tex_size_ch = 1;
	}
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 10 && BUTT.x <= 300) && (BUTT.y >= 491 && BUTT.y <= 520))
	{
		main->data_type = 10;
		change_int_value(main, sc, &sc->objects[*(sc->closest)].normal_map,
			&main->old_normal_map);
		main->old_normal_map_ch = 1;
	}
}

void			obj_window_part_two(t_sdl *main, t_scene *sc)
{
	part_one(main, sc);
	part_two(main, sc);
	part_three(main, sc);
}
