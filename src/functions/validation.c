/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:58:48 by fernando          #+#    #+#             */
/*   Updated: 2025/04/10 18:58:55 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_map_and_exit(t_map *map, char *msg, int code)
{
	free_map(map->grid);
	get_next_line(-1);
	ft_error_exit(msg, code);
}

void	ft_error_exit(char *msg, int exit_code)
{
	if (exit_code == 1)
		perror(msg);
	else
		ft_putstr_fd(msg, 2);
	get_next_line(-1);
	exit(exit_code);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int	is_valid_extension(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	return (ft_strcmp(filename + len - 4, ".ber") == 0);
}
