/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:45:53 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/13 17:47:11 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// TESTING **************************************
void	test_print_format_struct(t_format *format)
{
	printf("\n>>");
	printf("\nFLAGS:\t\t%c", format->flags);
	printf("\nWIDTH:\t\t%d", format->width);
	printf("\nPRECIS:\t\t%d", format->precision);
	printf("\nDATATYPE:\t%c", format->datatype);
	printf("\n<<\n");
}
//**********************************************

int		ft_printf(const char *str, ...)
{
	va_list		args;
	int			res;

	res = 0;
	va_start(args, str);
	res = ft_print_line(str, &args);
	va_end(args);
	if (res < 0)
		printf("\n\tBUGASOOOO\n");
	return (res);
}

int			ft_print_line(const char *str,  va_list *args)
{
	int		i;
	int		count;
	int		res;
	int		print_param_len;
	
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
			print_param_len = ft_print_param(&str[i], args, &count);
			if (print_param_len < 0)
				return (-1);
			i += print_param_len;
		}
		
		write (1, &str[i], 1);
		i++;
		count++;
	}
	return (i);
}

/*
 *	ft_print_param returns the length of the format specifier on the input line needed
 *	to read the line properly.
 *	Ex: %10.3d	-> 5
 *	Also leaves on total_length the 
 */
int			ft_print_param(const char *str, va_list *args, int *total_length)
{
	t_format	*format;
	int			i;
	int			format_len;
	int			format_ctl;

	va_list *p = args;
	p = 0;

	i = 0;
	format_len = 0;
/*
	if (str[i] == '%')
	{
		write(1, "%", 1);
		*total_length += 1;
		return (1);
	}
*/
	format = ft_init_format();
	if (!format)
		return (-1);
			
	
	format_len = ft_parse_format(str, format);
	format_ctl = ft_sort_format(args, format);
	*total_length += format_ctl;
	free(format);
	if (*total_length < 0 || format_ctl < 0)
		return (-1);
	return (format_len);
}
