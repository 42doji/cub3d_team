/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doji <doji@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 21:30:00 by doji              #+#    #+#             */
/*   Updated: 2025/02/13 23:15:49 by doji             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_wall_pixels(t_game *game, t_ray *ray, int x, double wall_x)
{
	int				tex_num;
	int				tex_x;
	int				y;
	unsigned int	color;

	tex_num = get_texture_number(ray);
	tex_x = (int)(wall_x * game->map->texture[tex_num].img.width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || \
		(ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = game->map->texture[tex_num].img.width - tex_x - 1;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		color = get_texture_color(&game->map->texture[tex_num].img,
				tex_x,
				((y - WINDOW_HEIGHT / 2 + ray->line_height / 2)
					* game->map->texture[tex_num].img.height)
				/ ray->line_height);
		put_pixel(&game->img, x, y, color);
		y++;
	}
}

void	draw_wall_line(t_game *game, t_ray *ray, int x)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	draw_wall_pixels(game, ray, x, wall_x);
}
