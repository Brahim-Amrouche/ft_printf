/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:02:26 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/08 00:32:51 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ft_print_char(char c)
{
	return (ft_putchar_fd(c, 0), 1);
}

size_t	ft_print_str(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		ft_putchar_fd(str[i++], 0);
	return (i);
}

size_t	ft_print_pointer(unsigned int p)
{
	return (ft_print_str("0x") + ft_print_hex(p));
}

size_t	ft_print_number(int i)
{
	return (ft_print_decimal(i));
}
