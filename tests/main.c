/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:13:44 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/11 00:30:50 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include "ft_printf.h"

int main()
{
    print_white();
    printf("Mandatory ------------------------------------------------------\n");
    print_black();
    // BREAKERS

    print_test_result(ft_printf("hello") == 5,"simple 'hello' print");
    print_test_result(ft_printf("")== 0 , "empty string");
    print_test_result(ft_printf(NULL)== -1,"NULL string pointer as first parameter");
    print_test_result(ft_printf("hello there % lx") == 13,"Not handled converter");

    // BREAKERS
    print_white();
    printf("End mandatory ---------------------------------------------------\n");
    print_black();
}