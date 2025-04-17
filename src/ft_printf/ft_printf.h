/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <fealonso@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 19:52:12 by fealonso          #+#    #+#             */
/*   Updated: 2024/12/28 19:54:08 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

// Prototipo de la función principal ft_printf
int		ft_printf(char const *str, ...);

// Prototipos adicionales 
int		ft_print_char(char c);
int		ft_print_string(const char *str);
int		ft_print_pointer(void *ptr);
int		ft_print_number(int n);
int		ft_print_unsigned(unsigned long n);
int		ft_print_hex(unsigned long n, char format);

// Prototipos auxiliares
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);

// Macros
# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

#endif
