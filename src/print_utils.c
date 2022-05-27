/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guda-sil@student.42sp.org.br <guda-sil@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:23:53 by guda-sil@st       #+#    #+#             */
/*   Updated: 2022/05/27 01:57:28 by guda-sil@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

int	ft_putchar_int(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_int(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", sizeof(char) * 6));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_int(int n)
{
	int		number_len;
	char	*number;

	number = ft_itoa(n);
	number_len = ft_putstr_int(number);
	free(number);
	return (number_len);
}

int	ft_putstr_reversed(char *str)
{
	int	i;
	int	bytes;

	bytes = ft_strlen(str);
	i = bytes - 1;
	while (i >= 0)
	{
		write(1, &str[i], sizeof(char) * 1);
		i--;
	}
	return (bytes);
}
