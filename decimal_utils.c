/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:08:49 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/13 17:53:43 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_int(int nbr, t_format *format)
{
	char	*nb_ascii;
	char	*swap;
	int		sp_padding;
//	int		ze_padding;

	if (!check_format_int(format))
			return (-1);
	swap = ft_itoa(nbr);
	nb_ascii = ft_put_zeroes(swap, format); 
	printf("\n\tITOA:\t%s\n", nb_ascii);
	free(swap);

	sp_padding = format->width - ft_strlen(nb_ascii);


	if (format->flags == '-')
		ft_putstr_fd(nb_ascii, 1);
	ft_padding(' ', sp_padding);
	if (format->flags != '-')
		ft_putstr_fd(nb_ascii, 1);
	return (sp_padding + ft_strlen(nb_ascii));


}

char	*ft_put_zeroes(char *nb_ascii, t_format *format)
{
	int		is_neg;
	int 	digits;
	int		ze_padding;
	char	*res;

	is_neg = 0;
	if (nb_ascii[0] == '-')
		is_neg = 1;
	digits = ft_strlen(nb_ascii) - is_neg;
	ze_padding = format->precision - digits;
	res = (char *)malloc(sizeof(char) * (is_neg + digits + ze_padding + 1));
	if (is_neg)
	{
		*res = '-';
		res++;
		nb_ascii++;
	}
	while (ze_padding > 0)
	{
		*res = '0';
		res++;
		ze_padding--;
	}
	while (digits > 0)
	{
		*res = *nb_ascii;
		res++;
		nb_ascii++;
		digits--;
	}
	*res = 0;
	return (res);
}

int		check_format_int(t_format *format)
{
	if (format->flags == '0' && format->precision == -1)
		format->precision = format->width;
	format = 0;
	return (1);
}
