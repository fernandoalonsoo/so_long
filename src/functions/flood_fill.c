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

void	flood(char **grid, int x, int y, int *collectible_count,
			int *exit_count, int width, int height);
int		is_valid_position(char **grid, int x, int y,
			int width, int height);

int	flood_fill(t_map *map, char **copy,
		int collectible_count, int exit_count)
{
	flood(copy, map -> player_x, map -> player_y, &collectible_count,
		&exit_count, map -> width, map -> height);
	if (!(collectible_count == 0 && exit_count != map -> exit_count))
		return (0);
	return (1);
}

void	flood(char **grid, int x, int y, int *collectible_count,
		int *exit_count, int width, int height)
{
	char	c;

	if (!(is_valid_position(grid, x, y, width, height)))
		return ;
	c = grid[y][x];
	if (c == 'C')
		*collectible_count -= 1;
	if (c == 'E')
		*exit_count -= 1;
	grid[y][x] = 'V';
	flood(grid, x - 1, y, collectible_count, exit_count, width, height);
	flood(grid, x + 1, y, collectible_count, exit_count, width, height);
	flood(grid, x, y + 1, collectible_count, exit_count, width, height);
	flood(grid, x, y - 1, collectible_count, exit_count, width, height);
}

int	is_valid_position(char **grid, int x, int y, int width, int height)
{
	char	c;

	if (x <= 0 || width <= x)
		return (0);
	if (y <= 0 || height <= y)
		return (0);
	c = grid[y][x];
	if (c == 'V' || c == '1')
		return (0);
	return (1);
}
