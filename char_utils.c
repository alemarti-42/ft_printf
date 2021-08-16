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
	int		i;

	i = 0;
	c = (char)ascii;
	if (format->flags == '-')
		write(1, &c, 1);
	while (i++ < format->width - 1)
	{
		write (1, " ", 1);
	}
	if (format->flags != '-')
		write(1, &c, 1);
	if (format->width <= 0)
	{
		return (1);
	}
	return (format->width);
}
