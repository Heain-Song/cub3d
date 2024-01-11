/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 07:53:34 by hesong            #+#    #+#             */
/*   Updated: 2024/01/11 10:52:58 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

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
}	t_elems;

int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstrfd(char *str, int fd);
int			file_checker(char *str);
char		*basic_gnl(int fd, int *read_ammount);
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
t_elems		gt_str_atrib(t_elems elems, char *str);
t_elems		assign_which_elem(char *str, int nb, t_elems elems);
void		free_elems(t_elems elems);
						//debug//
void display_textures_list (t_textures *head);

#endif
