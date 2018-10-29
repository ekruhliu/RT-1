/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:24:19 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/26 18:24:20 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void	frames(t_sdl *sdl)
{
	Uint32				render_flags;
	TTF_Font			*font;
	char				*stroka;
	SDL_Surface			*fps_surf;
	const SDL_Color		color = {0, 255, 0, 0};

	render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	font = TTF_OpenFont("./ui_buttons/test.ttf", 25);
	sdl->frames++;
	sdl->time_passed = clock() - sdl->begin;
	if ((float)(sdl->time_passed - sdl->start_time) / CLOCKS_PER_SEC > 0.25\
		&& sdl->frames > 10)
	{
		sdl->fps = (float)sdl->frames * CLOCKS_PER_SEC\
		/ (float)(sdl->time_passed - sdl->start_time);
		sdl->start_time = sdl->time_passed;
		sdl->frames = 0;
		stroka = ft_itoa((int)sdl->fps);
		fps_surf = TTF_RenderText_Solid(font, stroka, color);
		sdl->fps_tex = SDL_CreateTextureFromSurface(sdl->rend, fps_surf);
		SDL_FreeSurface(fps_surf);
		SDL_QueryTexture(sdl->fps_tex, NULL, NULL, &sdl->fps_r.w,\
			&sdl->fps_r.h);
	}
}
