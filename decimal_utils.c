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
	int	res;

	nb_ascii = ft_itoa(nbr);
	nb_ascii = add_prefix_nb(nb_ascii, format);
	res = ft_strlen(nb_ascii);
	ft_putstr_fd(nb_ascii, 1);
	free(nb_ascii);
	return (res);
}

char	*add_prefix_nb(char *nb_ascii, t_format *format)
{
	char	*swap;
	char	*aux_zeroes;
	char	*aux_nb;
	int		is_neg;
	int		ze_padding;


	is_neg = 0;
	if (nb_ascii[0] == '-')
		is_neg = 1;
	ze_padding = 0;
	
	
	if (format->flags == ' ')
		swap = ft_strdup(" ");
	else if (format->flags == '+' && nb_ascii[0] != '-')
		swap = ft_strdup("+");
	else if ( nb_ascii[0] == '-')
	{
		aux_nb = ft_substr(nb_ascii, 1, 30);
		swap = ft_strdup("-");
		free (nb_ascii);
		nb_ascii = aux_nb;
	}
	else
		swap = ft_strdup("");
	aux_zeroes = padding(format->precision - ft_strlen(nb_ascii), '0');
	aux_nb = ft_strjoin(swap, aux_zeroes);
	free(aux_zeroes);
	free(swap);
	swap = ft_strjoin(aux_nb, nb_ascii);

	free(nb_ascii);
	free(aux_nb);
	return(swap);
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
	ze_padding *= ze_padding > 0;
	res = (char *)malloc(sizeof(char) * (is_neg + digits + ze_padding + 1));
	if (!res)
		return (NULL);
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

