#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "../src/libft/libft.h"
# include "../src/get_next_line/src/get_next_line.h"
# include "mlx.h"

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
	int			steps;
}	t_game;

#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_ESC 65307

//void	print_map(t_map *map);
//void	print_copy(char **copy);

// Funciones principales
void	load_map(const char *filename, t_map *map);
void 	validate_map(t_map *map);
int		flood_fill(t_map *map, char **copy, int collectible_count, int exit_count);

// Game settings
void	game_init(t_game *game, t_map *map);
void	load_textures(t_game *game);
void	render_map(t_game *game);
int		handle_input(int keycode, t_game *game);


// Funciones auxiliares
void	ft_error_exit(char *msg, int exit_code);
int		is_valid_extension(const char *filename);
char	**copy_map(char **original, int height);

#endif