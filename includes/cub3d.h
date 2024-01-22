/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 07:53:34 by hesong            #+#    #+#             */
/*   Updated: 2024/01/22 15:59:42 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct	s_num_mlx
{
	void	*server;
	void	*window;
}t_num_mlx;

typedef struct s_textures
{
	char				*id;
	char				*path;
	struct s_textures	*next;
}	t_textures;

typedef struct s_elems
{
	t_textures	*textures;
	int			f_colors[3];
	int			c_colors[3];
	char		**map;
	int			is_full;
	int			error;
	char		**elem_names;
	int			did_c;
	int			did_f;
	int			found_player;
	t_num_mlx	mlx_l;
}	t_elems;

int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstrfd(char *str, int fd);
int			file_checker(char *str);
char		*basic_gnl(int fd, int *read_ammount, int keep_nl);
int			ft_strlen(char *str);
char		*ft_strcpy(char *src, char *dest);
t_textures	*make_text_id(void);
void		free_t_textures(t_textures *textures);
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
int			str_check_num_ammount(char *str);
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
t_elems		check_textures(t_elems elems, char *str);
//debug//
void		display_textures_list(t_textures *head);
void		print_map(char **map);
void		loop_debug(t_elems elems);
t_elems		init_mlx(t_elems elems);
void		clean_mlx(t_num_mlx mlx_info);
#endif
