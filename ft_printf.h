/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:43:00 by alemarti          #+#    #+#             */
/*   Updated: 2021/09/07 14:17:50 by alemarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_format
{
	char	flags;
	int		width;
	int		precision;
	char	datatype;
}	t_format;

//	ft_printf.c
int			ft_printf(const char *str, ...);
int			print_line(const char *str, va_list *args);
int			print_param(const char *str, va_list *args, int *pos);

//	ft_printf_utils.c
int			sort_format(va_list *args, t_format *format);
int			padding(char c, int n);

//		parse_utils.c
int			parse_format(const char *str, t_format *format);
int			get_flags(const char *str, t_format *format);
int			get_precission(const char *str, t_format *form);
int			get_width(const char *str, t_format *form);

//	format_utils.c
t_format	*init_format(void);
int			reset_format(t_format *form);

//	char_utils.c
int			print_chr(int ascii, t_format *format);

//	string_utils.c
int			print_str(char *str, t_format *format);
void		set_padding(int *pre_padding, int *post_padding, int *len, \
		t_format *format);

//	decimal_utils.c
int			print_int(long nbr, t_format *format);
char		*put_zeroes(char *nb_ascii, t_format *format);
void		parse_zero_flag(t_format *format, char *nbr);

// HEXA
int			print_hexa(unsigned int nbr, t_format *format);
char		*itoa_base(unsigned long nb, char *base);
char		*str_add_chr(const char *str, const char chr);
void		reverse_string(char *str);

//	pointer_utils.c
int			print_pointer(unsigned long mem, t_format *format);

#endif
