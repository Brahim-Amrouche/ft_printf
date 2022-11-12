/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:06:19 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/12 19:08:24 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ft_print_hex(unsigned long value, int upper)
{
	size_t	len;

	len = 0;
	if (value >= 16)
	{
		len += ft_print_hex(value / 16, upper);
		len += ft_print_hex(value % 16, upper);
		return (len);
	}
	else
	{
		if (value <= 9)
			return (ft_print_char("0123456789"[value], NULL));
		else if (upper)
			return (ft_print_char("ABCDEF"[value % 10], NULL));
		else
			return (ft_print_char("abcdef"[value % 10], NULL));
	}
}

size_t	ft_print_decimal(long d)
{
	size_t len;

	len = 0;
	if (d < 0)
	{
		d *= -1;
		len += ft_print_char('-', NULL);
		len += ft_print_decimal(d);
	}
	else if (d > 9)
	{
		len += ft_print_decimal(d / 10);
		len += ft_print_decimal(d % 10);
	}
	else
		len += ft_print_char(d + '0', NULL);
	return (len);
}