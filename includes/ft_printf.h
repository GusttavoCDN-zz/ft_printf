/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guda-sil@student.42sp.org.br <guda-sil@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:19:21 by guda-sil@st       #+#    #+#             */
/*   Updated: 2022/05/26 23:26:03 by guda-sil@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/**
 * @brief This function Write formatted output to stdout.
 *
 * @param format The format string
 * @param ...  The arguments
 * @return The size of the string written
 */
int		ft_printf(const char *format, ...);
int		ft_putchar_int(char c);
int		ft_putstr_int(char *str);
int		ft_putnbr_int(int n);
char	*ft_itoa(int n);
int		ft_print_unsigned_int(unsigned int n);
int		ft_print_pointer(unsigned long address);
int		ft_putstr_reversed(char *str);
int		ft_print_hex_int(unsigned int nb, char type);
int		ft_calc_hex_length(unsigned long nb);
char	ft_decimal_to_hex(char digit, char type);

#endif
