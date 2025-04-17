/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:58:16 by fealonso          #+#    #+#             */
/*   Updated: 2024/12/29 12:23:20 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_number(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_print_string(str);
	free(str);
	return (len);
}
