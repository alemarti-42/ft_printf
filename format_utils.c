/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:55:17 by alemarti          #+#    #+#             */
/*   Updated: 2021/08/11 13:20:01 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*init_format(void)
{
	t_format	*res;

	res = (t_format *)malloc(sizeof(t_format));
	if (!res || reset_format(res) == -1)
		return (NULL);
	return (res);
}

int	reset_format(t_format *form)
{
	if (!form)
		return (-1);
	form->flags = 0;
	form->flag_prefix = 0;
	form->width = -1;
	form->precision = -1;
	form->datatype = 0;
	return (0);
}
