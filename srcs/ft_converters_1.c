/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:02:26 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/15 19:11:52 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ft_print_char(char c, t_grouped_flags *flags)
{
	ssize_t	printed_chars;

	printed_chars = 1;
	printed_chars += ft_handle_left_padding(flags, 1 , FALSE);
	ft_putchar_fd(c, 1);
	printed_chars += ft_handle_minus_flag(flags, 1);
	return (printed_chars);
}

size_t	ft_print_str(char *str, t_grouped_flags *flags)
{
	ssize_t	printed_chars;
	ssize_t	i;

	if (!str)
		return (ft_print_str("(null)", flags));
	if (flags->precision_size > (ssize_t)ft_strlen(str) || !(flags->precision))
		printed_chars = ft_handle_left_padding(flags, ft_strlen(str) , FALSE);
	else
		printed_chars = ft_handle_left_padding(flags, flags->precision_size , FALSE);
	i = 0;
	while ((str[i] && !(flags->precision)) || (flags->precision && str[i]
			&& i < flags->precision_size))
		ft_putchar_fd(str[i++], 1);
	printed_chars += i;
	printed_chars += ft_handle_minus_flag(flags, printed_chars);
	return (printed_chars);
}

size_t	ft_print_pointer(unsigned long p, t_grouped_flags *flags)
{
	ssize_t	printed_chars;

	printed_chars = 0;
	printed_chars += ft_handle_left_padding(flags, ft_hex_len(p) + 2 , FALSE);
	printed_chars += ft_print_str("0x", NULL) + ft_print_hex(p, FALSE);
	printed_chars += ft_handle_minus_flag(flags, printed_chars);
	return (printed_chars);
}

size_t	ft_print_number(long i, t_grouped_flags *flags, t_boolean is_unsigned)
{
	ssize_t	printed_chars;

	printed_chars = 0;
	printed_chars += ft_handle_left_padding(flags, ft_decimal_len(i)
			+ (!is_unsigned && i >= 0 && (flags->plus || flags->space)) , flags->precision);
	printed_chars += ft_handle_plus_and_space_flag(flags, i, is_unsigned);
	if (i < 0)
	{
		printed_chars += ft_print_char('-', NULL);
		i *= -1;
	}
	printed_chars += ft_handle_zero_flag(flags, ft_decimal_len(i)
			+ printed_chars, flags->precision);
	printed_chars += ft_print_decimal(i);
	printed_chars += ft_handle_minus_flag(flags, printed_chars);
	return (printed_chars);
}

size_t	ft_print_hex_converter(unsigned long p, t_boolean is_upper,
		t_grouped_flags *flags)
{
	ssize_t	printed_chars;

	printed_chars = 0;
	printed_chars += ft_handle_left_padding(flags, ft_hex_len(p) , FALSE);
	printed_chars += ft_handle_zero_flag(flags, ft_hex_len(p) , FALSE);
	printed_chars += ft_print_hex(p, is_upper);
	printed_chars += ft_handle_minus_flag(flags, printed_chars);
	return (printed_chars);
}

size_t	ft_print_percentage(t_grouped_flags *flags)
{
	ssize_t	printed_chars;

	printed_chars = 0;
	printed_chars += ft_handle_zero_flag(flags, 1 , FALSE);
	printed_chars += ft_print_char('%', flags);
	return (printed_chars);
}
