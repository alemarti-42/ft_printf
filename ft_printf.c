/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:45:53 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/09 15:26:57 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	print_format_struct(t_format *format)
{
	printf("\n********************\n");
	printf("\nFLAGS:\t\t%c", format->flags);
	printf("\nWIDTH:\t\t%d", format->width);
	printf("\nPRECIS:\t\t%d", format->precision);
	printf("\nDATATYPE:\t%c", format->datatype);
	printf("\n********************\n");
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	int			res;

	res = 0;
	va_start(args, str);
	res = ft_print_line(str, &args);
	va_end(args);
	return (0);
}

int			ft_print_line(const char *str,  va_list *args)
{
	int		i;
	int		count;
	int		res;
	
	va_list *p = args;
	p = 0;

	i = 0;
	count = 0;
	res = 0;
	while (str[i])
	{
		
		if (str[i] == '%')
		{
			i++;
			i += ft_print_param(&str[i], args, &count);
		}
		
		write (1, &str[i], 1);
		i++;
		count++;
	}
	return (i);
}
int			ft_print_param(const char *str, va_list *args, int *total_length)
{
	t_format	*format;
	int			i;
	int			format_len;

	va_list *p = args;
	p = 0;

	i = 0;
	format_len = 0;
	if (str[i] == '%')
	{
		write(1, "%", 1);
		*total_length += 1;
		return (1);
	}
	format = ft_init_format();
	if (!format)
		return (-1);
			
	
	format_len = ft_parse_format(str, format);
	ft_sort_format(args, format);
	free(format);
	return (format_len);
}

//TODO: Parseo de los argumentos a string
//int			ft_parse_arg();

int			ft_parse_format(const char *str, t_format *format)
{
	int	i;
	char	*available_formats;

	available_formats = "cspdiuxX";
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

t_format	*ft_init_format(void)
{
	t_format	*res;

	res = (t_format *)malloc(sizeof(t_format));
	if (!res || ft_reset_format(res) == -1)
		return (NULL);
	return (res);
}

int		ft_reset_format(t_format *form)
{
	if (!form)
		return (-1);
	form->flags = 0;
	form->width = -1;
	form->precision = -1;
	form->datatype = 0;
	form->str = 0;
	return (0);
}

