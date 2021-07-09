/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:45:53 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/09 19:04:07 by alemarti         ###   ########.fr       */
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
	return (-1);
	va_end(args);
	return (0);
}

int			ft_print_line(const char *str,  va_list *args)
{
	int		i;
	int		count;
	int		res;
	int		print_param_ctl;
	
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
			print_param_ctl = ft_print_param(&str[i], args, &count);
			if (print_param_ctl == -1)
				return (-1);
			i += print_param_ctl;
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
