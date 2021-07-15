/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:52:56 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/14 20:23:50 by alemarti         ###   ########.fr       */
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
	if (!check_format_string(format))
		return (-1);
	if (format->precision >= 0 && len > format->precision)
		len = format->precision;
	pre_padding = format->width  - len;
	pre_padding *= (pre_padding > 0);
	post_padding = 0;
	if (format->flags == '-')
	{
		post_padding = pre_padding;
		pre_padding = 0;
	}
	aux = ft_substr(str, 0, len);
	ft_padding(' ', pre_padding);
	ft_putstr_fd(aux, 1);
	ft_padding(' ', post_padding);
	free(aux);
//	printf("\n[print_str]len:%dpre:%dpost:%d\n", len, pre_padding, post_padding);
	return(len + pre_padding + post_padding);

}

int		check_format_string(t_format *format)
{
//	test_print_format_struct(format);
	if (format->flags != '-' && format->flags != 0)
		return (0);
	/*
	if (format->precision < 0)
		return (0);
		*/
	return (1);
	
}
