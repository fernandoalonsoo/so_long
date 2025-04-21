/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:00:00 by fernando          #+#    #+#             */
/*   Updated: 2025/04/10 19:00:02 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	flood(char **grid, int x, int y, t_flood *info);
int		is_valid_position(char **grid, int x, int y, t_flood *info);

int	flood_fill(t_map *map, char **copy)
{
	t_flood	info;

	info.collectibles = map->collectible_count;
	info.exits = map->exit_count;
	info.width = map->width;
	info.height = map->height;
	flood(copy, map->player_x, map->player_y, &info);
	free_map(copy);
	return (info.collectibles == 0 && info.exits == 0);
}

void	flood(char **grid, int x, int y, t_flood *info)
{
	char	c;

	if (!is_valid_position(grid, x, y, info))
		return ;
	c = grid[y][x];
	if (c == 'C')
		info->collectibles--;
	if (c == 'E')
	{
		info->exits--;
		grid[y][x] = '1';
		return ;
	}
	grid[y][x] = 'V';
	flood(grid, x - 1, y, info);
	flood(grid, x + 1, y, info);
	flood(grid, x, y + 1, info);
	flood(grid, x, y - 1, info);
}

int	is_valid_position(char **grid, int x, int y, t_flood *info)
{
	char	c;

	if (x <= 0 || info->width <= x)
		return (0);
	if (y <= 0 || info->height <= y)
		return (0);
	c = grid[y][x];
	if (c == 'V' || c == '1')
		return (0);
	return (1);
}
