/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:02:26 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/12 19:08:34 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ft_print_char(char c, t_grouped_flags *flags)
{
	ssize_t	offset;

	ft_putchar_fd(c, 1);
	if (flags && flags->minus.exists)
	{
		offset = ft_atoi(flags->minus.params) - 1;
		while (offset-- > 0)
			ft_putchar_fd(' ', 1);
		offset = ft_atoi(flags->minus.params);
		if (offset > 1)
			return (offset);
	}
	return (1);
}

size_t	ft_print_str(char *str)
{
	size_t	i;

	if (!str)
		return (ft_print_str("(null)"));
	i = 0;
	while (str[i])
		ft_putchar_fd(str[i++], 1);
	return (i);
}

size_t	ft_print_pointer(unsigned long p)
{
	return (ft_print_str("0x") + ft_print_hex(p, 0));
}

size_t	ft_print_number(long i)
{
	return (ft_print_decimal(i));
}
