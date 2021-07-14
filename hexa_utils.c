/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:14:27 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/14 16:59:52 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_hexa(unsigned long nbr, t_format *format)
{
	char	*hexa;
	char	*res;

	hexa = ft_itoa_base(nbr, "0123456789ABCDEF");
	res = ft_strjoin("HEXPREFIX", hexa);
	free(hexa);
	return (ft_print_str(res, format));
}

char	*ft_itoa_base(unsigned long nb, char *base)
{
	size_t	base_size;
	char	*res;
	char	*swap;
	int		i;

	i = 0;
	base_size = ft_strlen(base);
	swap = NULL;
	res = NULL;
	while (nb >= base_size)
	{
		swap = res;
		res = ft_str_add_chr(swap, base[nb % base_size]);
		free(swap);
		i++;
		nb /= base_size;
	}
	swap = res;
	res = ft_str_add_chr(swap, base[nb]);
	free(swap);
	return (reverse_string(res));
}

char	*ft_str_add_chr(const char *str, const char chr)
{
	int		size;
	char	*res;
	int		i;

	size = ft_strlen(str) + sizeof(char) + 1;
	res = (char *)malloc(size);
	if (!res)
		return (NULL);
	i = -1;
	while (str[++i])
		res[i] = str[i];
	res[i] = chr;
	i++;
	res[i] = 0;
	return (res);
}

char	*reverse_string(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		str[i] = str[len - i - 1];
		i++;
	}
	return (str);
}

