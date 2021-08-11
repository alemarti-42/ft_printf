/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:52:56 by alemarti          #+#    #+#             */
/*   Updated: 2021/08/11 14:57:47 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str, t_format *format)
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
	if (format->flags == '0')
		filling = '0';
	set_padding(&pre_padding, &post_padding, &len, format);
	aux = ft_substr(str, 0, len);
	padding(filling, pre_padding);
	ft_putstr_fd(aux, 1);
	padding(filling, post_padding);
	free(aux);
	return (len + pre_padding + post_padding);
}

void	set_padding(int *pre_padding, int *post_padding, int *len, \
		t_format *format)
{
	if (format->precision >= 0 && *len > format->precision)
		*len = format->precision;
	*pre_padding = format->width - *len;
	*pre_padding *= (*pre_padding > 0);
	*post_padding = 0;
	if (format->flags == '-')
	{
		*post_padding = *pre_padding;
		*pre_padding = 0;
	}
}

int	check_format_string(t_format *format)
{
	if (format->flags == '0' || format->flags == '-' || \
			format->flags == ' ' || !format->flags)
		return (1);
	return (0);
}
