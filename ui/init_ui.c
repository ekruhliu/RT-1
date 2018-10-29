/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:27:18 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/10 18:27:18 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void			init_ui(t_sdl *main)
{
	Uint32		render_flags;

	render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	UI_T = malloc(sizeof(t_ui_text));
	main->obj_win_on = 1;
	main->obj_win = SDL_CreateWindow("Object Params", 1780, 400, 300, 600, 0);
	main->obj_rend = SDL_CreateRenderer(main->obj_win, -1, render_flags);
	SDL_SetRenderDrawColor(main->obj_rend, 107, 48, 184, 255);
	SDL_RenderClear(main->obj_rend);
	UI->accept_button_surf = IMG_Load("./ui_buttons/button_accept.png");
	UI->accept_button_tex = TEX_FMR_SRF(main->obj_rend, UI->accept_button_surf);
	SDL_FreeSurface(UI->accept_button_surf);
	UI->accept_rect.h = 45;
	UI->accept_rect.w = 100;
	UI->accept_rect.y = 600 - 50;
	UI->accept_rect.x = 100;
	UI_T->font = TTF_OpenFont("./ui_buttons/test.ttf", 22);
}

void			init_str(t_sdl *main, t_scene *sc)
{
	UI_T->stroka1 = ft_strjoin("X = ", ft_ftoa(THIS_FIG.centre.x));
	UI_T->stroka2 = ft_strjoin("Y = ", ft_ftoa(THIS_FIG.centre.y));
	UI_T->stroka3 = ft_strjoin("Z = ", ft_ftoa(THIS_FIG.centre.z));
	UI_T->stroka4 = ft_strjoin("R = ", ft_itoa((int)THIS_FIG.color.x));
	UI_T->stroka5 = ft_strjoin("G = ", ft_itoa((int)THIS_FIG.color.y));
	UI_T->stroka6 = ft_strjoin("B = ", ft_itoa((int)THIS_FIG.color.z));
	UI_T->stroka7 = ft_strjoin("DIR_X = ", ft_ftoa(THIS_FIG.dir.x));
	UI_T->stroka8 = ft_strjoin("DIR_Y = ", ft_ftoa(THIS_FIG.dir.y));
	UI_T->stroka9 = ft_strjoin("DIR_Z = ", ft_ftoa(THIS_FIG.dir.z));
	UI_T->stroka10 = ft_strjoin("Trans = ", ft_ftoa(THIS_FIG.transp));
	UI_T->stroka11 = ft_strjoin("Spec = ", ft_itoa(THIS_FIG.specular));
	UI_T->stroka12 = ft_strjoin("Refr = ", ft_ftoa(THIS_FIG.refr));
	UI_T->stroka13 = ft_strjoin("Refl = ", ft_ftoa(THIS_FIG.refl));
	UI_T->stroka14 = ft_strjoin("Texture = ", ft_itoa(THIS_FIG.texture));
	UI_T->stroka15 = ft_strjoin("Tex size = ", ft_itoa(THIS_FIG.texture_size));
	UI_T->stroka16 = ft_strjoin("Normal map = ", ft_itoa(THIS_FIG.normal_map));
}

void			init_surfs(t_sdl *main)
{
	const SDL_Color	color = {0, 0, 0, 255};

	UI_T->text_surf_x = RENDER_TEXT(UI_T->font, UI_T->stroka1, color);
	UI_T->text_surf_y = RENDER_TEXT(UI_T->font, UI_T->stroka2, color);
	UI_T->text_surf_z = RENDER_TEXT(UI_T->font, UI_T->stroka3, color);
	UI_T->text_surf_red = RENDER_TEXT(UI_T->font, UI_T->stroka4, color);
	UI_T->text_surf_green = RENDER_TEXT(UI_T->font, UI_T->stroka5, color);
	UI_T->text_surf_blue = RENDER_TEXT(UI_T->font, UI_T->stroka6, color);
	UI_T->text_surf_dir_x = RENDER_TEXT(UI_T->font, UI_T->stroka7, color);
	UI_T->text_surf_dir_y = RENDER_TEXT(UI_T->font, UI_T->stroka8, color);
	UI_T->text_surf_dir_z = RENDER_TEXT(UI_T->font, UI_T->stroka9, color);
	UI_T->text_surf_trans = RENDER_TEXT(UI_T->font, UI_T->stroka10, color);
	UI_T->text_surf_spec = RENDER_TEXT(UI_T->font, UI_T->stroka11, color);
	UI_T->text_surf_refr = RENDER_TEXT(UI_T->font, UI_T->stroka12, color);
	UI_T->text_surf_brill = RENDER_TEXT(UI_T->font, UI_T->stroka13, color);
	UI_T->text_surf_tex = RENDER_TEXT(UI_T->font, UI_T->stroka14, color);
	UI_T->text_surf_tex_size = RENDER_TEXT(UI_T->font, UI_T->stroka15, color);
	UI_T->text_surf_norm_map = RENDER_TEXT(UI_T->font, UI_T->stroka16, color);
}

