/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:08:49 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/14 18:21:55 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_int(long nbr, t_format *format)
{
	char	*nb_ascii;
	char	*swap;
	int		sp_padding;
//	int		ze_padding;

	if (!check_format_int(nbr, format))
			return (-1);
	swap = ft_itoa(nbr);
	nb_ascii = ft_put_zeroes(swap, format); 
////	printf("\n\tITOA:\t|%s|\n", nb_ascii);
	free(swap);

	sp_padding = format->width - ft_strlen(nb_ascii);
	sp_padding *= (sp_padding > 0);


	if (format->flags == '-')
		ft_putstr_fd(nb_ascii, 1);
	ft_padding(' ', sp_padding);
	if (format->flags != '-')
		ft_putstr_fd(nb_ascii, 1);
	free(nb_ascii);
	return (sp_padding + ft_strlen(nb_ascii));


}

char	*ft_put_zeroes(char *nb_ascii, t_format *format)
{
	int		is_neg;
	int 	digits;
	int		ze_padding;
	int		i;
	char	*res;

	i = 0;
	is_neg = 0;
	if (nb_ascii[i] == '-')
		is_neg = 1;
	digits = ft_strlen(nb_ascii) - is_neg;
//	printf("\tDIGITS:|%d|", digits);
	ze_padding = format->precision - digits;
//test_print_format_struct(format);
	res = (char *)malloc(sizeof(char) * (is_neg + digits + ze_padding + 1));
	if (is_neg)
	{
		res[i] = *nb_ascii;
		i++;
		nb_ascii++;
	}
	while (ze_padding > 0)
	{
		res[i] = '0';
		i++;
		ze_padding--;
	}
	while (digits > 0)
	{
		res[i] = *nb_ascii;
		i++;
		nb_ascii++;
		digits--;
	}
	res[i] = 0;
	return (res);
}

int		check_format_int(long nbr, t_format *format)
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
