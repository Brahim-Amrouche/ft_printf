/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:06:19 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/07 10:41:22 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t ft_print_hex(unsigned int value)
{
    size_t len = 0;
    if (value >= 16)
    {
        len += ft_print_hex(value / 16);
        len += ft_print_hex(value % 16);
        return len;
    }
    else 
    {
        if (value <= 9)
        {
            ft_putchar_fd("0123456789"[value],0);
            return 1;
        }
        else
        {
            ft_putchar_fd("abcdef"[value%10],0);
            return 1;
        }
    }

}
