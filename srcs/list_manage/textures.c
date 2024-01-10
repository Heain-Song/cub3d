/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-siga <ede-siga@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:15:46 by ede-siga          #+#    #+#             */
/*   Updated: 2024/01/10 09:36:25 by ede-siga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_t_textures(t_textures *textures)
{
	t_textures	*temp;

	temp = textures->next;
	while (textures)
	{
		free(textures->path);
		free(textures);
		textures = temp;
		if (textures)
			temp = textures->next;
	}
}

t_textures	*make_id_text(t_textures *textures, char *str)
{
	t_textures	*temp;
	t_textures	*node;

	if (!textures)
	{
		textures = malloc(sizeof(t_textures));
		textures->next = NULL;
		textures->id = str;
		textures->path = NULL;
		return (textures);
	}
	temp = textures;
	while (temp->next)
		temp = temp->next;
	node = malloc(sizeof(t_textures));
	node->next = NULL;
	node->path = NULL;
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
