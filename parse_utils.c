/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:59:37 by alemarti          #+#    #+#             */
/*   Updated: 2021/08/11 13:19:35 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(const char *str, t_format *format)
{
	int		i;
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
	if (str[0] == '#' || str[0] == ' ' || str[0] == '+')
	{
		format->flags = str[0];
		i++;
	}
	i += get_width(&str[i], format);
	if (str[i] == '.')
	{
		i += 1;
		i += get_precission(&str[i], format);
	}
	if (!ft_strchr(available_formats, str[i]))
		return (-1);
	format->datatype = str[i];
	return (i + 1);
}

int	get_precission(const char *str, t_format *form)
{
	int		i;
	char	*nbr;

	i = 0;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	nbr = ft_substr(str, 0, i);
	form->precision = ft_atoi(nbr);
	free(nbr);
	return (i);
}

int	get_width(const char *str, t_format *form)
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
