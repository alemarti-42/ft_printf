/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:08:03 by alemarti          #+#    #+#             */
/*   Updated: 2021/08/11 13:22:39 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_chr(int ascii, t_format *format)
{
	char	c;

	c = (char)ascii;
	if (!check_format_char(format))
		return (-1);
	if (format->flags == '-')
		write(1, &c, 1);
	padding(' ', format->width - 1);
	if (format->flags == 0)
		write(1, &c, 1);
	if (format->width <= 0)
	{
		return (1);
	}
	return (format->width);
}

int	check_format_char(t_format *format)
{
	if (format->flags != '-' && format->flags)
		return (0);
	if (format->precision != -1)
		return (0);
	if (format->datatype != 'c')
		return (0);
	return (1);
}
