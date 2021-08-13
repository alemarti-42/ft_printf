/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:52:56 by alemarti          #+#    #+#             */
/*   Updated: 2021/08/11 21:08:54 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str, t_format *format)
{
	int		pre_padding;
	int		post_padding;
	int		len;
	char	*swap;
	char	filling;
	char	*pad;
	int		res;

res = 0;
	filling = ' ';
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (format->flags == '0')
		filling = '0';
	set_padding(&pre_padding, &post_padding, &len, format);
	swap = ft_substr(str, 0, len);
	pad = padding(pre_padding, filling);
	str = ft_strjoin(pad, swap);
	free(pad);
	free(swap);
	pad = padding(post_padding, filling);
	swap = ft_strjoin(str, pad);
	res = ft_strlen(swap);
	free(pad);
	free(str);
	ft_putstr_fd(swap, 1);
	free(swap);

	
	// padding(filling, pre_padding);
	// ft_putstr_fd(aux, 1);
	// padding(filling, post_padding);
	// free(aux);
	return (res);
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
