/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:08:53 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/13 21:38:13 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sort_format(va_list *args, t_format *format)
{
	if (format->datatype == '%')
		return (ft_print_str("%", format));
	if (format->datatype == 's')
	{
		return (ft_print_str(va_arg(*args, char *), format));
	}
	if (format->datatype == 'c')
		return (ft_print_chr(va_arg(*args, int), format));
	if (format->datatype == 'i' || format->datatype == 'd' || \
		   	format->datatype == 'u')
		return (ft_print_int(va_arg(*args, int), format));
	if (format->datatype == 'x')
		return (ft_print_hexa(va_arg(*args, unsigned long), format));
	return (-1);
}

void	ft_padding(char c, int n)
{
	while (n > 0)
	{
		write (1, &c, 1);
		n--;
	}
}
