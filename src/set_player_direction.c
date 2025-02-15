/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_direction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:30:00 by doji              #+#    #+#             */
/*   Updated: 2025/02/14 10:58:34 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_vector(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
	}
	else if (direction == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
	}
	else if (direction == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
	}
	else if (direction == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
	}
}

static void	set_camera_plane(t_player *player, char direction)
{
	if (direction == 'N' || direction == 'S')
	{
		if (direction == 'N')
			player->plane_x = 0.66;
		else
			player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (direction == 'E' || direction == 'W')
	{
		player->plane_x = 0;
		if (direction == 'E')
			player->plane_y = 0.66;
		else
			player->plane_y = -0.66;
	}
}

void	set_player_direction(t_game *game, char direction)
{
	set_player_vector(&game->player, direction);
	set_camera_plane(&game->player, direction);
}
