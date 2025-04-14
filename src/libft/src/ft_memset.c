/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:36:21 by fealonso          #+#    #+#             */
/*   Updated: 2024/09/25 14:52:38 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *) ptr;
	while (i < num)
	{
		p[i] = (char)value;
		i++;
	}
	return (ptr);
}
