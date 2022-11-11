/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:18:24 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/11 21:46:32 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char *s = "%d %s%s";

	ft_printf(s, 55, "www", "hl");
	// int x = 0;
	// //x = printf("hello %");
	// int y = ft_printf("|hello |%  ,n|\n not low");l
	// printf("%d original === %d mine \n",(x ? x : -1), y);
	return (0);
}