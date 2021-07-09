/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:08:53 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/09 19:31:33 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sort_format(va_list *args, t_format *format)
{
	if (format->datatype == 's')
	{
		return (ft_print_str(va_arg(*args, char *), format));
	}
	if (format->datatype == 'c')
		return (ft_print_chr(va_arg(*args, int), format));
	if (format->datatype == 'i' || format->datatype == 'd')
		return (ft_print_chr(va_arg(*args, int), format));
	return (0);
}

void	ft_padding(char c, int n)
{
	while (n > 0)
	{
		write (1, &c, 1);
		n--;
	}
}
