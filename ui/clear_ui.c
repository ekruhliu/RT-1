/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_ui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:23:42 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/10 18:23:42 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

static	void	part_one(t_sdl *main)
{
	SDL_DestroyTexture(UI_T->text_tex_x);
	SDL_DestroyTexture(UI_T->text_tex_y);
	SDL_DestroyTexture(UI_T->text_tex_z);
	SDL_DestroyTexture(UI_T->text_tex_red);
	SDL_DestroyTexture(UI_T->text_tex_green);
	SDL_DestroyTexture(UI_T->text_tex_blue);
	SDL_DestroyTexture(UI_T->text_tex_dir_x);
	SDL_DestroyTexture(UI_T->text_tex_dir_y);
	SDL_DestroyTexture(UI_T->text_tex_dir_z);
	SDL_DestroyTexture(UI_T->text_tex_trans);
	SDL_DestroyTexture(UI_T->text_tex_spec);
	SDL_DestroyTexture(UI_T->text_tex_refr);
	SDL_DestroyTexture(UI_T->text_tex_brill);
	SDL_DestroyTexture(UI_T->text_tex_tex);
	SDL_DestroyTexture(UI_T->text_tex_tex_size);
	SDL_DestroyTexture(UI_T->text_tex_norm_map);
}

void			clear_ui(t_sdl *main)
{
	TTF_CloseFont(UI_T->font);
	part_one(main);
	free(UI_T->stroka1);
	free(UI_T->stroka2);
	free(UI_T->stroka3);
	free(UI_T->stroka4);
	free(UI_T->stroka5);
	free(UI_T->stroka6);
	free(UI_T->stroka7);
	free(UI_T->stroka8);
	free(UI_T->stroka9);
	free(UI_T->stroka10);
	free(UI_T->stroka11);
	free(UI_T->stroka12);
	free(UI_T->stroka13);
	free(UI_T->stroka14);
	free(UI_T->stroka15);
	free(UI_T->stroka16);
	free(UI_T);
	free(main->ui);
}
