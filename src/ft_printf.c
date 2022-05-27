/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guda-sil@student.42sp.org.br <guda-sil@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:22:01 by guda-sil@st       #+#    #+#             */
/*   Updated: 2022/05/27 00:13:23 by guda-sil@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	print_format(va_list arguments, const char *format, int *size);
static	int	verify_arguments(va_list arguments, const char *format, int size);

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		size;

	va_start(arguments, format);
	size = 0;
	print_format(arguments, format, &size);
	va_end(arguments);
	return (size - 1);
}

static	void	print_format(va_list arguments, const char *format, int *size)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			*size += verify_arguments(arguments, format, i + 1);
			i++;
		}
		else
			*size += ft_putchar_int(format[i]);
		i++;
	}
}

static int	verify_arguments(va_list arguments, const char *format, int i)
{
	if (format[i] == 'c')
		return (ft_putchar_int(va_arg(arguments, int)) + i);
	else if (format[i] == 's')
		return (ft_putstr_int(va_arg(arguments, char *)) + i);
	else if (format[i] == 'd' || format[i] == 'i')
		return (ft_putnbr_int(va_arg(arguments, int)) + i);
	else if (format[i] == 'u')
		return (ft_print_unsigned_int(va_arg(arguments, unsigned int)) + i);
	else if (format[i] == 'p')
		return (ft_print_pointer(va_arg(arguments, unsigned long)) + i);
	else if (format[i] == 'x')
		return (ft_print_hex_int(va_arg(arguments, unsigned int), 'x') + i);
	else if (format[i] == 'X')
		return (ft_print_hex_int(va_arg(arguments, unsigned int), 'X') + i);
	else if (format[i] == '%')
		return (ft_putchar_int('%') + i);
	return (0);
}
