#include "../../includes/so_long.h"

void	move_player(t_game *game, int dx, int dy);

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
	int	new_x = game->map.player_x + dx;
	int	new_y = game->map.player_y + dy;
	char	next_tile = game->map.grid[new_y][new_x];

	if (next_tile == '1')
		return; // no se puede mover a un muro

	if (next_tile == 'C')
		game->map.collectible_count--;
	if (next_tile == 'E' && game->map.collectible_count == 0)
	{
		printf("¡Ganaste en %d pasos!\n", game->steps);
		exit(0);
	}
	game->map.grid[game->map.player_y][game->map.player_x] = '0';
	game->map.grid[new_y][new_x] = 'P';
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	game->steps++;
	render_map(game);
}
