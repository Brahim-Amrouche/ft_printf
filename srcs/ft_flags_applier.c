/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_applier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:07:27 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/13 19:02:48 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

ssize_t	ft_handle_minus_flag(t_grouped_flags *flags, ssize_t printed_len)
{
	ssize_t	offset;

	if (flags && flags->minus)
	{
		offset = flags->offset_size - printed_len;
		while (offset-- > 0)
			ft_putchar_fd(' ', 1);
		if (flags->offset_size > printed_len)
			return (offset);
	}
	return (-1);
}

ssize_t ft_handle_zero_flag(t_grouped_flags *flags,ssize_t printed_len)
{
	ssize_t printed_zeroes;
	
	if (flags && flags->zero && !(flags->minus))
	{
		printed_zeroes = flags->offset_size - printed_len;
		while (printed_zeroes-- > 0)
			ft_putchar_fd('0',1);
		if (flags->offset_size > printed_len)
			return (flags->offset_size - printed_len);
	}
	return (0);
}