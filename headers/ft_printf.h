/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:07:11 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/09 01:02:29 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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
size_t				ft_print_char(char c);
size_t				ft_print_str(char *str);
size_t				ft_print_hex(unsigned long long value , int maj);
size_t				ft_print_pointer(unsigned int p);
size_t				ft_print_decimal(long d);
size_t				ft_print_number(int i);
/* end Converts Logic */

/* Flags Logic */
void				ft_is_format_flag(char *str, t_printf_flag *flag);
void				ft_is_precision_flag(char *str, t_printf_flag *flag);
void				ft_is_plus_flag(char c, t_printf_flag *flag);
void				ft_is_space_flag(char c, t_printf_flag *flag);
void				ft_is_minus_flag(char *str, t_printf_flag *flag);
size_t				ft_parse_flags(char *str, t_grouped_flags *flags,
						size_t *index);
/* end Flags Logic*/

int					ft_printf(char *s, ...);

#endif