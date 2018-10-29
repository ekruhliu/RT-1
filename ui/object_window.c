/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objectWindow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 15:04:06 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/23 15:04:07 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void	object_window(t_sdl *main, t_scene *sc)
{
	if (main->block == 0 && BUTT.button == SDL_BUTTON_LEFT &&
		(BUTT.x >= 100 && BUTT.x <= 200) && (BUTT.y >= 550 && BUTT.y <= 595))
	{
		clear_ui(main);
		SDL_DestroyRenderer(main->obj_rend);
		SDL_DestroyWindow(main->obj_win);
		main->obj_win_on = 0;
		main->block = 0;
		*(sc->closest) = -1;
	}
	obj_window_part_one(main, sc);
	obj_window_part_two(main, sc);
	if (*(sc->closest) > -1)
		obj_to_normal(&sc->objects[*(sc->closest)], 0);
}
