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
	mlx_clear_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	handle_input(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
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
	if (next_tile == '1')
		return ;
	if (next_tile == 'C')
		game->map.collectible_count--;
	if (next_tile == 'E' && game->map.collectible_count == 0)
	{
		game->steps++;
		exit(0);
	}
	if (game->map.grid[game->map.player_y][game->map.player_x] != 'E')
		game->map.grid[game->map.player_y][game->map.player_x] = '0';
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	game->map.grid[new_y][new_x] = 'P';
	game->steps++;
	ft_printf("Steps: %d\n", game->steps);
	render_map(game);
}
