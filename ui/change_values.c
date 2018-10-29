/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:50:44 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/09 17:50:45 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void	change_float_value(t_sdl *main, t_scene *sc, float *new, float *old)
{
	const char	*value;
	float		it_new;

	main->block = 1;
	it_new = 0;
	value = tinyfd_inputBox("Меняй параметры", "Value = ", "");
	if (value != NULL)
	{
		main->block = 0;
		it_new = ft_atof(value);
		*new = it_new;
		clear_ui(main);
		SDL_DestroyRenderer(main->obj_rend);
		SDL_DestroyWindow(main->obj_win);
		interface_win(main, sc);
	}
	else
	{
		main->block = 0;
		*new = *old;
	}
}

void	change_int_value(t_sdl *main, t_scene *sc, int *new, int *old)
{
	const char	*value;
	int			it_new;

	main->block = 1;
	it_new = 0;
	value = tinyfd_inputBox("Меняй параметры", "Value = ", "");
	if (value != NULL)
	{
		main->block = 0;
		it_new = ft_atoi(value);
		*new = it_new;
		clear_ui(main);
		SDL_DestroyRenderer(main->obj_rend);
		SDL_DestroyWindow(main->obj_win);
		interface_win(main, sc);
	}
	else
	{
		main->block = 0;
		*new = *old;
	}
}
