/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:59:10 by fealonso          #+#    #+#             */
/*   Updated: 2024/12/29 14:02:41 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static char	*ft_unsigned_itoa(unsigned long n);

int	ft_print_unsigned(unsigned long n)
{
	char	*str;
	int		len;

	str = ft_unsigned_itoa(n);
	len = ft_print_string(str);
	free(str);
	return (len);
}

static int	get_len(unsigned long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	put_digits(char *p, unsigned long n, int len)
{
	while (n)
	{
		p[--len] = n % 10 + '0';
		n /= 10;
	}
}

static char	*ft_unsigned_itoa(unsigned long n)
{
	char			*p;
	int				len;

	len = get_len(n);
	p = malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	p[len] = '\0';
	if (n == 0)
		p[0] = '0';
	put_digits(p, n, len);
	return (p);
}
