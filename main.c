/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:18:24 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/12 19:08:16 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int x = printf("%-------------3c", 'a');
	int y = ft_printf("%-----------3c", 'a');

	printf("this is original %d === and mine %d", x, y);
	// int x = 0;
	// //x = printf("hello %");
	// int y = ft_printf("|hello |%  ,n|\n not low");l
	// printf("%d original === %d mine \n",(x ? x : -1), y);
	return (0);
}