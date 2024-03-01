/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:15:46 by ede-siga          #+#    #+#             */
/*   Updated: 2024/03/01 12:52:49 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_t_textures(t_textures *textures, t_elems elems)
{
	t_textures	*temp;

	if (!textures)
		return ;
	temp = textures->next;
	while (textures)
	{
		if (textures->path)
			free(textures->path);
		if (textures->img && elems.mlx.server)
			mlx_destroy_image(elems.mlx.server, textures->img);
		free(textures);
		textures = temp;
		if (textures)
			temp = textures->next;
	}
}

t_textures	*make_first_text(t_textures *textures, char *str)
{
	textures = malloc(sizeof(t_textures));
	if (!textures)
		return (NULL);
	textures->img = NULL;
	textures->next = NULL;
	textures->id = str;
	textures->path = NULL;
	return (textures);
}

t_textures	*make_id_text(t_textures *textures, char *str)
{
	t_textures	*temp;
	t_textures	*node;

	if (!textures)
		return (make_first_text(textures, str));
	temp = textures;
	while (temp->next)
		temp = temp->next;
	node = malloc(sizeof(t_textures));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->path = NULL;
	node->img = NULL;
	node->id = str;
	temp->next = node;
	return (textures);
}

t_textures	*make_text_id(void)
{
	t_textures	*textures;

	textures = NULL;
	textures = make_id_text(textures, "NO");
	textures = make_id_text(textures, "SO");
	textures = make_id_text(textures, "WE");
	textures = make_id_text(textures, "EA");
	return (textures);
}
