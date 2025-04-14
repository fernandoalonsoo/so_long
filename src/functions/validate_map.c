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

static int	check_sorroundings(char **grid, int width, int height);
static int	is_valid_char(char c);
static void	validate_position(t_map *map, char c, int width, int height);


void validate_map(t_map *map)
{
	int		i;
	int		j;
	char	**grid;

	i = 0;
	grid = map -> grid;
	if (!check_sorroundings(grid, map -> width, map -> height))
		ft_error_exit("Error. El mapa no esta rodeado de muros\n", 2);
	while (i < map -> height)
	{
		j = 0;
		while (j < map->width && is_valid_char(grid[i][j]))
		{
			validate_position(map, grid[i][j], i, j);
			j++;
		}
		if (j < map->width && is_valid_char(grid[i][j]))
			ft_error_exit("Error. Casilla no valida\n", 2);
		i++;
	}
	if (!(map -> player_count))
		ft_error_exit("Error. Tiene que 1 player\n", 2);
	if (!(map -> exit_count) || !(map -> collectible_count))
		ft_error_exit("Error. Tiene que haber al menos un exit y un collectible\n", 2);
}

static int	check_sorroundings(char **grid, int width, int height)
{
	int i;
	int j;

	i = 0;
	while (i < height)
	{
		if (i == 0 || i == height - 1)
		{
			j = 0;
			while (j < width)
			{
				if (grid[i][j] != '1')
					return (0);
				j++;
			}
		}
		if (i != 0 && i != height - 1)
		{
			if (grid[i][0] != '1' || grid[i][width - 1] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

static int	is_valid_char(char c)
{
	return (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C');
}

static void	validate_position(t_map *map, char c, int width, int height)
{
	if (c == '1' || c == '0')
		return ;
	else if(c == 'P')
	{
		if (map -> player_count == 0)
		{
			map -> player_x = width;
			map -> player_y = height;
			map -> player_count += 1;
		}
		else
			ft_error_exit("Error. Solo puede haber exactamente un jugador\n", 2);
	}
	else if(c == 'E')
		map -> exit_count += 1;
	else if(c == 'C')
		map -> collectible_count += 1;
}
