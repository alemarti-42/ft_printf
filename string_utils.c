/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:52:56 by alemarti          #+#    #+#             */
/*   Updated: 2021/08/11 13:54:21 by alemarti         ###   ########.fr       */
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
	if (format->precision >= 0 && len > format->precision)
		len = format->precision;
	filling = '0' * (format->flags == '0');
	pre_padding = format->width - len;
	pre_padding *= (pre_padding > 0);
	post_padding = 0;
	post_padding = pre_padding * (format->flags == '-');
	pre_padding = 1 * (format->flags != '-');
	aux = ft_substr(str, 0, len);
	padding(filling, pre_padding);
	ft_putstr_fd(aux, 1);
	padding(filling, post_padding);
	free(aux);
	return (len + pre_padding + post_padding);
}

int	check_format_string(t_format *format)
{
	if (format->flags == '0' || format->flags == '-' || \
			format->flags == ' ' || !format->flags)
		return (1);
	return (0);
}
