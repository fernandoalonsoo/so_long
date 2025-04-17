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

static void	initialise_map(t_map *map);
static char	**append_line(char **lines, char *line, int count);
static void	check_width(t_map *map, char *line, int count);

void	load_map(const char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		count;

	initialise_map(map);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error_exit("open", 1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		check_width(map, line, count);
		map->grid = append_line(map->grid, line, count);
		line = get_next_line(fd);
		count++;
	}
	free(line);
	map->height = count;
	close(fd);
	validate_map(map);
}

static void	check_width(t_map *map, char *line, int count)
{
	if (count == 0)
		map->width = ft_strlen(line);
	if ((int)ft_strlen(line) != map->width)
	{
		get_next_line(-1);
		free(line);
		free_map(map->grid);
		ft_error_exit("Error. The map should be a rectangle\n", 2);
	}
}

static void	initialise_map(t_map *map)
{
	map -> grid = NULL;
	map -> width = 0;
	map -> height = 0;
	map -> player_count = 0;
	map -> exit_count = 0;
	map -> collectible_count = 0;
	map -> player_x = 0;
	map -> player_y = 0;
}

static char	**append_line(char **lines, char *line, int count)
{
	char	**array;
	int		i;

	array = malloc(sizeof(char *) * (count + 2));
	i = 0;
	while (i < count)
	{
		array[i] = ft_strdup(lines[i]);
		free(lines[i]);
		i++;
	}
	array[i] = ft_strdup(line);
	array[i + 1] = NULL;
	free(line);
	free(lines);
	return (array);
}

char	**copy_map(char **original, int height)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (height + 1));
	while (i < height)
	{
		copy[i] = ft_strdup(original[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
