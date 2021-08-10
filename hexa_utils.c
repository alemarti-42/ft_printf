/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:14:27 by alemarti          #+#    #+#             */
/*   Updated: 2021/08/10 19:28:23 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned int nbr, t_format *format)
{
	char	*hexa;
	int		res;

	hexa = 0;
	res = 0;
	if (format->datatype == 'x')
		hexa = ft_itoa_base(nbr, "0123456789abcdef");
	if (format->datatype == 'X')
		hexa = ft_itoa_base(nbr, "0123456789ABCDEF");
	res += ft_padding('0', format->precision - ft_strlen(hexa));
	format->precision = -1;
	if (format->flags == '#' && nbr > 0)
	{
		if (format->datatype == 'x')
			ft_putstr_fd("0x", 1);
		if (format->datatype == 'X')
			ft_putstr_fd("0X", 1);
		res += 2;
	}
	format->flags *= format->flags != '#';
	res += ft_print_str(hexa, format);
	free(hexa);
	return (res);
}

char	*ft_itoa_base(unsigned long nb, char *base)
{
	size_t	base_size;
	char	*res;
	char	*swap;
	int		i;

	i = 0;
	if (nb <= 0)
		nb = 0;
	base_size = ft_strlen(base);
	res = (char *)malloc(1);
	*res = 0;
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
	reverse_string(res);
	return (res);
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

void	reverse_string(char *str)
{
	int		len;
	int		i;
	char	aux;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		aux = str[len - i - 1];
		str[len - i - 1] = str[i];
		str[i] = aux;
		i++;
	}
}
