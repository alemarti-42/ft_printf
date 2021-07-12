/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:59:37 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/12 16:08:52 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_parse_format(const char *str, t_format *format)
{
	int	i;
	char	*available_formats;

	available_formats = "cspdiuxX%";
	i = 0;


	while (str[i] == '0' || str[i] == '-')
	{
		while (str[i] == '0')
		{
			if (format->flags != '-')
				format->flags = '0';
			i++;
		}
		while (str[i] == '-')
		{
			if (format->flags != '-')
				format->flags = '-';
			i++;
		}
	}
	i += ft_get_width(&str[i], format);
	if (str[i] == '.')
	{
		i += 1;
		i += ft_get_precision(&str[i], format);
	}
	if (!ft_strchr(available_formats, str[i]))
			return (-1);
	format->datatype = str[i];
//	print_format_struct(format);
//	printf("\n\tLETRAS: %d", i);
	return (i + 1);
}

int		ft_get_precision(const char *str, t_format *form)
{
	int		i;
	char	*nbr;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	nbr = ft_substr(str, 0, i);
	form->precision = ft_atoi(nbr);
	free(nbr);
	return (i);
}

int		ft_get_width(const char *str, t_format *form)
{
	int		i;
	char	*nbr;

	i = 0;
	while (ft_isdigit(str[i]))
		i++;
	nbr = ft_substr(str, 0, i);
	form->width = ft_atoi(nbr);
	free(nbr);
	return (i);
}
