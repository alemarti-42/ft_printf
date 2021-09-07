/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:08:03 by alemarti          #+#    #+#             */
/*   Updated: 2021/09/07 12:47:37 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_chr(int ascii, t_format *format)
{
	char	c;

	c = (char)ascii;
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
