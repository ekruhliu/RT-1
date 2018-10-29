/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_selection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:24:58 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/09 17:24:58 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

static	void	create_old(t_sdl *main, t_scene *sc)
{
	main->old_pos = sc->objects[*(sc->closest)].centre;
	main->old_color = sc->objects[*(sc->closest)].color;
	main->old_dir = sc->objects[*(sc->closest)].dir;
	main->old_trans = sc->objects[*(sc->closest)].transp;
	main->old_spec = sc->objects[*(sc->closest)].specular;
	main->old_refr = sc->objects[*(sc->closest)].refr;
	main->old_refl = sc->objects[*(sc->closest)].refl;
	main->old_tex = sc->objects[*(sc->closest)].texture;
	main->old_tex_size = sc->objects[*(sc->closest)].texture_size;
	main->old_normal_map = sc->objects[*(sc->closest)].normal_map;
}

static	void	events(t_scene *sc, t_sdl *main, t_cldata *cl)
{
	if (main->obj_win_on == 0)
	{
		sc->mouse_x = BUTT.x;
		sc->mouse_y = BUTT.y;
	}
	write_cl_data(cl, sc, 1);
	execute_and_read(cl, sizeof(int) * sc->width * sc->height,\
		main->sample_data, sc);
	if (*(sc->closest) > -1)
	{
		create_old(main, sc);
		interface_win(main, sc);
		sc->mouse_y = -1;
		sc->mouse_x = -1;
	}
}

void			figure_selection(t_sdl *main, t_scene *sc, t_cldata *cl)
{
	if (main->on == 0 && !(BUTT_X && (BUTT.y >= 0 && BUTT.y <= 40)) &&
		!((BUTT.x >= W - 75 && BUTT.x <= W) && (BUTT.y >= 0 && BUTT.y <= 75)))
		events(sc, main, cl);
	else if (main->on == 1 && !(BUTT_X && (BUTT.y >= 0 && BUTT.y <= 40)) &&
		!((BUTT.x >= W - 75 && BUTT.x <= W) && (BUTT.y >= 0 && BUTT.y <= 75)) &&
		!(BUTT_X && (BUTT.y >= 40 && BUTT.y <= 80)) && !(BUTT_X &&
			(BUTT.y >= 80 && BUTT.y <= 120)) && !(BUTT_X && (BUTT.y >= 120
				&& BUTT.y <= 160)) && !(BUTT_X && (BUTT.y >= 160
				&& BUTT.y <= 200)) && !(BUTT_X && (BUTT.y >= 200
				&& BUTT.y <= 240)) && !(BUTT_X && (BUTT.y >= 240
				&& BUTT.y <= 280)) && !(BUTT_X && (BUTT.y >= 280
				&& BUTT.y <= 320)))
		events(sc, main, cl);
}
