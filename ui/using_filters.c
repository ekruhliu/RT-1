/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   using_filters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:31:10 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/09 17:31:11 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

static	void	part_one(t_sdl *main, t_scene *sc)
{
	if (main->on == 0 && BUTT.button == SDL_BUTTON_LEFT && BUTT_X &&
		(BUTT.y >= 0 && BUTT.y <= 40))
		main->on = 1;
	else if (main->on == 1 && BUTT.button == SDL_BUTTON_RIGHT && BUTT_X
		&& (BUTT.y >= 0 && BUTT.y <= 40))
	{
		zero_maker(sc);
		main->on = 0;
	}
}

static	void	part_two(t_sdl *main, t_scene *sc)
{
	if (BUTT.button == SDL_BUTTON_LEFT && BUTT_X && (BUTT.y >= 40
		&& BUTT.y <= 80))
	{
		zero_maker(sc);
		sc->filters->sepia_on = 1;
	}
	if (BUTT.button == SDL_BUTTON_LEFT && BUTT_X && (BUTT.y >= 80
		&& BUTT.y <= 120))
	{
		zero_maker(sc);
		sc->filters->b_w_on = 1;
	}
	if (BUTT.button == SDL_BUTTON_LEFT && BUTT_X && (BUTT.y >= 120
		&& BUTT.y <= 160))
	{
		zero_maker(sc);
		sc->filters->negative_on = 1;
	}
}

static	void	part_three(t_sdl *main, t_scene *sc)
{
	if (BUTT.button == SDL_BUTTON_LEFT && BUTT_X && (BUTT.y >= 160
		&& BUTT.y <= 200))
	{
		zero_maker(sc);
		sc->filters->blood_on = 1;
	}
	if (BUTT.button == SDL_BUTTON_LEFT && BUTT_X && (BUTT.y >= 200
		&& BUTT.y <= 240))
	{
		zero_maker(sc);
		sc->filters->gt_on = 1;
	}
	if (BUTT.button == SDL_BUTTON_LEFT && BUTT_X && (BUTT.y >= 240
		&& BUTT.y <= 280))
	{
		zero_maker(sc);
		sc->filters->bt_on = 1;
	}
	if (BUTT.button == SDL_BUTTON_LEFT && BUTT_X && (BUTT.y >= 280
		&& BUTT.y <= 320))
	{
		zero_maker(sc);
		sc->filters->gradient = 1;
	}
}

void			using_filters(t_sdl *main, t_scene *sc)
{
	part_one(main, sc);
	if (main->on == 1)
	{
		part_two(main, sc);
		part_three(main, sc);
	}
}
