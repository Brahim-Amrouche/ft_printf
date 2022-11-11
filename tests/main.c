/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:13:44 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/11 22:14:30 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"
#include "ft_printf.h"

int main()
{
    print_white();
    printf("Mandatory ------------------------------------------------------\n");
    // BREAKERS

    print_test_result(ft_printf("hello") == 5,"simple 'hello' print");
    print_test_result(ft_printf("")== 0 , "empty string");
    print_test_result(ft_printf(NULL)== -1,"NULL string pointer as first parameter");
    print_test_result(ft_printf("hello there % lx") == 13,"Not handled converter");
    print_test_result(ft_printf("still %lu %n s")== 10 , "Another Not handled converters");
    print_test_result(ft_printf(" %d %s%",10,"www")== 7,"%% before the \\0");
    print_test_result(ft_printf("%c") == 1,"Char converter without a parametre passed");
    print_test_result(ft_printf("%c",'a') == 1,"Char converter with parameter passed");
    print_test_result(ft_printf("%c",0) == 1,"Printin null char");
    print_test_result(ft_printf("%c",-10) == 1,"Printin negative char");
    print_test_result(ft_printf(""),"work ?");
    
    // BREAKERS
    print_white();
    printf("End mandatory ---------------------------------------------------\n");
    print_black();
}