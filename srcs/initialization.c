/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekruhliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:44:53 by ekruhliu          #+#    #+#             */
/*   Updated: 2018/10/26 16:44:53 by ekruhliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

void			create_sdl(t_sdl *main, int width, int height)
{
	Uint32	render_flags;

	main->win = SDL_CreateWindow("RT", SDL_WINDOWPOS_UNDEFINED,\
		SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	main->rend = SDL_CreateRenderer(main->win, -1, render_flags);
	main->fillscreen = SDL_CreateTexture(main->rend, SDL_PIXELFORMAT_RGB888,\
		SDL_TEXTUREACCESS_TARGET, width, height);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	main->sample_screen = SDL_CreateTexture(main->rend, SDL_PIXELFORMAT_RGB888,\
		SDL_TEXTUREACCESS_TARGET, 2 * width, 2 * height);
	main->done = 0;
	main->data = malloc(sizeof(int) * (width * height));
	main->sample_data = malloc(4 * sizeof(int) * (width * height));
	bzero(main->sample_data, 4 * sizeof(int) * (width * height));
	bzero(main->data, sizeof(int) * (width * height));
	TTF_Init();
}

static	t_sdl	part_one(t_sdl sdl)
{
	sdl.obj_win_on = 0;
	sdl.block = 0;
	sdl.num_of_figure = -1;
	sdl.on = 0;
	sdl.num_of_scr_shot = 0;
	sdl.old_pos_x_ch = 0;
	sdl.old_pos_y_ch = 0;
	sdl.old_pos_z_ch = 0;
	sdl.old_color_x_ch = 0;
	sdl.old_color_y_ch = 0;
	sdl.old_color_z_ch = 0;
	sdl.old_dir_x_ch = 0;
	sdl.old_dir_y_ch = 0;
	sdl.old_dir_z_ch = 0;
	sdl.old_trans_ch = 0;
	sdl.old_spec_ch = 0;
	sdl.old_refr_ch = 0;
	sdl.old_refl_ch = 0;
	sdl.old_tex_ch = 0;
	sdl.old_tex_size_ch = 0;
	sdl.old_normal_map_ch = 0;
	sdl.data_type = 0;
	sdl.ui = NULL;
	return (sdl);
}

t_sdl			ui_init(t_sdl sdl, t_scene *sc)
{
	sdl = part_one(sdl);
	sdl.byte_size = sizeof(t_cl_object) * sc->obj_cnt;
	sdl.res_len = WIDTH * WIDTH;
	sdl.res = malloc(sizeof(unsigned int) * sdl.res_len);
	bzero(sdl.res, sizeof(unsigned int) * sdl.res_len);
	if (load_file_str("./my.cl", &sdl.source) == -1)
	{
		ft_putstr("bad cl\n");
		exit(1);
	}
	sdl.frames = 0;
	sdl.begin = clock();
	sdl.fps = 0;
	sdl.res_blen = sizeof(int) * sc->width * sc->height;
	sdl.sample_res_blen = sizeof(int) * 4 * sc->width * sc->height;
	sdl.time_passed = clock() - sdl.begin;
	sdl.start_time = sdl.time_passed;
	sdl.new_data = 0;
	sdl.fps_r.w = 100;
	sdl.fps_r.h = 100;
	sdl.fps_r.x = 490;
	sdl.fps_r.y = 0;
	return (sdl);
}

static	void	part_sc(t_scene *sc)
{
	sc->earth = malloc(sizeof(int) * (512 * 512));
	sc->iron = malloc(sizeof(int) * (512 * 512));
	sc->earth_normal = malloc(sizeof(int) * (512 * 512));
	sc->iron_normal = malloc(sizeof(int) * (512 * 512));
	sc->stone = malloc(sizeof(int) * (512 * 512));
	sc->stone_normal = malloc(sizeof(int) * (512 * 512));
	sc->perlin = malloc(sizeof(int) * (512 * 512));
	sc->sun = malloc(sizeof(int) * (512 * 512));
	sc->merc = malloc(sizeof(int) * (512 * 512));
	sc->mars = malloc(sizeof(int) * (512 * 512));
	sc->neptune = malloc(sizeof(int) * (512 * 512));
}

void			init_sc(t_scene *sc)
{
	sc->filters = ft_memalloc(sizeof(t_filters_on));
	sc->filters->gradient = 0;
	sc->height = 1000;
	sc->width = 1000;
	part_sc(sc);
	ft_get_image(sc->earth_normal, "./img/earthnormal.png");
	ft_get_image(sc->earth, "./img/earth.png");
	ft_get_image(sc->iron, "./img/iron.jpg");
	ft_get_image(sc->iron_normal, "./img/ironnormal.png");
	ft_get_image(sc->stone, "./img/stone.jpg");
	ft_get_image(sc->stone_normal, "./img/stonenormal.png");
	ft_get_image(sc->sun, "./img/sun.jpg");
	ft_get_image(sc->merc, "./img/merc.jpg");
	ft_get_image(sc->mars, "./img/redplanet.jpg");
	ft_get_image(sc->neptune, "./img/pink.jpg");
	generate_perlin(sc->perlin, 512 * 512);
	sc->closest = ft_memalloc(sizeof(int));
	*(sc->closest) = -1;
	sc->mouse_x = -1;
	sc->mouse_y = -1;
}
