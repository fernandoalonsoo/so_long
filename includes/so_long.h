/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:58:22 by fealonso          #+#    #+#             */
/*   Updated: 2025/04/17 15:58:25 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "../src/libft/libft.h"
# include "../src/get_next_line/src/get_next_line.h"
# include "../src/ft_printf/ft_printf.h"
# include "../mlx/mlx.h"

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	int		player_x;
	int		player_y;
}	t_map;

typedef struct s_textures
{
	void	*player;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*collectible;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_textures	textures;
	t_map		map;
	int			tile_size;
	char		tile_under;
	int			steps;
}	t_game;

typedef struct s_flood
{
	int		collectibles;
	int		exits;
	int		width;
	int		height;
}	t_flood;

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307

//void	print_map(t_map *map);
//void	print_copy(char **copy);

// Funciones principales
void	load_map(const char *filename, t_map *map);
void	validate_map(t_map *map);
int		flood_fill(t_map *map, char **copy);

// Game settings
void	game_init(t_game *game, t_map *map);
void	load_textures(t_game *game);
void	render_map(t_game *game);
int		handle_input(int keycode, t_game *game);

// Funciones auxiliares
void	free_map_and_exit(t_map *map, char *msg, int code);
void	ft_error_exit(char *msg, int exit_code);
int		is_valid_extension(const char *filename);
char	**copy_map(char **original, int height);
int		ft_print_string(const char *str);
int		close_game(t_game *game);
void	free_map(char **grid);
void	free_textures(t_game *game);

#endif
