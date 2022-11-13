/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:07:11 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/13 16:28:35 by bamrouch         ###   ########.fr       */
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
}					t_printf_flag;

typedef struct s_grouped_flags
{
	t_printf_flag	format;
	t_printf_flag	precision;
	t_printf_flag	plus;
	t_printf_flag	space;
	t_printf_flag	minus;
	t_printf_flag	zero;
	ssize_t			offset_size;
	ssize_t			precision_size;
}					t_grouped_flags;

/* Converters Logic */
size_t				ft_print_char(char c, t_grouped_flags *flags);
size_t				ft_print_str(char *str, t_grouped_flags *flags);
size_t				ft_print_hex(unsigned long value, int upper);
size_t				ft_print_pointer(unsigned long p, t_grouped_flags *flags);
size_t				ft_print_hex_converter(unsigned long p, int is_upper,
						t_grouped_flags *flags);
size_t				ft_print_decimal(long d);
size_t				ft_print_number(long i, t_grouped_flags *flags);
/* end Converts Logic */

/* Flags Logic */
ssize_t	ft_handle_minus_flag(t_grouped_flags *flags, ssize_t printed_len);
size_t ft_parse_flags(const char *str, t_grouped_flags *flags);
/* end Flags Logic*/

#endif