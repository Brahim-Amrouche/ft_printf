/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:18:24 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/12 12:31:09 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	printf("printed chars== %d",printf("|%-10c|",48));
	// int x = 0;
	// //x = printf("hello %");
	// int y = ft_printf("|hello |%  ,n|\n not low");l
	// printf("%d original === %d mine \n",(x ? x : -1), y);
	return (0);
}