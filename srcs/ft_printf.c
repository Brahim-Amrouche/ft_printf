/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:56:58 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/08 00:54:45 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

// void	print_flags(t_grouped_flags flags)
// {
// 	printf("format exists == %d \n", flags.format.exists);
// 	printf("precision exists == %d \n", flags.precision.exists);
// 	printf("plus exists == %d \n", flags.plus.exists);
// 	printf("space exists == %d \n", flags.space.exists);
// 	printf("minus exists == %d \n", flags.minus.exists);
// 	printf("zero exists == %d \n ------------- \n", flags.zero.exists);
// }

int	ft_manage_printf_flags(va_list args, char *str, size_t *index)
{
	ssize_t			printed_chars;
	size_t			i;
	t_grouped_flags	flags;

	printed_chars = 0;
	ft_bzero(&flags, sizeof(t_grouped_flags));
	i = ft_parse_flags(str, &flags, index);
	if (str[i] == 'c')
		printed_chars = ft_print_char(va_arg(args, int));
	else if (str[i] == 's')
		printed_chars = ft_print_str(va_arg(args, char *));
	else if (str[i] == 'p')
		printed_chars = ft_print_pointer(va_arg(args,unsigned int));
	else if (str[i] == 'd')
		printed_chars = ft_print_number(va_arg(args,int));
	else if (str[i] == 'i')
		printed_chars = ft_print_number(va_arg(args,int));
	else if (str[i] == 'u')
		printed_chars = ft_print_number(va_arg(args,unsigned int));
	else if (str[i] == 'x')
		return (1);
	else if (str[i] == 'X')
		return (1);
	else if (str[i] == '%')
		printed_chars = ft_print_char('%');
	return (printed_chars);
}

int	ft_printf(char *s, ...)
{
	size_t	i;
	size_t	printed_chars;
	va_list	args;

	va_start(args, s);
	i = 0;
	printed_chars = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			printed_chars += ft_manage_printf_flags(args, s + i, &i);
			i++;
			continue ;
		}
		printed_chars += ft_print_char(s[i]);
		i++;
	}
	va_end(args);
	return (printed_chars);
}
