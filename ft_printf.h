/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alemarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:43:00 by alemarti          #+#    #+#             */
/*   Updated: 2021/07/07 19:43:29 by alemarti         ###   ########.fr       */
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
	int		flags;
	int		width;
	int		precision;
	char	datatype;
}	t_format;

int			ft_printf(const char *str, ...);
int			ft_printer(const char *str, va_list *args);
int			ft_print_param(const char *str, va_list *args);
int			ft_parse_format(const char *str, t_format format);
t_format	*ft_init_format(void);
int			ft_reset_format(t_format form);
#endif
