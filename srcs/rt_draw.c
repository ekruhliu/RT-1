/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:35:37 by iradchen          #+#    #+#             */
/*   Updated: 2018/08/27 20:25:42 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"
#define NEG_TEX BUTTONS->negative_tex
#define S_DATA main->sample_data

void	draw_direct(t_sdl *main, int height, int is_sample)
{
	if (is_sample)
		SDL_UpdateTexture(main->sample_screen, NULL, S_DATA, height * 4);
	else
		SDL_UpdateTexture(main->fillscreen, NULL, main->data, height * 4);
	SDL_SetRenderDrawColor(main->rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(main->rend);
	if (is_sample)
		REND_CPY(main->rend, main->sample_screen, NULL, NULL);
	else
		REND_CPY(main->rend, main->fillscreen, NULL, NULL);
	REND_CPY(main->rend, BUTTONS->exit_tex, NULL, &BUTTONS->dst_r);
	REND_CPY(main->rend, BUTTONS->screenshot_tex, NULL, &BUTTONS->ssdst_r);
	REND_CPY(main->rend, main->fps_tex, NULL, &main->fps_r);
	if (main->on == 1)
	{
		REND_CPY(main->rend, BUTTONS->sepia_tex, NULL, &BUTTONS->sepia_dst_r);
		REND_CPY(main->rend, BUTTONS->b_w_tex, NULL, &BUTTONS->b_w_dst_r);
		REND_CPY(main->rend, NEG_TEX, NULL, &BUTTONS->negative_dst_r);
		REND_CPY(main->rend, BUTTONS->red_tex, NULL, &BUTTONS->red_dst_r);
		REND_CPY(main->rend, BUTTONS->green_tex, NULL, &BUTTONS->green_dst_r);
		REND_CPY(main->rend, BUTTONS->blue_tex, NULL, &BUTTONS->blue_dst_r);
		REND_CPY(main->rend, BUTTONS->gradient_tex, NULL,\
			&BUTTONS->gradient_dst_r);
	}
	SDL_RenderPresent(main->rend);
}
