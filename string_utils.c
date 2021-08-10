/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:52:56 by alemarti          #+#    #+#             */
/*   Updated: 2021/08/10 16:46:40 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_str(char *str, t_format *format)
{
	int		pre_padding;
	int		post_padding;
	int		len;
	char	*aux;
	char	filling;

	filling = ' ';
	len = ft_strlen(str);
	if (!check_format_string(format))
		return (-1);
	if (format->precision >= 0 && len > format->precision)
		len = format->precision;
	if (format->flags == '0')
		filling = '0';
	pre_padding = format->width  - len;
	pre_padding *= (pre_padding > 0);
	post_padding = 0;
	if (format->flags == '-')
	{
		post_padding = pre_padding;
		pre_padding = 0;
	}
	aux = ft_substr(str, 0, len);
	ft_padding(filling, pre_padding);
	ft_putstr_fd(aux, 1);
	ft_padding(filling, post_padding);
	free(aux);
//	printf("\n[print_str]len:%dpre:%dpost:%d\n", len, pre_padding, post_padding);
	return(len + pre_padding + post_padding);

}

int		check_format_string(t_format *format)
{
//	test_print_format_struct(format);
	if (format->flags == '0' || format->flags == '-' || !format->flags )
		return (1);
//	if (format->flags == '#' && (format->datatype == 'x' || format->datatype == 'X'))
//		return (1);
	/*
	if (format->precision < 0)
		return (0);
		*/
	return (0);
	
}
