/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 19:08:03 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/09 19:43:27 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_chr(int ascii, t_format *format)
{
	char	c;

	c = (char)ascii;
	if (format->flags == '-')
	{
		
		write(1, &c, 1);
		ft_padding(' ', format->width - 1);
	}
	else
	{
		ft_padding(' ', format->width - 1);
		write(1, &c, 1);
	}
	return (format->width);
}
