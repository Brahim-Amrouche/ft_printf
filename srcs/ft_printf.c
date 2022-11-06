/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:56:58 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/06 15:14:05 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	print_flags(t_grouped_flags flags)
{
	printf("format exists == %d \n", flags.format.exists);
	printf("precision exists == %d \n", flags.precision.exists);
	printf("plus exists == %d \n", flags.plus.exists);
	printf("space exists == %d \n", flags.space.exists);
	printf("minus exists == %d \n", flags.minus.exists);
	printf("zero exists == %d \n", flags.zero.exists);
}

int	ft_manage_printf_flags(va_list args, char *str)
{
	ssize_t			printed_chars;
	size_t			i;
	t_grouped_flags	*flags;

	(void)printed_chars;
	(void)args;
	flags = ft_calloc(1, sizeof(t_grouped_flags));
	i = ft_parse_flags(str, flags);
	free(flags);
	return (1);
}

int	ft_printf(char *s, ...)
{
	ssize_t	i;
	size_t	printed_chars;
	va_list	args;

	va_start(args, s);
	i = 0;
	printed_chars = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			printed_chars += ft_manage_printf_flags(args, s + i);
			i++;
			continue ;
		}
		printed_chars++;
		i++;
	}
	va_end(args);
	return (printed_chars);
}
