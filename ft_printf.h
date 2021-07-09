/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:43:00 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/09 15:23:35 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_format
{
	char	flags;
	int		width;
	int		precision;
	char	datatype;
	char	*str;
}	t_format;

int			ft_printf(const char *str, ...);
int			ft_print_line(const char *str, va_list *args);
int			ft_print_param(const char *str, va_list *args, int *pos);
int			ft_parse_format(const char *str, t_format *format);
int			ft_get_precision(const char *str, t_format *form);
int			ft_get_width(const char *str, t_format *form);
t_format	*ft_init_format(void);
int			ft_reset_format(t_format *form);

int			ft_sort_format(va_list *args, t_format *format);
int			ft_print_str(char *str, t_format *format);
//int			ft_print_str(
void		ft_padding(char c, int n);
#endif
