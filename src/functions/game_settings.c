/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:01:23 by fernando          #+#    #+#             */
/*   Updated: 2025/04/10 19:01:28 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void game_init(t_game *game, t_map *map)
{
	game->tile_size = 32;
	game->steps = 0;
	game->map = *map;
	game->mlx = mlx_init();
	game->win = mlx_new_window(	game->mlx, game->map.width * game->tile_size,
		game->map.height * game->tile_size, "so_long");
}


void	load_textures(t_game *game)
{
	int	size;
	
	size = game->tile_size;
	game->textures.wall = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", &size, &size);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx, "assets/floor.xpm", &size, &size);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", &size, &size);
	game->textures.collectible = mlx_xpm_file_to_image(game->mlx, "assets/collectible.xpm", &size, &size);
	game->textures.player = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", &size, &size);
	if (!game->textures.wall || !game->textures.floor || !game->textures.exit
		|| !game->textures.collectible || !game->textures.player)
		ft_error_exit("Error al cargar las texturas\n", 2);
}

static void	*get_tile_img(t_game *game, char tile)
{
	if (tile == '1')
		return (game->textures.wall);
	if (tile == '0')
		return (game->textures.floor);
	if (tile == 'C')
		return (game->textures.collectible);
	if (tile == 'E')
		return (game->textures.exit);
	if (tile == 'P')
		return (game->textures.player);
	return (NULL);
}

void	render_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			img = get_tile_img(game, game->map.grid[y][x]);
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img, x * game->tile_size, y * game->tile_size);
			x++;
		}
		y++;
	}
}
