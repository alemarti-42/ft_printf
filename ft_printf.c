/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:45:53 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/07 19:44:47 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		args;
	int			res;

	res = 0;
	va_start(args, str);
	res = ft_printer(str, args);
	va_end(args);
	return (0);
}

//TODO
int			ft_printer(const char *str,  va_list *args)
{
	int		i;
	int		count;
	int		res;

	i = 0;
	count = 0;
	res = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count += ft_print_param(&str[i], args);
		write (1, &str[i], 1);
		i++;
		count++;
	}
}
//TODO
int			ft_print_param(const char *str, va_list *args)
{
	t_format	format;

	format = (t_format *)malloc(sizeof(t_format));
	if (!format || ft_parse_format(str, format) == -1)
		return (-1);

	return (0);
}

//TODO
int			ft_parse_format(const char *str, t_format format)
{
	int	i;

	i = 1;

	if (str[i] == '%')
	{
		write (1, '%', 1);
		return (0);
	}
	if (str[i] == '-')
	{}
	if (str[i] == '0')
	{}
	i++;
	if (ft_is_num(str[i]))
		ft_get_width(&str[i]);



	}
	return (0);
}

t_format	*ft_init_format(void)
{
	t_format	*res;

	res = (t_format *)malloc(sizeof(t_format));
	if (!res || ft_reset_format(*res) == -1);
		return (NULL);
	return (res);
}

int		ft_reset_format(t_format form)
{
	if (!form)
		return (-1);
	form->flags = -1;
	form->width = -1;
	form->precision = -1;
	form->datatype = 0;
	form->str = 0;
	return (0);
}
