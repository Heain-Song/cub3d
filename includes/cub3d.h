/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesong <hesong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 07:53:34 by hesong            #+#    #+#             */
/*   Updated: 2024/01/09 14:38:00 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstrfd(char *str, int fd);
int		file_checker(char *str);
char	*basic_gnl(int fd);
int		ft_strlen(char *str);
char	*ft_strcpy(char *src, char *dest);
#endif
