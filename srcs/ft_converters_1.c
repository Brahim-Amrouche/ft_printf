/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:02:26 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/14 19:33:57 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ft_print_char(char c, t_grouped_flags *flags)
{
	ssize_t	printed_chars;

	printed_chars = 1;
	printed_chars += ft_handle_left_padding(flags,1);
	ft_putchar_fd(c, 1);
	printed_chars += ft_handle_minus_flag(flags, 1);
	return (printed_chars);
}

size_t	ft_print_str(char *str, t_grouped_flags *flags)
{
	size_t	printed_chars;

	if (!str)
		return (ft_print_str("(null)", flags));
	printed_chars = 0;
	printed_chars += ft_handle_left_padding(flags,ft_strlen(str));
	while (str[printed_chars])
		ft_putchar_fd(str[printed_chars++], 1);
	printed_chars += ft_handle_minus_flag(flags, printed_chars);
	return (printed_chars);
}

size_t	ft_print_pointer(unsigned long p, t_grouped_flags *flags)
{
	ssize_t	printed_chars;

	printed_chars = 0;
    printed_chars += ft_handle_left_padding(flags,ft_hex_len(p) + 2);
	printed_chars += ft_print_str("0x", NULL) + ft_print_hex(p, FALSE);
	printed_chars += ft_handle_minus_flag(flags, printed_chars);
	return (printed_chars);
}

size_t	ft_print_number(long i, t_grouped_flags *flags, t_boolean is_unsigned)
{
	ssize_t	printed_chars;

	if (is_unsigned)
		printed_chars = 0;
	else
		printed_chars = ft_handle_plus_and_space_flag(flags, i);
	printed_chars += ft_handle_left_padding(flags,ft_decimal_len(i) + printed_chars);
	if (i < 0)
	{
		printed_chars += ft_print_char('-', NULL);
		i *= -1;
	}
	printed_chars += ft_handle_zero_flag(flags, ft_decimal_len(i)
			+ printed_chars);
	printed_chars += ft_print_decimal(i);
	printed_chars += ft_handle_minus_flag(flags, printed_chars);
	return (printed_chars);
}

size_t	ft_print_hex_converter(unsigned long p, t_boolean is_upper,
		t_grouped_flags *flags)
{
	ssize_t	printed_chars;

	printed_chars = 0;
	printed_chars += ft_handle_left_padding(flags,ft_hex_len(p));
	printed_chars += ft_handle_zero_flag(flags, ft_hex_len(p));
	printed_chars += ft_print_hex(p, is_upper);
	printed_chars += ft_handle_minus_flag(flags, printed_chars);
	
	return (printed_chars);
}

size_t	ft_print_percentage(t_grouped_flags *flags)
{
	ssize_t	printed_chars;

	printed_chars = 0;
	printed_chars += ft_handle_zero_flag(flags, 1);
	printed_chars += ft_print_char('%', flags);
	return (printed_chars);
}
