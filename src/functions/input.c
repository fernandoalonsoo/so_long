/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:13:53 by fealonso          #+#    #+#             */
/*   Updated: 2025/04/17 15:13:56 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_player(t_game *game, int dx, int dy);

int	close_game(t_game *game)
{
	free_textures(game);
	free_map(game->map.grid);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	handle_input(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	else if (keycode == KEY_W)
		move_player(game, 0, -1);
	else if (keycode == KEY_S)
		move_player(game, 0, 1);
	else if (keycode == KEY_A)
		move_player(game, -1, 0);
	else if (keycode == KEY_D)
		move_player(game, 1, 0);
	return (0);
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	next_tile;

	new_x = game->map.player_x + dx;
	new_y = game->map.player_y + dy;
	next_tile = game->map.grid[new_y][new_x];
	game->steps++;
	if (next_tile == '1')
		return ;
	if (next_tile == 'C')
		game->map.collectible_count--;
	if (next_tile == 'E' && game->map.collectible_count == 0)
	{
		ft_printf("Steps: %d\n", game->steps);
		close_game(game);
	}
	if (game->map.grid[game->map.player_y][game->map.player_x] != 'E')
		game->map.grid[game->map.player_y][game->map.player_x] = '0';
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	if (next_tile != 'E')
		game->map.grid[new_y][new_x] = 'P';
	ft_printf("Steps: %d\n", game->steps);
	render_map(game);
}
