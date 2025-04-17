/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:56:36 by fernando          #+#    #+#             */
/*   Updated: 2024/12/29 14:00:45 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf.h"

int	ft_print_pointer(void *ptr)
{
	if (!ptr)
		return (ft_print_string("(nil)"));
	return (ft_print_string("0x") + ft_print_hex((unsigned long)ptr, 'x'));
}
