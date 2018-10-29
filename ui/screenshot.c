/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:43:20 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/09/06 14:43:20 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void	screenshot(t_sdl *main, char *number, char *res)
{
	const Uint32	f = SDL_PIXELFORMAT_ARGB8888;
	SDL_Surface		*surface;

	surface = SDL_CreateRGBSurfaceWithFormat(0, 1000, 1000, 32, f);
	SDL_RenderReadPixels(main->rend, NULL, f, surface->pixels, surface->pitch);
	if (main->num_of_scr_shot == 0)
	{
		IMG_SavePNG(surface, "myscreenshot.png");
		main->num_of_scr_shot++;
	}
	else
	{
		number = ft_itoa(main->num_of_scr_shot);
		res = ft_strjoin("myscreenshot_", number);
		free(number);
		number = ft_strjoin(res, ".png");
		free(res);
		IMG_SavePNG(surface, number);
		free(number);
		main->num_of_scr_shot++;
	}
	SDL_FreeSurface(surface);
}
