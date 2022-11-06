/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:07:11 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/06 11:49:37 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

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

int					ft_printf(char *s, ...);

#endif