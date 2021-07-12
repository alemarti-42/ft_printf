/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:08:49 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/12 19:51:11 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"

int		ft_print_int(int nbr, t_format *format)
{
	char	*nb_ascii;
	int		sp_padding;
	int		ze_padding;

	if (!check_format_int(t_format *format))
			return (-1);
	nb_ascii = ft_itoa(nbr);
	nb_ascii = add_precision(nb_ascii, format);
	sp_padding = format->width - ft_strlen(nb_ascii);
	if (format->flags == '-')
	{
		ft_putstr_fd(nb_ascii, 1);
		ft_padding(' ', sp_padding);
	}


	ft_putstr_fd(str, 1);
}

char	*add_precision(char *nb_ascii, int precision)
{
	int		i;
	int		ze_padding;
	char	*res;
	char	*swap;

	i = 0;
	ze_padding = format->precision - ft_strlen(nb_ascii);
	if (nb_ascii[0] == '-')
		res = ft_strjoin("-", "");
	while (i < ze_padding)
	{
		swap = ft_strjoin(res, "0");
		free (res);
		res = swap;
		i++;
	}
	swap = ft_strjoin(res, nb_ascii);
	free (res);
	res = swap;
	free (nb_ascii);

	return (res);
}

int		check_format_int(t_format *format)
{
	return (1);
}