static	void	part_one(t_sdl *main)
{
	UI_T->text_tex_x = TEX_FMR_SRF(main->obj_rend, UI_T->text_surf_x);
	SDL_FreeSurface(UI_T->text_surf_x);
	UI_T->text_tex_y = TEX_FMR_SRF(main->obj_rend, UI_T->text_surf_y);
	SDL_FreeSurface(UI_T->text_surf_y);
	UI_T->text_tex_z = TEX_FMR_SRF(main->obj_rend, UI_T->text_surf_z);
	SDL_FreeSurface(UI_T->text_surf_z);
	UI_T->text_tex_red = TEX_FMR_SRF(main->obj_rend, UI_T->text_surf_red);
	SDL_FreeSurface(UI_T->text_surf_red);
	UI_T->text_tex_green = TEX_FMR_SRF(main->obj_rend, UI_T->text_surf_green);
	SDL_FreeSurface(UI_T->text_surf_green);
	UI_T->text_tex_blue = TEX_FMR_SRF(main->obj_rend, UI_T->text_surf_blue);
	SDL_FreeSurface(UI_T->text_surf_blue);
	UI_T->text_tex_dir_x = TEX_FMR_SRF(main->obj_rend, UI_T->text_surf_dir_x);
	SDL_FreeSurface(UI_T->text_surf_dir_x);
	UI_T->text_tex_dir_y = TEX_FMR_SRF(main->obj_rend, UI_T->text_surf_dir_y);
	SDL_FreeSurface(UI_T->text_surf_dir_y);
}

void			init_textures(t_sdl *main)
{
	part_one(main);
	UI_T->text_tex_dir_z = TEX_FMR_SRF(main->obj_rend, UI_T->text_surf_dir_z);
	SDL_FreeSurface(UI_T->text_surf_dir_z);
	UI_T->text_tex_trans = TEX_FMR_SRF(main->obj_rend, UI_T->text_surf_trans);
	SDL_FreeSurface(UI_T->text_surf_trans);
	UI_T->text_tex_spec = TEX_FMR_SRF(main->obj_rend, UI_T->text_surf_spec);
	SDL_FreeSurface(UI_T->text_surf_spec);
	UI_T->text_tex_refr = TEX_FMR_SRF(main->obj_rend, UI_T->text_surf_refr);
	SDL_FreeSurface(UI_T->text_surf_refr);
	UI_T->text_tex_brill = TEX_FMR_SRF(main->obj_rend, UI_T->text_surf_brill);
	SDL_FreeSurface(UI_T->text_surf_brill);
	UI_T->text_tex_tex = TEX_FMR_SRF(main->obj_rend, UI_T->text_surf_tex);
	SDL_FreeSurface(UI_T->text_surf_tex);
	UI_T->text_tex_tex_size = TEX_FMR_SRF(main->obj_rend,\
		UI_T->text_surf_tex_size);
	SDL_FreeSurface(UI_T->text_surf_tex_size);
	UI_T->text_tex_norm_map = TEX_FMR_SRF(main->obj_rend,\
		UI_T->text_surf_norm_map);
	SDL_FreeSurface(UI_T->text_surf_norm_map);
}
