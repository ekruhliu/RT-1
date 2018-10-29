/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   query_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 18:33:19 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/10 18:33:20 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void	query_textures(t_sdl *main)
{
	QUERY_TEX(UI_T->text_tex_x, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
	QUERY_TEX(UI_T->text_tex_y, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
	QUERY_TEX(UI_T->text_tex_z, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
	QUERY_TEX(UI_T->text_tex_red, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
	QUERY_TEX(UI_T->text_tex_green, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
	QUERY_TEX(UI_T->text_tex_blue, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
	QUERY_TEX(UI_T->text_tex_dir_x, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
	QUERY_TEX(UI_T->text_tex_dir_y, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
	QUERY_TEX(UI_T->text_tex_dir_z, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
	QUERY_TEX(UI_T->text_tex_trans, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
	QUERY_TEX(UI_T->text_tex_spec, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
	QUERY_TEX(UI_T->text_tex_refr, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
	QUERY_TEX(UI_T->text_tex_brill, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
	QUERY_TEX(UI_T->text_tex_tex, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
	QUERY_TEX(UI_T->text_tex_tex_size, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
	QUERY_TEX(UI_T->text_tex_norm_map, NULL, NULL, &UI_T->T_R.w, &UI_T->T_R.h);
}
