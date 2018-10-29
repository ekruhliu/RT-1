/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_open_cl.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akokoshk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 18:30:31 by akokoshk          #+#    #+#             */
/*   Updated: 2018/08/27 21:28:57 by akokoshk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_OPEN_CL_H
# define RT_OPEN_CL_H

# include <stdio.h>
# include <time.h>
# include <strings.h>
# include <OpenCL/opencl.h>
# include <math.h>
# include "frameworks/SDL2.framework/Headers/SDL.h"
# include "frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
# include "frameworks/SDL2_image.framework/Headers/SDL_image.h"
# include "frameworks/textBox/tinyfiledialogs.h"
# include "frameworks/libJson/nxjson.h"
# include "./libft/libft.h"

# define WRITE ft_putstr
# define WIDTH 1000
# define HEIGHT 1000

# define W 1000
# define H 1000

# define AMBIENT 0
# define POINT 1
# define DIRECT 2
# define PARAL 3

# define UI_T main->ui->ui_text
# define RENDER_TEXT TTF_RenderText_Solid
# define THIS_FIG sc->objects[*(sc->closest)]
# define T_R text_rect
# define QUERY_TEX SDL_QueryTexture
# define UI main->ui

# define MCL_GPU CL_DEVICE_TYPE_GPU
# define MCL_OK CL_SUCCESS
# define MCL_RDO CL_MEM_READ_ONLY
# define MCL_WRO CL_MEM_WRITE_ONLY

# define SPHERE 0
# define PLANE 1
# define CYLINDER 2
# define CONE 3

# define EVENT_TYPE main->event.type
# define BUTT_X main->event.button.x >= 0 && main->event.button.x <= 80
# define BUTT main->event.button
# define TEX_FMR_SRF SDL_CreateTextureFromSurface
# define BUTTONS main->buttons
# define REND_CPY SDL_RenderCopy
# define SET_KERNEL clSetKernelArg
# define KEKOS(x, y, s) (x + s * (y - x))
# define MEMOS(x, y, s) KEKOS(x, y, s * s * (3 - 2 * s))
# define JOPEC(a) (a * 255)

typedef struct			s_cldata
{
	cl_device_id		dev_id;
	cl_context			cntxt;
	cl_command_queue	commands;
	cl_program			program;
	cl_kernel			kernel;
	char				*src;
	int					err;
	cl_mem				inp;
	cl_mem				lights;
	cl_mem				filters;
	cl_mem				earth;
	cl_mem				iron;
	cl_mem				earth_normal;
	cl_mem				iron_normal;
	cl_mem				stone;
	cl_mem				stone_normal;
	cl_mem				perlin;
	cl_mem				sun;
	cl_mem				mars;
	cl_mem				merc;
	cl_mem				neptune;
	cl_mem				out;
	cl_mem				sample_out;
	cl_mem				closest;
	cl_mem				rotate_matrix;
	size_t				bytlen;
	size_t				cnt;
}						t_cldata;

typedef struct			s_cl_object
{
	int					type;
	int					texture;
	int					texture_size;
	int					normal_map;
	int					limited;
	int					specular;
	float				refl;
	float				transp;
	float				refr;
	float				radius;
	float				sq_cos;
	float				sq_sin;
	cl_float3			color;
	cl_float3			centre;
	cl_float3			centre1;
	cl_float3			centre2;
	cl_float3			dir;
	cl_float3			normal1;
	cl_float3			normal2;
}						t_cl_object;

typedef struct			s_cl_light
{
	int					type;
	float				cos_a;
	cl_float3			intens;
	cl_float3			centre;
	cl_float3			dir;
}						t_cl_light;

typedef struct			s_rt_cam
{
	cl_float3			center;
	cl_float3			transp_rotate_matrix[3];
}						t_rt_cam;

typedef	struct			s_filters_on
{
	int					gradient;
	int					sepia_on;
	int					b_w_on;
	int					blood_on;
	int					bt_on;
	int					gt_on;
	int					negative_on;
}						t_filters_on;

typedef struct			s_scene
{
	int					width;
	int					height;
	int					mouse_x;
	int					mouse_y;
	int					shadow;
	int					is_sample;
	t_cl_object			*objects;
	int					obj_cnt;
	t_cl_light			*lights;
	int					light_cnt;
	t_rt_cam			*cam;
	int					cam_num;
	int					*earth;
	int					*iron;
	int					*iron_normal;
	int					*earth_normal;
	int					*stone;
	int					*stone_normal;
	unsigned int		*perlin;
	int					*sun;
	int					*merc;
	int					*mars;
	int					*neptune;
	t_filters_on		*filters;
	int					*closest;
}						t_scene;

typedef struct			s_move
{
	int					forward;
	int					backward;
	int					left;
	int					right;
	int					up;
	int					down;
	int					f_rot_x;
	int					b_rot_x;
	int					f_rot_y;
	int					b_rot_y;
	int					f_rot_z;
	int					b_rot_z;
	int					rot;
	int					mv;
	cl_float3			f_dir;
	cl_float3			l_dir;
	cl_float3			u_dir;
}						t_move;

typedef	struct			s_buttons
{
	SDL_Texture			*exit_tex;
	SDL_Texture			*screenshot_tex;
	SDL_Texture			*sepia_tex;
	SDL_Texture			*b_w_tex;
	SDL_Texture			*negative_tex;
	SDL_Texture			*red_tex;
	SDL_Texture			*green_tex;
	SDL_Texture			*blue_tex;
	SDL_Texture			*gradient_tex;
	SDL_Surface			*exit_surf;
	SDL_Rect			dst_r;
	SDL_Rect			ssdst_r;
	SDL_Rect			sepia_dst_r;
	SDL_Rect			b_w_dst_r;
	SDL_Rect			negative_dst_r;
	SDL_Rect			red_dst_r;
	SDL_Rect			green_dst_r;
	SDL_Rect			blue_dst_r;
	SDL_Rect			gradient_dst_r;
}						t_buttons;

typedef	struct			s_ui_text
{
	char				*stroka1;
	char				*stroka2;
	char				*stroka3;
	char				*stroka4;
	char				*stroka5;
	char				*stroka6;
	char				*stroka7;
	char				*stroka8;
	char				*stroka9;
	char				*stroka10;
	char				*stroka11;
	char				*stroka12;
	char				*stroka13;
	char				*stroka14;
	char				*stroka15;
	char				*stroka16;
	SDL_Rect			text_rect;
	TTF_Font			*font;
	SDL_Surface			*text_surf_x;
	SDL_Surface			*text_surf_y;
	SDL_Surface			*text_surf_z;
	SDL_Surface			*text_surf_red;
	SDL_Surface			*text_surf_green;
	SDL_Surface			*text_surf_blue;
	SDL_Surface			*text_surf_dir_x;
	SDL_Surface			*text_surf_dir_y;
	SDL_Surface			*text_surf_dir_z;
	SDL_Surface			*text_surf_trans;
	SDL_Surface			*text_surf_spec;
	SDL_Surface			*text_surf_refr;
	SDL_Surface			*text_surf_brill;
	SDL_Surface			*text_surf_tex;
	SDL_Surface			*text_surf_tex_size;
	SDL_Surface			*text_surf_norm_map;
	SDL_Texture			*text_tex_x;
	SDL_Texture			*text_tex_y;
	SDL_Texture			*text_tex_z;
	SDL_Texture			*text_tex_red;
	SDL_Texture			*text_tex_green;
	SDL_Texture			*text_tex_blue;
	SDL_Texture			*text_tex_dir_x;
	SDL_Texture			*text_tex_dir_y;
	SDL_Texture			*text_tex_dir_z;
	SDL_Texture			*text_tex_trans;
	SDL_Texture			*text_tex_spec;
	SDL_Texture			*text_tex_refr;
	SDL_Texture			*text_tex_brill;
	SDL_Texture			*text_tex_tex;
	SDL_Texture			*text_tex_tex_size;
	SDL_Texture			*text_tex_norm_map;
}						t_ui_text;

typedef	struct			s_ui
{
	t_ui_text			*ui_text;
	SDL_Surface			*accept_button_surf;
	SDL_Texture			*accept_button_tex;
	SDL_Rect			accept_rect;
}						t_ui;

typedef struct			s_sdl
{
	SDL_Window			*win;
	SDL_Renderer		*rend;
	SDL_Texture			*fillscreen;
	SDL_Texture			*sample_screen;
	SDL_Surface			*surf;
	SDL_Event			event;
	int					*data;
	int					*sample_data;
	int					done;
	t_buttons			*buttons;
	SDL_Window			*obj_win;
	SDL_Renderer		*obj_rend;
	int					block;
	int					obj_win_on;
	int					num_of_figure;
	int					on;
	int					num_of_scr_shot;
	t_cl_object			*figure;
	cl_float3			old_pos;
	cl_float3			old_color;
	cl_float3			old_dir;
	float				old_trans;
	int					old_spec;
	float				old_refr;
	float				old_refl;
	int					old_tex;
	int					old_tex_size;
	int					old_normal_map;
	int					old_pos_x_ch;
	int					old_pos_y_ch;
	int					old_pos_z_ch;
	int					old_color_x_ch;
	int					old_color_y_ch;
	int					old_color_z_ch;
	int					old_dir_x_ch;
	int					old_dir_y_ch;
	int					old_dir_z_ch;
	int					old_trans_ch;
	int					old_spec_ch;
	int					old_refr_ch;
	int					old_refl_ch;
	int					old_tex_ch;
	int					old_tex_size_ch;
	int					old_normal_map_ch;
	t_ui				*ui;
	int					data_type;
	char				*source;
	size_t				byte_size;
	size_t				res_len;
	unsigned int		*res;
	int					frames;
	clock_t				begin;
	clock_t				time_passed;
	clock_t				start_time;
	float				fps;
	size_t				res_blen;
	size_t				sample_res_blen;
	int					new_data;
	SDL_Texture			*fps_tex;
	SDL_Rect			fps_r;
}						t_sdl;

t_cldata				*ocl_init(char *progstr, char *kernel, size_t size,\
	size_t cnt);
void					write_cl_data(t_cldata *cl, t_scene *scene, int push);
t_scene					*parse_json_scene(const nx_json *json);
cl_mem					cl_mem_write(t_cldata *cl, cl_mem mem, size_t size,\
	void *dat);
void					execute_and_read(t_cldata *cl, size_t res_blen,\
	void *res, t_scene *sc);
void					draw_direct(t_sdl *sdl, int height, int is_sample);
float					vector_len(cl_float3 *v);
cl_float3				norm_vector_by_points(cl_float3 *p, cl_float3 *p1);
void					normalize_local(cl_float3 *to_normalize);
cl_float3				vector_by_points(cl_float3 *p, cl_float3 *p1);
cl_float3				get_normal_to_plane(cl_float3 *p, cl_float3 *p1,\
	cl_float3 *p2);
void					move_cam(t_move *move, cl_float3 *cam,\
	cl_float3 *transp_matrix);
void					set_move(t_move *move, int scancode);
void					remove_move(t_move *move, int scancode);
void					key(t_sdl *main, t_move *move, t_scene *sc,\
	t_cldata *cl);
float					dot(cl_float3 *v1, cl_float3 *v2);
void					rotate_local(cl_float3 *v, cl_float3 *transp_matrix);
void					add_to_first(cl_float3 *first, cl_float3 *second);
void					minus_to_first(cl_float3 *first, cl_float3 *second);
void					mult_local(float sc, cl_float3 *to_mult);
void					set_rotation(t_move *move, cl_float3 *transp_matrix);
void					transp_local(cl_float3 *matrix);
void					set_rotate_x(cl_float3 *buff, float angle);
void					set_rotate_y(cl_float3 *buff, float angle);
void					set_rotate_z(cl_float3 *buff, float angle);
void					mult_to_first_second(cl_float3 *first,\
	cl_float3 *second);
void					clear_ui(t_sdl *main);
void					ui(t_sdl *main, t_scene *sc, t_cldata *cl);
void					zero_maker(t_scene *sc);
void					figure_selection(t_sdl *main, t_scene *sc,\
	t_cldata *cl);
void					using_filters(t_sdl *main, t_scene *sc);
void					interface_win(t_sdl *main, t_scene *sc);
void					change_int_value(t_sdl *main, t_scene *sc,\
	int *new, int *old);
void					change_float_value(t_sdl *main, t_scene *sc,\
	float *new, float *old);
void					init_ui(t_sdl *main);
void					init_str(t_sdl *main, t_scene *sc);
void					init_surfs(t_sdl *main);
void					init_textures(t_sdl *main);
void					query_textures(t_sdl *main);
void					screenshot(t_sdl *main, char *number, char *res);
void					create_buttons(t_sdl *main);
void					valid_obj(t_cl_object *obj);
void					valid_light(t_cl_light *light);
int						is_trinagle(cl_float3 *p, cl_float3 *p1, cl_float3 *p2);
void					light_mouse(t_sdl *main, t_scene *sc);
void					object_window(t_sdl *main, t_scene *sc);
void					obj_window_part_one(t_sdl *main, t_scene *sc);
void					obj_window_part_two(t_sdl *main, t_scene *sc);
float					ft_atof(const char *str);
void					obj_to_normal(t_cl_object *obj, double angle);
cl_float3				cross(cl_float3 *u, cl_float3 *v);
void					ocl_error(int err);
void					create_cl_data(t_cldata *cl, t_scene *scene);
cl_mem					cl_mem_create(t_cldata *cl, cl_mem_flags rw,\
	size_t size);
cl_mem					cl_mem_write(t_cldata *cl, cl_mem mem,\
	size_t size, void *dat);
int						int_val(const nx_json *nod);
float					flt_val(const nx_json *nod);
cl_float3				flt3_val(const nx_json *ar);
int						parce_cam(const nx_json *nod, void *dst);
void					create_sdl(t_sdl *main, int width, int height);
t_sdl					ui_init(t_sdl sdl, t_scene *sc);
void					init_sc(t_scene *sc);
void					generate_perlin(unsigned int *pixels, int size);
void					ft_get_image(int *pixels, const char *path);
int						get_col_by_i(void *ptr, int i);
int						set_rgb(unsigned int r, unsigned int g, unsigned int b);
long					load_file_str(char *fname, char **str);
float					perl2d(float x, float y, float freq, int depth);
float					noise_mc(float x, float y);
void					frames(t_sdl *sdl);
void					shit_happens(char *message);

#endif
