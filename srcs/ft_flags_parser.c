/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:21:24 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/13 16:59:32 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int ft_is_flag(int c)
{
	if (c == '0' || c == '-' || c == ' ' || c == '#' || c == '+' || c == '.')
		return 1;
	return 0;
}

size_t ft_handle_initial_flags(const char *str,t_grouped_flags *flags)
{
	size_t i;

	i = 0;
	while(ft_is_flag(str[++i]))
	{
		if (str[i] == '0')
			flags->zero.exists = TRUE;
		else if (str[i] == '-')
			flags->minus.exists = TRUE;
		else if (str[i] == '#')
			flags->format.exists = TRUE;
		else if (str[i] == '+')
			flags->plus.exists = TRUE;
		else if (str[i] == ' ')
			flags->space.exists = TRUE;
		else if (str[i] == '.')
			flags->precision.exists = TRUE;
	}
	return i;
}

size_t ft_parse_flags(const char *str, t_grouped_flags *flags)
{
	size_t i;

	i = ft_handle_initial_flags(str,flags);
	if (flags->precision.exists)
		flags->precision_size = ft_atoi(&str[i]);
	else
		flags->offset_size = ft_atoi(&str[i]);
	while(ft_isdigit(str[i]))
		i++;
	if (str[i] && str[i] == '.' && !(flags->precision.exists))
	{
		flags->precision.exists = TRUE;
		flags->precision_size = ft_atoi(&str[++i]);
	}
	while (ft_isdigit(str[i]))
		i++;
	return i;
}