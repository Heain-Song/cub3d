/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 07:53:34 by hesong            #+#    #+#             */
/*   Updated: 2024/02/29 12:12:06 by hesong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <string.h>

/*****************MACROS*****************/

# define WIDTH 800
# define HEIGHT 800
# define PROG "cub3d"
# define FORWARD 119
# define BACK 115
# define RIGHT 100
# define LEFT 97
# define MOVE_SPEED 0.01
# define ROT_SPEED 0.01
# define ROTATE_RIGHT 65363
# define ROTATE_LEFT 65361
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

/***************STRUCTURES***************/

typedef struct s_vector{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player{
	int		x;
	int		y;
}	t_player;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_num_mlx
{
	void	*server;
	void	*window;
	void	*img;
	int		*addr;
}	t_num_mlx;

typedef struct s_textures
{
	char				*id;
	char				*path;
	void				*img;
	struct s_textures	*next;
}	t_textures;

typedef struct s_ray
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
	double		move_speed;
	double		rotate_speed;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwalldist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			drawn_len;
	int			tex_x;
	int			tex_y;
	double		current_angle;
}	t_ray;

typedef struct s_elems
{
	int			loaded_textures;
	t_textures	*textures;
	t_num_mlx	mlx;
	t_data		floor;
	t_data		ceiling;
	t_data		img;
	t_data		screen;
	t_ray		ray;
	t_data		tex[4];
	int			f_colors[3];
	int			c_colors[3];
	char		**map;
	int			is_full;
	int			error;
	char		**elem_names;
	int			did_c;
	int			did_f;
	double		player_x;
	double		player_y;
	int			found_player;
	char		player_dir;
	int			color;
	bool		w;
	bool		s;
	bool		a;
	bool		d;
	bool		rotate_left;
	bool		rotate_right;
	void		*screenbuffer;
	char		*map_file;





}	t_elems;

/****************FUNCTIONS***************/

int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstrfd(char *str, int fd);
int			file_checker(char *str);
char		*basic_gnl(int fd, int *read_amount, int keep_nl);
int			ft_strlen(char *str);
char		*ft_strcpy(char *src, char *dest);
t_textures	*make_text_id(void);
void		free_t_textures(t_textures *textures, t_elems elems);
char		*ft_strdup(char *str);
int			ft_strncmp(const char *s1, const char *s2, unsigned int n);
t_elems		element_reader(int fd, t_elems elems);
t_elems		init_elems(void);
t_elems		check_elems(t_elems elems_list);
int			elem_type(char *temp, char **str);
int			ft_atoi(const char *str);
t_elems		get_nbr_atribs(t_elems elems, char *str);
t_elems		get_str_atrib(t_elems elems, char *str);
t_elems		assign_which_elem(char *str, int nb, t_elems elems);
void		free_elems(t_elems elems);
char		*skip_and_getnb(char *str, int *nb);
int			str_check_num_amount(char *str);
t_elems		start_reading_map(int fd, t_elems elems);
char		**add_to_table(char *str, char **table);
t_elems		check_map(t_elems elems, char **map);
t_elems		error_node(t_textures *node, t_elems elems);
t_elems		basic_error(t_elems elems, char *error,
				char *attrib, char *to_free);
t_elems		save_error(t_elems elems);
t_elems		check_around(char d, t_elems elems);
int			is_player(char c);
t_elems		find_player(char **map, t_elems elems);
t_elems		error_reading(char *temp, char *error, t_elems elems);
t_elems		check_textures(t_elems elems, t_textures *node);
t_elems		check_empty_line(char **map, size_t i, t_elems elems);
t_elems		error_player(t_elems elems);
t_elems		check_type_in_map(char **str, t_elems elems);
t_elems		color_checker(t_elems elems, char *str);
t_elems		start_window_loop(t_elems elems);
int			get_colors(int t, int r, int g, int b);
t_elems		make_background(t_elems elems);

//visuals
int			window_destroyer(t_num_mlx *mlx);
int			ft_close_win(int keycode, t_num_mlx *mlx);
int			hook_event(t_num_mlx *mlx);

//raycasting//
t_elems		launch_game(t_elems elems);
void		get_position(t_elems *elems);
void		get_dir(t_elems *elems);
void		get_plane(t_elems *elems);



//debug//
void		display_textures_list(t_textures *head);
void		print_map(char **map);
void		loop_debug(t_elems elems);
t_elems		init_mlx(t_elems elems);
void		clean_mlx(t_num_mlx mlx_info);
void		print_elems_map(t_elems *elems);

//raycasting
int				main_loop(t_elems *elems);
void			calc(t_elems *elems);
void			draw_line(t_elems *elems, int x);
unsigned int	get_pixel_color(t_data *data, int x, int y);
//static int		get_w_dir(t_elems *elems);
void			put_pixel(t_data *data, int y, int x, int color);
//static void		draw_iteration(t_elems *elems, int x);
//static void		get_lineinfo(t_elems *elems);
char	*ft_strchr(const char *s, int c);
int	save_texture(t_elems *elems);
bool	load_image(t_elems *elems, char *line, int index);
//bool	is_cardinal_valid(char *line, int index);
void	get_dist(t_elems *elems);

//key_hooks
int		key_press(int keycode, t_elems *elems);
int		key_release(int keycode, t_elems *elems);
int		is_wall(char c);
bool	key_w(t_elems *elems, bool reload);
bool	key_s(t_elems *elems, bool reload);
bool	key_d(t_elems *elems, bool reload);
bool	key_a(t_elems *elems, bool reload);
int		move(t_elems *elems);

int pressed_key(int keycode, t_elems *elems);

#endif
