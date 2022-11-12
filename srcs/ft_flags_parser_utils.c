/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parser_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:07:50 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/12 19:07:58 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_is_format_flag(const char *str, t_printf_flag *flag)
{
	if (str[0] == '#')
	{
		flag->exists = TRUE;
		flag->skip = 1;
		return ;
	}
	flag->skip = 0;
}

void	ft_is_precision_flag(const char *str, t_printf_flag *flag)
{
	if (str[0] == '.')
	{
		flag->exists = TRUE;
		flag->skip = 1;
		return ;
	}
	flag->skip = 0;
}

void	ft_is_plus_flag(const char c, t_printf_flag *flag)
{
	if (c == '+')
	{
		flag->exists = TRUE;
		flag->skip = 1;
		return ;
	}
	flag->skip = 0;
}

void	ft_is_space_flag(const char c, t_printf_flag *flag)
{
	if (c == ' ')
	{
		flag->exists = TRUE;
		flag->skip = 1;
		return ;
	}
	flag->skip = 0;
}

void	ft_is_minus_flag(const char *str, t_printf_flag *flag)
{
	size_t	i[2];

	flag->skip = 0;
	if (str[0] != '-')
		return ;
	flag->exists = TRUE;
	i[1] = 1;
	while (str[i[1]] == '-')
		(i[1])++;
	i[0] = i[1];
	while (ft_isdigit(str[i[0]]))
		(i[0])++;
	if (i[0] == i[1])
		flag->params = ft_strdup("0");
	else
		flag->params = ft_substr(str, i[1], i[0] - i[1]);
	flag->skip = i[0];
}
