/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 21:14:53 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/09 20:08:19 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    int x = printf("%p\n","");
    int y = ft_printf("%p\n","");
    printf("%d == %d \n",x ,y);
    return (0);
}
