/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:07:11 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/13 03:24:00 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int					ft_printf(const char *s, ...);

typedef enum boolean
{
	FALSE = 0,
	TRUE = 1
}					t_boolean;

typedef struct s_printf_flag
{
	t_boolean		exists;
	char			*params;
	size_t			skip;
}					t_printf_flag;

typedef struct s_grouped_flags
{
	t_printf_flag	format;
	t_printf_flag	precision;
	t_printf_flag	plus;
	t_printf_flag	space;
	t_printf_flag	minus;
	t_printf_flag	zero;
}					t_grouped_flags;

/* Converters Logic */
size_t				ft_print_char(char c, t_grouped_flags *flags);
size_t				ft_print_str(char *str, t_grouped_flags *flags);
size_t				ft_print_hex(unsigned long value, int upper);
size_t				ft_print_pointer(unsigned long p, t_grouped_flags *flags);
size_t				ft_print_decimal(long d);
size_t				ft_print_number(long i, t_grouped_flags *flags);
/* end Converts Logic */

/* Flags Logic */
void				ft_is_format_flag(const char *str, t_printf_flag *flag);
void				ft_is_precision_flag(const char *str, t_printf_flag *flag);
void				ft_is_plus_flag(const char c, t_printf_flag *flag);
void				ft_is_space_flag(const char c, t_printf_flag *flag);
void				ft_is_minus_flag(const char *str, t_printf_flag *flag);
size_t				ft_parse_flags(const char *str, t_grouped_flags *flags,
						size_t *index);
/* end Flags Logic*/

#endif