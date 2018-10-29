/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 17:01:38 by akokoshk          #+#    #+#             */
/*   Updated: 2018/08/27 22:11:30 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rt_open_cl.h"

static	void	part_one(int ac, char **argv, t_sdl *sdl)
{
	int err;

	if (ac > 1)
	{
		err = load_file_str(argv[1], &sdl->source);
		if (err == -1)
		{
			ft_putstr("put valid scene\n");
			exit(1);
		}
	}
	else
	{
		ft_putstr("put scene\n");
		exit(1);
	}
}

static	void	part_two(t_move *move, t_cldata *cl, t_scene *sc, t_sdl *sdl)
{
	bzero(move, sizeof(t_move));
	create_cl_data(cl, sc);
	write_cl_data(cl, sc, 0);
	execute_and_read(cl, sdl->sample_res_blen, sdl->sample_data, sc);
	draw_direct(sdl, sc->height, sc->is_sample);
}

static	void	part_three(t_sdl *sdl, t_scene *sc)
{
	if (sc->is_sample)
	{
		if (sc->height == 1000)
		{
			sc->height *= 2;
			sc->width *= 2;
			sdl->new_data = 1;
		}
		else
			sdl->new_data = 0;
	}
	else
	{
		if (sc->height == 2000)
		{
			sc->height /= 2;
			sc->width /= 2;
			sdl->new_data = 1;
		}
		else
			sdl->new_data = 0;
	}
}

static	void	part_four(t_sdl *sdl, t_scene *sc, t_move *move, t_cldata *cl)
{
	key(sdl, move, sc, cl);
	write_cl_data(cl, sc, 1);
	if (sc->is_sample)
		execute_and_read(cl, sdl->sample_res_blen, sdl->sample_data, sc);
	else
		execute_and_read(cl, sdl->res_blen, sdl->data, sc);
	set_rotation(move, sc->cam->transp_rotate_matrix);
	move_cam(move, &sc->cam->center, sc->cam->transp_rotate_matrix);
	draw_direct(sdl, sc->height, sc->is_sample);
}

int				main(int ac, char **argv)
{
	t_sdl			sdl;
	t_scene			*sc;
	t_cldata		*cl;
	t_move			move;
	nx_json			*js;

	part_one(ac, argv, &sdl);
	js = (nx_json*)nx_json_parse(sdl.source, 0);
	free(sdl.source);
	if (!(sc = parse_json_scene(js)))
		shit_happens("invalid json");
	init_sc(sc);
	create_sdl(&sdl, 1000, 1000);
	create_buttons(&sdl);
	sdl = ui_init(sdl, sc);
	cl = ocl_init(sdl.source, "test", sdl.byte_size, (size_t)sc->obj_cnt);
	free(sdl.source);
	part_two(&move, cl, sc, &sdl);
	while (!sdl.done)
	{
		part_three(&sdl, sc);
		part_four(&sdl, sc, &move, cl);
		frames(&sdl);
	}
	return (0);
}
