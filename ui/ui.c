/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:01:17 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/09 17:01:18 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void	ui(t_sdl *main, t_scene *sc, t_cldata *cl)
{
	light_mouse(main, sc);
	if (main->event.type == SDL_MOUSEBUTTONDOWN)
	{
		if (main->obj_win_on == 0)
		{
			figure_selection(main, sc, cl);
			if (BUTT.button == SDL_BUTTON_LEFT && (BUTT.x >= W - 75 &&
				BUTT.x <= W) && (BUTT.y >= 0 && BUTT.y <= 75))
				screenshot(main, NULL, NULL);
			using_filters(main, sc);
		}
		else
			object_window(main, sc);
	}
}
