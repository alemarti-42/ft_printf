/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 20:43:04 by alemarti          #+#    #+#             */
/*   Updated: 2021/08/11 13:25:05 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(unsigned long mem, t_format *format)
{
	char	*swap;
	char	*res;
	int		ctl;

	swap = itoa_base(mem, "0123456789abcdef");
	res = ft_strjoin("0x", swap);
	free(swap);
	ctl = print_str(res, format);
	free (res);
	return (ctl);
}
