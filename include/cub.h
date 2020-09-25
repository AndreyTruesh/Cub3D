/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abibi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 21:16:04 by abibi             #+#    #+#             */
/*   Updated: 2020/09/25 16:21:16 by abibi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_R_ARR 65363
# define KEY_L_ARR 65361
# define KEY_ESC 65307
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <stdio.h>

typedef struct	s_pos
{
	float		pos_x;
	float		pos_y;
	float		dir_x;
	float		dir_y;
	float		plane_y;
	float		plane_x;
}				t_pos;

typedef struct	s_map
{
	int			h;
	int			w;
	char		**map;
}				t_map;

typedef struct	s_tex
{
	void		*img_ptr;
	void		*img_data;
	int			sizeline;
	int			bpp;
	int			height;
	int			width;
	int			endian;
}				t_tex;

typedef struct	s_drawinfo
{
	int			x;
	int			lineheight;
	int			tex_x;
}				t_drawinfo;

typedef struct	s_sprite
{
	float		distance;
	float		x;
	float		y;
}				t_sprite;

typedef struct	s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img_data;
	int			bpp;
	int			size_line;
	int			endian;
	int			w;
	int			h;
	char		*no_tex_p;
	char		*we_tex_p;
	char		*ea_tex_p;
	char		*so_tex_p;
	char		*s_tex_p;
	int			f_color;
	int			c_color;
	int			c_color_flag;
	int			f_color_flag;
	int			sprite_count;
	t_tex		no_tex;
	t_tex		we_tex;
	t_tex		so_tex;
	t_tex		ea_tex;
	t_tex		s_tex;
	t_pos		pos;
	t_map		map;
	t_sprite	*sprite_arr;
	double		*pwd_arr;
}				t_game;

typedef struct	s_rc
{
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	int			step_x;
	int			step_y;
	int			side;
}				t_rc;

typedef struct	s_rc_res
{
	double		pwalldist;
	double		raydir_x;
	double		raydir_y;
	int			lineheight;
	int			side;
}				t_rc_res;

typedef struct	s_sprite_di
{
	double		transform_y;
	int			spritescreen_x;
	int			spriteheight;
	int			spritewidth;
	int			drawend_x;
	int			drawend_y;
	int			drawstart_x;
	int			drawstart_y;
}				t_sprite_di;

int				parse_input(char *f_path, t_game *el);
int				get_tex(t_game *el, char *line, int id);
int				get_res(t_game *el, char *line);
int				parse_inp(int fd, t_game *el);
void			map_free(t_game *el);
int				get_map(t_game *el, int fd);
void			make_screenshot_malloc_error(t_game *el);
void			make_screenshot_write_error(t_game *el, unsigned char *bmp);
void			sort_sprites(t_game *el);
int				get_sprites(t_game *el);
int				ft_isspace(char c);
int				get_color(t_game *el, char *line, int id);
int				check_last_symbols(char *line);
int				load_textures(t_game *el);
void			free_tex_paths(t_game *el);
void			free_textures(t_game *el);
void			render_image(t_game *el);
int				deal_key(int key, t_game *el);
void			load_textures_error(t_game *el);
void			parse_inp_error(int error);
void			get_sprites_error(t_game *el);
void			mlx_init_error(t_game *el);
void			mlx_new_window_error(t_game *el);
int				close_event(t_game *el);
void			sprites_free(t_game *el);
void			check_screen_size(t_game *el);
int				exp_event(t_game *el);
int				check_for_pos(t_game *el, int n);
void			lstclear(t_list **map_lines);
void			lstdestroyer(t_list **lst, t_list *el);
int				map_to_list(t_list **map_lines, t_game *el, int fd);
int				validate_last_empty_lines(t_list *map_lines);
t_rc_res		apply_dda(double raydir_x, double raydir_y, t_game *el);
void			render_walls(t_game *el);
int				get_pixel_col(int x, int y, t_tex tex);
void			print_error(const char *s);
void			mlx_get_data_addr_error(t_game *el);
void			mlx_new_image_error(t_game *el);
void			draw_sprites(t_game el);
int				map_is_empty(t_list *map_lines);
int				list_malloc_error(t_list **map_lines, char *buf, int i,
		t_game *el);
char			*ft_strcpy(char *dest, const char *src);
void			tgame_init(t_game *el);
int				id_num(char **id);
int				check_fields(t_game el);
void			init_game_screenshot(char *f_path, t_game *el);

#endif
