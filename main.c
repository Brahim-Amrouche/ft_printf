/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:18:24 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/14 19:34:40 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#define ARG "|%15c|\n",'a'

int	main(void)
{
	int x = printf(ARG);
	int y = ft_printf(ARG);
	// ft_printf("s");
	printf("this is original %d === and mine %d \n", x, y);
	return (0);
}