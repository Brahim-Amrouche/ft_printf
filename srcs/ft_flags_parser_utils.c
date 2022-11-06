/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parser_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:07:50 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/06 15:13:00 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_format_flag(char *str, t_printf_flag *flag)
{
	if (str[0] == '#')
	{
		flag->exists = TRUE;
		flag->skip = 1;
		return ;
	}
	flag->skip = 0;
}

void	ft_is_precision_flag(char *str, t_printf_flag *flag)
{
	if (str[0] == '.')
	{
		flag->exists = TRUE;
		flag->skip = 1;
		return ;
	}
	flag->skip = 0;
}

void	ft_is_plus_flag(char c, t_printf_flag *flag)
{
	if (c == '+')
	{
		flag->exists = TRUE;
		flag->skip = 1;
		return ;
	}
	flag->skip = 0;
}

void	ft_is_space_flag(char c, t_printf_flag *flag)
{
	if (c == ' ')
	{
		flag->exists = TRUE;
		flag->skip = 1;
		return ;
	}
	flag->skip = 0;
}

void	ft_is_minus_flag(char *str, t_printf_flag *flag)
{
	if (str[0] == '-')
	{
		flag->exists = TRUE;
		flag->skip = 1;
		return ;
	}
	flag->skip = 0;
}
