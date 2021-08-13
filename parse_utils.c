/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:59:37 by alemarti          #+#    #+#             */
/*   Updated: 2021/08/12 14:27:20 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(const char *str, t_format *format)
{
	int		i;
	int		flags_ctl;
	char	*available_formats;

	available_formats = "cspdiuxX%";
	i = 0;
	flags_ctl = get_flags(str, format);
	i += flags_ctl;
	if (flags_ctl < 0)
		return (-1);
	i += get_width(&str[i], format);
	if (str[i] == '.')
		i += (get_precission(&str[i + 1], format) + 1);
	//if (!ft_strchr(available_formats, str[i]))
	//	return (-1);
	format->datatype = str[i];
	return (i + 1);
}

int	get_flags(const char *str, t_format *form)
{
	int		i;

	i = 0;
	
	while (str[i] == '0' || str[i] == '-' || str[i] == '#')
	{
		while (str[i] == '0')
		{
			if (form->flags != '-')
				form->flags = '0';
			i++;
		}
		while (str[i] == '-')
		{
			form->flags = '-';
			i++;
		}
		while (str[i] == '#')
		{
			form->flag_prefix = '#';
			i++;
		}
	}
	
	while (str[i] == ' ' || str[i] == '+')
	{
		if (form->flags == '-' || form->flags == '0')
			return (-1);
		while (str[i] == ' ')
		{
			if (form->flags != '+')
				form->flags = ' ';
			i++;
		}
		while (str[i] == '+')
		{
			form->flags = '+';
			i++;
		}
	}
	return (i);
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
