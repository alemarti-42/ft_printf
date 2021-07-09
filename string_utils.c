/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:52:56 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/09 18:55:05 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
