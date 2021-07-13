/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:14:27 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/13 21:45:43 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_hexa(unsigned long nbr, t_format *format)
{
	return (ft_print_str(ft_itoa_base(nbr, "0123456789ABCDEF"), format));
}

char	*ft_itoa_base(unsigned long nb, char *base)
{
	int		base_size;
	char	*swap;
	char	res[10];
	int		i;

	i = 0;
	base_size = ft_strlen(base);
	while (nb >= base_size)
	{
		res[i] = base[nb % base_size];
		i++;
		nb /= base_size;
	}
	res[i] = base[nb];
	res[i + 1] = 0;
	reverse_string(&res);
	return (res);
}

void	reverse_string(char **str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		(*str)[i] = (*str)[len - i];
		i++;
	}
}

