/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:02:26 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/13 03:29:31 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

ssize_t	ft_handle_minus_flag(t_grouped_flags *flags, ssize_t printed_len)
{
	ssize_t	offset;

	if (flags && flags->minus.exists)
	{
		offset = ft_atoi(flags->minus.params) - printed_len;
		while (offset-- > 0)
			ft_putchar_fd(' ', 1);
		offset = ft_atoi(flags->minus.params);
		if (offset > printed_len)
			return (offset);
	}
	return (-1);
}

size_t	ft_print_char(char c, t_grouped_flags *flags)
{
	ssize_t	offset;

	ft_putchar_fd(c, 1);
	offset = ft_handle_minus_flag(flags, 1);
	if (offset != -1)
		return (offset);
	return (1);
}

size_t	ft_print_str(char *str, t_grouped_flags *flags)
{
	size_t	printed_chars;
	ssize_t	offset;

	if (!str)
		return (ft_print_str("(null)", flags));
	printed_chars = 0;
	while (str[printed_chars])
		ft_putchar_fd(str[printed_chars++], 1);
	offset = ft_handle_minus_flag(flags, printed_chars);
	if (offset != -1)
		return (offset);
	return (printed_chars);
}

size_t	ft_print_pointer(unsigned long p, t_grouped_flags *flags)
{
	ssize_t	printed_chars;
	ssize_t	offset;

	printed_chars = ft_print_str("0x", NULL) + ft_print_hex(p, 0);
	offset = ft_handle_minus_flag(flags, printed_chars);
	if (offset != -1)
		return (offset);
	return (printed_chars);
}

size_t	ft_print_number(long i, t_grouped_flags *flags)
{
	ssize_t	printed_chars;
	ssize_t	offset;

	printed_chars = ft_print_decimal(i);
	offset = ft_handle_minus_flag(flags, printed_chars);
	if (offset != -1)
		return (offset);
	return (printed_chars);
}
