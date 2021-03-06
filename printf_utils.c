/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:08:53 by alemarti          #+#    #+#             */
/*   Updated: 2021/08/11 13:17:46 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sort_format(va_list *args, t_format *format)
{
	if (format->datatype == '%')
		return (print_str("%", format));
	if (format->datatype == 's')
		return (print_str(va_arg(*args, char *), format));
	if (format->datatype == 'c')
		return (print_chr(va_arg(*args, int), format));
	if (format->datatype == 'i' || format->datatype == 'd')
		return (print_int(va_arg(*args, int), format));
	if (format->datatype == 'u')
		return (print_int(va_arg(*args, unsigned int), format));
	if (format->datatype == 'x' || format->datatype == 'X')
		return (print_hexa(va_arg(*args, unsigned int), format));
	if (format->datatype == 'p')
		return (print_pointer(va_arg(*args, unsigned long), format));
	return (-1);
}

int	padding(char c, int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		write (1, &c, 1);
		n--;
		i++;
	}
	return (i);
}
