/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_buttons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 10:43:18 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/12 10:43:19 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

static	void	part_one(t_sdl *main)
{
	BUTTONS->exit_surf = IMG_Load("./ui_buttons/Filter.png");
	BUTTONS->exit_tex = TEX_FMR_SRF(main->rend, BUTTONS->exit_surf);
	SDL_FreeSurface(BUTTONS->exit_surf);
	BUTTONS->exit_surf = IMG_Load("./ui_buttons/screenshot.png");
	BUTTONS->screenshot_tex = TEX_FMR_SRF(main->rend, BUTTONS->exit_surf);
	SDL_FreeSurface(BUTTONS->exit_surf);
	BUTTONS->exit_surf = IMG_Load("./ui_buttons/sepia.png");
	BUTTONS->sepia_tex = TEX_FMR_SRF(main->rend, BUTTONS->exit_surf);
	SDL_FreeSurface(BUTTONS->exit_surf);
	BUTTONS->exit_surf = IMG_Load("./ui_buttons/b_w.png");
	BUTTONS->b_w_tex = TEX_FMR_SRF(main->rend, BUTTONS->exit_surf);
	SDL_FreeSurface(BUTTONS->exit_surf);
	BUTTONS->exit_surf = IMG_Load("./ui_buttons/negative.png");
	BUTTONS->negative_tex = TEX_FMR_SRF(main->rend, BUTTONS->exit_surf);
	SDL_FreeSurface(BUTTONS->exit_surf);
}

static	void	part_one_and_half(t_sdl *main)
{
	BUTTONS->exit_surf = IMG_Load("./ui_buttons/red.png");
	BUTTONS->red_tex = TEX_FMR_SRF(main->rend, BUTTONS->exit_surf);
	SDL_FreeSurface(BUTTONS->exit_surf);
	BUTTONS->exit_surf = IMG_Load("./ui_buttons/green.png");
	BUTTONS->green_tex = TEX_FMR_SRF(main->rend, BUTTONS->exit_surf);
	SDL_FreeSurface(BUTTONS->exit_surf);
	BUTTONS->exit_surf = IMG_Load("./ui_buttons/blue.png");
	BUTTONS->blue_tex = TEX_FMR_SRF(main->rend, BUTTONS->exit_surf);
	SDL_FreeSurface(BUTTONS->exit_surf);
	BUTTONS->exit_surf = IMG_Load("./ui_buttons/gradient.png");
	BUTTONS->gradient_tex = TEX_FMR_SRF(main->rend, BUTTONS->exit_surf);
	SDL_FreeSurface(BUTTONS->exit_surf);
}

static	void	part_two(t_sdl *main)
{
	BUTTONS->dst_r.h = 40;
	BUTTONS->dst_r.w = 80;
	BUTTONS->dst_r.x = 0;
	BUTTONS->dst_r.y = 0;
	BUTTONS->ssdst_r.h = 75;
	BUTTONS->ssdst_r.w = 75;
	BUTTONS->ssdst_r.x = W - 75;
	BUTTONS->ssdst_r.y = 0;
	BUTTONS->sepia_dst_r.h = 40;
	BUTTONS->sepia_dst_r.w = 80;
	BUTTONS->sepia_dst_r.x = 0;
	BUTTONS->sepia_dst_r.y = 40;
	BUTTONS->b_w_dst_r.h = 40;
	BUTTONS->b_w_dst_r.w = 80;
	BUTTONS->b_w_dst_r.x = 0;
	BUTTONS->b_w_dst_r.y = 80;
}

static	void	part_three(t_sdl *main)
{
	BUTTONS->negative_dst_r.h = 40;
	BUTTONS->negative_dst_r.w = 80;
	BUTTONS->negative_dst_r.x = 0;
	BUTTONS->negative_dst_r.y = 120;
	BUTTONS->red_dst_r.h = 40;
	BUTTONS->red_dst_r.w = 80;
	BUTTONS->red_dst_r.x = 0;
	BUTTONS->red_dst_r.y = 160;
	BUTTONS->green_dst_r.h = 40;
	BUTTONS->green_dst_r.w = 80;
	BUTTONS->green_dst_r.x = 0;
	BUTTONS->green_dst_r.y = 200;
	BUTTONS->blue_dst_r.h = 40;
	BUTTONS->blue_dst_r.w = 80;
	BUTTONS->blue_dst_r.x = 0;
	BUTTONS->blue_dst_r.y = 240;
	BUTTONS->gradient_dst_r.h = 40;
	BUTTONS->gradient_dst_r.w = 80;
	BUTTONS->gradient_dst_r.x = 0;
	BUTTONS->gradient_dst_r.y = 280;
}

void			create_buttons(t_sdl *main)
{
	BUTTONS = malloc(sizeof(t_buttons));
	part_one(main);
	part_one_and_half(main);
	part_two(main);
	part_three(main);
}
