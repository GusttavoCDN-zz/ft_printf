/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guda-sil@student.42sp.org.br <guda-sil@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:12:27 by guda-sil@st       #+#    #+#             */
/*   Updated: 2022/05/26 23:27:24 by guda-sil@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_pointer(unsigned long address)
{
	char	*number;
	int		number_len;
	int		i;

	i = 0;
	if (!address)
		return (write(1, "(nil)", sizeof(char) * 5));
	number_len = write(1, "0x", sizeof(char) * 2);
	number = (char *) malloc((ft_calc_hex_length(address) + 1) * sizeof(char));
	while (address)
	{
		number[i] = ft_decimal_to_hex(address % 16, 'x');
		address = address / 16;
		i++;
	}
	number[i] = '\0';
	number_len += ft_putstr_reversed(number);
	free(number);
	return (number_len);
}
