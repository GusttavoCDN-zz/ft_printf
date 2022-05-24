/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guda-sil@student.42sp.org.br <guda-sil@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:12:27 by guda-sil@st       #+#    #+#             */
/*   Updated: 2022/05/24 12:44:42 by guda-sil@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


static int calc_hex_length(unsigned long nb)
{
	int		len;

	len = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

static char decimal_converter_to_hex(char digit, char type)
{
	int capitalize;

	capitalize = 0;
	if (type == 'X')
		capitalize = 32;
	if (digit > 9)
	{
		if (digit == 10)
			return ('a' - capitalize);
		else if (digit == 11)
			return ('b' - capitalize);
		else if (digit == 12)
			return ('c' - capitalize);
		else if (digit == 13)
			return ('d' - capitalize);
		else if (digit == 14)
			return ('e' - capitalize);
		else if (digit == 15)
			return ('f' - capitalize);
	}
	else
		return (digit + '0');
	return (0);

}

int	ft_print_pointer(unsigned long address)
{
	char *number;
	int number_len;
	int i;

	i = 0;
	if (!address)
		return (write(1, "(nil)", sizeof(char) * 5));
	number_len = write(1, "0x", sizeof(char) * 2);
	number = (char *) malloc((calc_hex_length(address) + 1) * sizeof(char));
	while (address)
	{
		number[i] = decimal_converter_to_hex(address % 16, 'x');
		address = address / 16;
		i++;
	}
	number[i] = '\0';
	number_len += ft_putstr_reversed(number);
	free(number);
	return (number_len);
}

int ft_print_hex_integer(unsigned int nb, char type)
{
	char *number;
	int number_len;
	int i;

	i = 0;
	if (!nb)
		return (write(1, "0", sizeof(char)));
	number = (char *) malloc((calc_hex_length(nb) + 1) * sizeof(char));
	while (nb)
	{
		number[i] = decimal_converter_to_hex(nb % 16, type);
		nb = nb / 16;
		i++;
	}
	number[i] = '\0';
	number_len += ft_putstr_reversed(number);
	free(number);
	return (number_len);
}
