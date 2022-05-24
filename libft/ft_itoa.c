/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guda-sil@student.42sp.org.br <guda-sil@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 23:53:23 by guda-sil@st       #+#    #+#             */
/*   Updated: 2022/05/23 23:40:48 by guda-sil@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	size_t	ft_find_size(long int n);

char	*ft_itoa(int n)
{
	char		*str;
	size_t		size;
	long int	nb;
	size_t		i;

	nb = n;
	size = ft_find_size(nb);
	str = (char *) calloc(size, sizeof(char));
	if (nb == 0)
		str[0] = '0';
	if (!str)
		return (NULL);
	i = size - 1;
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	while (nb > 0)
	{
		str[--i] = (nb % 10) + '0';
		nb = nb / 10;
	}
	str[size - 1] = '\0';
	return (str);
}

static	size_t	ft_find_size(long int n)
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
