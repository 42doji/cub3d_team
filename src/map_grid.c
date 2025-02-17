/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:30:00 by doji              #+#    #+#             */
/*   Updated: 2025/02/09 00:50:28 by hisong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**allocate_grid(int height)
{
	char	**grid;

	grid = (char **)malloc(sizeof(char *) * (height + 1));
	if (!grid)
		error_handler(MALLOC_ERROR, NULL, NULL);
	return (grid);
}

static void	fill_grid(char **grid, char **lines, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		if (!init_grid_row(grid, i, map->width, map))
			return ;
		j = 0;
		while (lines[i][j] && j < map->width)
		{
			grid[i][j] = lines[i][j];
			j++;
		}
		i++;
	}
	grid[map->height] = NULL;
}

char	**create_map_grid(char **lines, int height, int width, t_map *map)
{
	char	**grid;

	if (!lines || height <= 0 || width <= 0)
		return (NULL);
	grid = allocate_grid(height);
	if (!grid)
		return (NULL);
	fill_grid(grid, lines, map);
	return (grid);
}
