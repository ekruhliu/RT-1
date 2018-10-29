/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:46:37 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/23 14:46:37 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

static	void	wheel_up(int i, t_scene *sc)
{
	sc->lights[i].intens.x -= 0.01;
	sc->lights[i].intens.y -= 0.01;
	sc->lights[i].intens.z -= 0.01;
	if (sc->lights[i].intens.x < 0 || sc->lights[i].intens.y < 0
		|| sc->lights[i].intens.z < 0)
	{
		sc->lights[i].intens.x = 0.01;
		sc->lights[i].intens.y = 0.01;
		sc->lights[i].intens.z = 0.01;
	}
}

static	void	wheel_dn(int i, t_scene *sc)
{
	sc->lights[i].intens.x += 0.01;
	sc->lights[i].intens.y += 0.01;
	sc->lights[i].intens.z += 0.01;
	if (sc->lights[i].intens.x > 1 || sc->lights[i].intens.y > 1
		|| sc->lights[i].intens.z > 1)
	{
		sc->lights[i].intens.x = 1;
		sc->lights[i].intens.y = 1;
		sc->lights[i].intens.z = 1;
	}
}

void			light_mouse(t_sdl *main, t_scene *sc)
{
	int i;

	i = 0;
	while (i < sc->light_cnt)
	{
		if (sc->lights[i].type == 0)
		{
			if (EVENT_TYPE == SDL_MOUSEWHEEL)
			{
				if (main->event.wheel.y > 0)
					wheel_up(i, sc);
				if (main->event.wheel.y < 0)
					wheel_dn(i, sc);
			}
		}
		i++;
	}
}
