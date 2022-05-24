/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guda-sil@student.42sp.org.br <guda-sil@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:20:30 by guda-sil@st       #+#    #+#             */
/*   Updated: 2022/05/24 12:34:54 by guda-sil@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	size_t	ft_find_size(unsigned int n);

char	*ft_utoa(unsigned int n)
{
	char		*str;
	size_t		size;
	size_t		i;

	size = ft_find_size(n);
	str = (char *) calloc(size, sizeof(char));
	if (n == 0)
		str[0] = '0';
	if (!str)
		return (NULL);
	i = size - 1;
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (n > 0)
	{
		str[--i] = (n % 10) + '0';
		n = n / 10;
	}
	str[size - 1] = '\0';
	return (str);
}

static	size_t	ft_find_size(unsigned int n)
{
	size_t	i;

	i = 1;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_print_unsigned_int(unsigned int n)
{
	int		number_len;
	char	*number;

	number_len = 0;
	if (n == 0)
		number_len += write(1, "0", 1);
	else
	{
		number = ft_utoa(n);
		number_len += ft_putstr_int(number);
		free(number);
	}
	return (number_len);
}
