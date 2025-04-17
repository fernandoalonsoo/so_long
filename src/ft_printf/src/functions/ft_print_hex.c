/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:58:04 by fealonso          #+#    #+#             */
/*   Updated: 2024/12/29 10:58:11 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

static char	*convert_hexadecimal(unsigned long n, char format);

int	ft_print_hex(unsigned long n, char format)
{
	char	*str;
	int		i;

	i = 0;
	if (!n)
		return (ft_print_char('0'));
	str = convert_hexadecimal(n, format);
	if (!str)
		return (i);
	i += ft_print_string(str);
	free(str);
	return (i);
}

static int	get_hex_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static char	*convert_hexadecimal(unsigned long n, char format)
{
	char	*aux;
	int		len;

	len = get_hex_len(n);
	aux = malloc(len + 1);
	if (!aux)
		return (NULL);
	aux[len] = '\0';
	if (format == 'x')
	{
		while (n != 0)
		{
			aux[--len] = HEX_LOWER[n % 16];
			n /= 16;
		}
	}
	else
	{
		while (n != 0)
		{
			aux[--len] = HEX_UPPER[n % 16];
			n /= 16;
		}
	}
	return (aux);
}
