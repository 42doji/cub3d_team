/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:20:59 by doji              #+#    #+#             */
/*   Updated: 2025/01/31 15:21:00 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_map	*create_map(void)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		error_handler(MALLOC_ERROR, NULL, NULL);
		return (NULL);
	}
	return (map);
}

static void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->grid && map->grid[i])
	{
		printf("%s\n", map->grid[i]);
		i++;
	}
}

t_map	*init_map(char *file_name)
{
	t_map	*map;
	int		fd;

	map = create_map();
	if (!map)
		return (NULL);
	if (!init_map_values(map))
		return (free_map_resources(NULL, map), NULL);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		free_map_resources(NULL, map);
		error_handler(OPEN_ERROR, NULL, NULL);
		return (NULL);
	}
	if (!parse_cub_file(file_name, map))
		return (close(fd), NULL);
	close(fd);
	print_map(map);
	return (map);
}
