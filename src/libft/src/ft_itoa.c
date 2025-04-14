/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:09:27 by fealonso          #+#    #+#             */
/*   Updated: 2024/09/23 00:04:39 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	get_len(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	exception(char *p, int len)
{
	unsigned int	n;

	p[0] = '-';
	n = 2147483648;
	while (n != 0)
	{
		p[--len] = n % 10 + 48;
		n /= 10;
	}
}

static void	put_digits(char *p, unsigned int aux, int len)
{
	while (aux)
	{
		p[--len] = aux % 10 + '0';
		aux /= 10;
	}
}

char	*ft_itoa(int n)
{
	char			*p;
	int				len;
	unsigned int	aux;

	len = get_len(n);
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	p[len] = '\0';
	if (n == -2147483648)
	{
		exception(p, len);
		return (p);
	}
	if (n == 0)
		p[0] = '0';
	if (n < 0)
	{
		p[0] = '-';
		aux = -n;
	}
	else
		aux = n;
	put_digits(p, aux, len);
	return (p);
}
