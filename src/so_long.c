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

/*
void	print_map(t_map *map)
{
	int	i = 0;

	while (i < map->height)
	{
		printf("%s\n", map->grid[i]);
		i++;
	}
}

void	print_copy(char **copy)
{
	int	i;

	i = 0;
	while (copy[i])
	{
		printf("%s\n", copy[i]);
		i++;
	}
}*/

int	main(int argc, char const *argv[])
{
	t_map	map;
	char	**copy;
	t_game	game;

	if (argc != 2)
		ft_error_exit("Error. Use: ./so_long <map.ber>\n", 2);
	if (!is_valid_extension(argv[1] +5))
		ft_error_exit("Error. The map should have the extension .ber\n", 2);
	load_map(argv[1], &map);
	copy = copy_map(map.grid, map.height);
	if (!(flood_fill(&map, copy)))
	{
		game.map = map;
		free_map_and_exit(&game.map, "The map has no solution\n", 2);
	}
	game_init(&game, &map);
	load_textures(&game);
	render_map(&game);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
