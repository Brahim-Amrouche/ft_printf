/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:21:24 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/06 15:14:42 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_zero_flag(char *str, t_printf_flag *flag)
{
	if (str[0] == '0')
	{
		flag->exists = TRUE;
		flag->skip = 1;
		return ;
	}
	flag->skip = 0;
}

size_t	ft_sum_skip(t_grouped_flags flags)
{
	return (flags.format.skip + flags.precision.skip + flags.plus.skip
		+ flags.space.skip + flags.minus.skip + flags.zero.skip);
}

size_t	ft_parse_flags(char *str, t_grouped_flags *flags)
{
	size_t	i;

	i = 1;
	while (str[i])
	{
		ft_is_format_flag(str + i, &(flags->format));
		ft_is_precision_flag(str + i, &(flags->precision));
		ft_is_plus_flag(str[i], &(flags->plus));
		ft_is_space_flag(str[i], &(flags->space));
		ft_is_minus_flag(str + i, &(flags->minus));
		ft_is_zero_flag(str + i, &(flags->zero));
		if (!ft_sum_skip(*flags))
			break ;
		i += ft_sum_skip(*flags);
	}
	return (i);
}
