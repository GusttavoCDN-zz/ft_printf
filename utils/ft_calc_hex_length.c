/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_hex_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guda-sil@student.42sp.org.br <guda-sil@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:02:18 by guda-sil@st       #+#    #+#             */
/*   Updated: 2022/05/24 13:03:38 by guda-sil@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	calc_hex_length(unsigned long nb)
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
