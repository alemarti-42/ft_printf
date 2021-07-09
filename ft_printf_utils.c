/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:08:53 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/09 15:26:22 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sort_format(va_list *args, t_format *format)
{
	if (format->datatype == 's' || format->datatype == 'c')
	{
		return (ft_print_str(va_arg(*args, char *), format));
	}
	if (format->datatype == 'i' || format->datatype == 'd')
		return (ft_print_str(ft_itoa(va_arg(*args, int)), format));
	return (0);
}

int		ft_print_str(char *str, t_format *format)
{
	int	pre_padding;
	int	post_padding;
	int	len;
	char *aux;

	len = ft_strlen(str);
	if (len > format->precision && format->precision >= 0)
		len = format->precision;
	pre_padding = format->width  - len;
	post_padding = 0;
	if (format->flags == '-')
	{
		post_padding = pre_padding;
		pre_padding = 0;
	}
	aux = ft_substr(str, 0, format->precision);
	ft_padding(' ', pre_padding);
	ft_putstr_fd(aux, 1);
	ft_padding(' ', post_padding);
	free(aux);
	return(len + pre_padding + post_padding);

}


void	ft_padding(char c, int n)
{
	while (n > 0)
	{
		write (1, &c, 1);
		n--;
	}
}
