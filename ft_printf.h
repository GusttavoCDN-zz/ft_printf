/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guda-sil@student.42sp.org.br <guda-sil@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:19:21 by guda-sil@st       #+#    #+#             */
/*   Updated: 2022/05/23 19:21:58 by guda-sil@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/**
 * @brief This function Write formatted output to stdout.
 *
 * @param format The format string
 * @param ...  The arguments
 * @return The size of the string written
 */
int ft_printf(const char *format, ...);

#endif
