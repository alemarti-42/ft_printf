/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:08:49 by alemarti          #+#    #+#             */
/*   Updated: 2021/08/11 13:23:39 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(long nbr, t_format *format)
{
	char	*nb_ascii;
	char	filling;
	char	*swap;
	int		sp_padding;

	filling = ' ';
	if (!check_format_int(nbr, format))
		return (-1);
	swap = ft_itoa(nbr);
	nb_ascii = put_zeroes(swap, format);
	free(swap);
	sp_padding = format->width - ft_strlen(nb_ascii);
	sp_padding *= (sp_padding > 0);
	if (format->flags == '-')
		ft_putstr_fd(nb_ascii, 1);
	padding(' ', sp_padding);
	if ((format->flags == ' ' || format->flags == '+') && nbr >= 0)
	{
		write(1, &format->flags, 1);
		sp_padding++;
	}
	if (format->flags != '-')
		ft_putstr_fd(nb_ascii, 1);
	free(nb_ascii);
	return (sp_padding + ft_strlen(nb_ascii));
}

char	*put_zeroes(char *nb_ascii, t_format *format)
{
	int		is_neg;
	int		digits;
	int		ze_padding;
	int		i;
	char	*res;

	i = 0;
	is_neg = 0;
	if (nb_ascii[0] == '-')
		is_neg = 1;
	digits = ft_strlen(nb_ascii) - is_neg;
	ze_padding = format->precision - digits;
	res = (char *)malloc(sizeof(char) * (is_neg + digits + ze_padding + 1));
	res[0] = '-';
	i += is_neg;
	nb_ascii += is_neg;
	while (ze_padding-- > 0)
		res[i++] = '0';
	while (digits-- > 0)
	{
		res[i++] = *nb_ascii;
		nb_ascii++;
	}
	res[i] = 0;
	return (res);
}

int	check_format_int(long nbr, t_format *format)
{
	if (format->flags == '0' && format->precision == -1)
	{
		format->precision = format->width;
		format->width = 0;
		if (nbr < 0)
			format->precision -= 1;
	}
	return (1);
}
