/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:39:19 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/09 17:39:20 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

static	void	copy_ui_on_render_part_one(t_sdl *main)
{
	UI_T->T_R.x = 10;
	UI_T->T_R.y = 0;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_x, NULL, &UI_T->T_R);
	UI_T->T_R.y += 30;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_y, NULL, &UI_T->T_R);
	UI_T->T_R.y += 30;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_z, NULL, &UI_T->T_R);
	UI_T->T_R.y += 40;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_red, NULL, &UI_T->T_R);
	UI_T->T_R.y += 30;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_green, NULL, &UI_T->T_R);
	UI_T->T_R.y += 30;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_blue, NULL, &UI_T->T_R);
	UI_T->T_R.y += 40;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_dir_x, NULL, &UI_T->T_R);
	UI_T->T_R.y += 30;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_dir_y, NULL, &UI_T->T_R);
}

static	void	copy_ui_on_render_part_two(t_sdl *main)
{
	UI_T->T_R.y += 30;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_dir_z, NULL, &UI_T->T_R);
	UI_T->T_R.y += 40;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_trans, NULL, &UI_T->T_R);
	UI_T->T_R.y += 30;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_spec, NULL, &UI_T->T_R);
	UI_T->T_R.y += 30;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_refr, NULL, &UI_T->T_R);
	UI_T->T_R.y += 30;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_brill, NULL, &UI_T->T_R);
	UI_T->T_R.y += 40;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_tex, NULL, &UI_T->T_R);
	UI_T->T_R.y += 30;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_tex_size, NULL, &UI_T->T_R);
	UI_T->T_R.y += 30;
	SDL_RenderCopy(main->obj_rend, UI_T->text_tex_norm_map, NULL, &UI_T->T_R);
	SDL_RenderCopy(main->obj_rend, UI->accept_button_tex, NULL,\
		&UI->accept_rect);
}

void			interface_win(t_sdl *main, t_scene *sc)
{
	UI = ft_memalloc(sizeof(t_ui));
	init_ui(main);
	init_str(main, sc);
	init_surfs(main);
	init_textures(main);
	query_textures(main);
	copy_ui_on_render_part_one(main);
	copy_ui_on_render_part_two(main);
	SDL_RenderPresent(main->obj_rend);
}
