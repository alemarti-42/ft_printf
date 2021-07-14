/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:14:27 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/14 20:42:08 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_hexa(unsigned long nbr, t_format *format)
{
	char	*hexa;
	int		res;

	hexa = 0;
	hexa = ft_itoa_base(nbr, "0123456789abcdef");
	res = ft_print_str(hexa, format);
//	printf("\n\t[-]hexa:%s|res:%d\n", hexa, res);
	return (res);
}

char	*ft_itoa_base(unsigned long nb, char *base)
{
	size_t	base_size;
	char	*res;
	char	*swap;
	int		i;

	i = 0;
	base_size = ft_strlen(base);
	res = (char *)malloc(1);
	*res = 0;
	while (nb >= base_size)
	{
		swap = res;
//		printf("\n\t[i]:%s\n", res);
		res = ft_str_add_chr(swap, base[nb % base_size]);
//		printf("\n[+]%s|%ld|BS%zu\n", res, nb, base_size);
		free(swap);
		i++;
		nb /= base_size;
	}
	swap = res;
	res = ft_str_add_chr(swap, base[nb]);
//	printf("\n[+]%s|%ld|BS%zu\n", res, nb, base_size);
	free(swap);
//	printf("\n\t[u]:%s\n", res);
	reverse_string(res);
//	printf("\n\t[u]:%s\n", res);
	return (res);
}

char	*ft_str_add_chr(const char *str, const char chr)
{
	int		size;
	char	*res;
	int		i;

//	printf("\n[+]%s\n", str);
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
	int	len;
	int	i;
	char	aux;

	len = ft_strlen(str);
	i = 0;
//	printf("\n[+]len:%d\n", len);
	while (i < len / 2)
	{
		aux = str[len - i - 1];
		str[len - i - 1] = str[i];
		str[i] = aux;

		i++;
	}
}

