/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guda-sil@student.42sp.org.br <guda-sil@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:22:01 by guda-sil@st       #+#    #+#             */
/*   Updated: 2022/05/24 13:27:15 by guda-sil@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

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
			*size += verify_arguments(arguments, format, *size + 1);
			i++;
		}
		else
			*size += ft_putchar_int(format[i]);
		i++;
	}
}

static int	verify_arguments(va_list arguments, const char *format, int size)
{
	if (format[size] == 'c')
		return (ft_putchar_int(va_arg(arguments, int)) + size);
	else if (format[size] == 's')
		return (ft_putstr_int(va_arg(arguments, char *)) + size);
	else if (format[size] == 'd' || format[size] == 'i')
		return (ft_putnbr_int(va_arg(arguments, int)) + size);
	else if (format[size] == 'u')
		return (ft_print_unsigned_int(va_arg(arguments, unsigned int)) + size);
	else if (format[size] == 'p')
		return (ft_print_pointer(va_arg(arguments, unsigned long)) + size);
	else if (format[size] == 'x')
		return (ft_print_hex_int(va_arg(arguments, unsigned int), 'x') + size);
	else if (format[size] == 'X')
		return (ft_print_hex_int(va_arg(arguments, unsigned int), 'X') + size);
	else if (format[size] == '%')
		return (ft_putchar_int('%') + size);
	return (0);
}
