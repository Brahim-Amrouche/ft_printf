/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:56:58 by bamrouch          #+#    #+#             */
/*   Updated: 2022/11/06 12:10:59 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_is_format_flag(char *str, t_printf_flag *flag)
{
	if (str[0] == '#')
	{
		flag->exists = TRUE;
		flag->skip = 1;
		return ;
	}
	flag->skip = 0;
}

void ft_is_precision_flag(char *str, t_printf_flag *flag)
{
    if(str[0]== '.')
    {
        flag->exists = TRUE;
        flag->skip = 1;
        return;
    }
    flag->skip=0;
}

void	ft_is_plus_flag(char c, t_printf_flag *flag)
{
	if (c == '+')
	{
		flag->exists = TRUE;
		flag->skip = 1;
		return ;
	}
	flag->skip = 0;
}

void ft_is_space_flag(char c,t_printf_flag *flag)
{
    if ( c == ' ')
	{
		flag->exists = TRUE;
		flag->skip = 1;
		return ;
	}
	flag->skip = 0;
}

void	ft_is_minus_flag(char *str, t_printf_flag *flag)
{
	if (str[0] == '-')
	{
		flag->exists = TRUE;
		flag->skip = 1;
		return ;
	}
	flag->skip = 0;
}

void ft_is_zero_flag(char *str, t_printf_flag *flag)
{
    if ( str[0] == '0')
	{
		flag->exists = TRUE;
		flag->skip = 1;
		return ;
	}
	flag->skip = 0;
}

size_t	ft_sum_skip(t_grouped_flags flags)
{
	return (flags.format.skip + flags.precision.skip + flags.plus.skip
		+ flags.space.skip + flags.minus.skip + flags.zero.skip);
}
void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*res;

	if (count && size > SIZE_MAX / count)
		return (0);
	res = (char *)malloc(count * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < count * size)
		res[i++] = '\0';
	return (res);
}

void print_flags(t_grouped_flags flags)
{
    printf("format exists == %d \n",flags.format.exists);
    printf("precision exists == %d \n",flags.precision.exists);
    printf("plus exists == %d \n",flags.plus.exists);
    printf("space exists == %d \n",flags.space.exists);
    printf("minus exists == %d \n",flags.minus.exists);
    printf("zero exists == %d \n",flags.zero.exists);
}

int	ft_manage_printf_flags(va_list args, char *str)
{
	ssize_t			printed_chars;
	size_t			i;
	t_grouped_flags	*flags;

    (void) printed_chars;
    (void) args;
	i = 1;
    flags = ft_calloc(1,sizeof(t_grouped_flags));
	while (str[i])
	{

		ft_is_format_flag(str + i, &(flags->format));
		ft_is_precision_flag(str + i, &(flags->precision));
		ft_is_plus_flag(str[i], &(flags->plus));
		ft_is_space_flag(str[i], &(flags->space));
		ft_is_minus_flag(str + i, &(flags->minus));
		ft_is_zero_flag(str + i, &(flags->zero));
        if (!ft_sum_skip(*flags))
            break;
        i += ft_sum_skip(*flags);
	}
    print_flags(*flags);
    free(flags);
    return 1;
}

int	ft_printf(char *s, ...)
{
	ssize_t i;
	size_t printed_chars;
	va_list args;

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