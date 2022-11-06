/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:06:19 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/06 19:15:09 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void ft_print_hex(long value)
{
    if (value / 16 > 0)
    {
        ft_print_hex(value / 16);
        ft_print_hex(value %16);
    }
    else 
    {
        if (value <= 9)
            ft_putchar_fd("0123456789"[value],0);
        else 
            ft_putchar_fd("abcdef"[value%10],0);
    }

}