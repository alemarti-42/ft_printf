/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:43:00 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/14 17:25:29 by alemarti         ###   ########.fr       */
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

//	ft_printf.c
int			ft_printf(const char *str, ...);
int			ft_print_line(const char *str, va_list *args);
int			ft_print_param(const char *str, va_list *args, int *pos);

//	ft_printf_utils.c
int			ft_sort_format(va_list *args, t_format *format);
void		ft_padding(char c, int n);

//		parse_utils.c
int			ft_parse_format(const char *str, t_format *format);
int			ft_get_precision(const char *str, t_format *form);
int			ft_get_width(const char *str, t_format *form);

//	format_utils.c
t_format	*ft_init_format(void);
int			ft_reset_format(t_format *form);

//	string_utils.c
int			ft_print_chr(int ascii, t_format *format);
int			check_format_string(t_format *format);

//	char_utils.c
int			ft_print_str(char *str, t_format *format);
int			check_format_char(t_format *format);

//	decimal_utils.c
int			ft_print_int(long nbr, t_format *format);
char		*ft_put_zeroes(char *nb_ascii, t_format *format);
int			check_format_int(long nbr,t_format *format);

// HEXA
int			ft_print_hexa(unsigned long nbr, t_format *format);
char		*ft_itoa_base(unsigned long nb, char *base);
char		*ft_str_add_chr(const char *str, const char chr);
char		*reverse_string(char *str);

//	TESTING ***********************************
void		test_print_format_struct(t_format *format);
//*********************************************

#endif
