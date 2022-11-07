/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:06:19 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/08 00:27:20 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ft_print_hex(unsigned int value)
{
	size_t	len;

	len = 0;
	if (value >= 16)
	{
		len += ft_print_hex(value / 16);
		len += ft_print_hex(value % 16);
		return (len);
	}
	else
	{
		if (value <= 9)
		{
			ft_putchar_fd("0123456789"[value], 0);
			return (1);
		}
		else
		{
			ft_putchar_fd("abcdef"[value % 10], 0);
			return (1);
		}
	}
}

size_t	ft_print_decimal(long d)
{
	size_t len;

	len = 0;
	if (d < 0)
	{
		d *= -1;
		len += ft_print_char('-');
		len += ft_print_decimal(d);
	}
	else if (d > 9)
	{
		len += ft_print_decimal(d / 10);
		len += ft_print_decimal(d % 10);
	}
	else
		len += ft_print_char(d + '0');
	return (len);
}