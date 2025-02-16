/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hisong <hisong@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 00:48:21 by hisong            #+#    #+#             */
/*   Updated: 2025/02/09 00:48:21 by hisong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int validate_texture(const char *line)
{
	int fd;
	char *path;
	char **split;

	trim_line_endings((char *) line);
	split = ft_split(line, ' ');
	if (!split || !split[1] || split[2])
	{
		free_split(split);
		return (0);
	}
	path = ft_strdup(split[1]);
	free_split(split);
	if (!path)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		return (0);
	}
	if (fd > 0)
		close(fd);
	free(path);
	path = NULL;
	return (1);
}

int	parse_texture(const char *line, t_map *map, int texture_index)
{
	char	**split;
	char	*path;

	if (!validate_texture(line))
		error_handler(TEXTURE_ERROR, NULL, map);
	trim_line_endings((char *)line);
	split = ft_split(line, ' ');
	if (!split || !split[1] || split[2])
	{
		free_split(split);
		error_handler(TEXTURE_ERROR, NULL, map);
		return (0);
	}
	if (map->texture[texture_index].path)
	{
		free_split(split);
		error_handler(DUPLICATE_KEY_ERROR, NULL, map);
		return (0);
	}
	path = ft_strdup(split[1]);
	free_split(split);
	if (!path)
		return (error_handler(MALLOC_ERROR, NULL, map), 0);
	map->texture[texture_index].path = path;
	return (1);
}
