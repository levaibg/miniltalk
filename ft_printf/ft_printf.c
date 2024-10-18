/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 19:27:35 by lloginov          #+#    #+#             */
/*   Updated: 2024/10/17 17:22:34 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	check(const char *input, va_list args)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += ft_printe(va_arg(args, int));
	else if (*input == 's')
		i += ft_string(va_arg(args, char *));
	else if (*input == 'p')
		i += print_ptr(va_arg(args, char *), "0123456789abcdef");
	else if (*input == 'd' || *input == 'i')
		i += ft_printnb(va_arg(args, int));
	else if (*input == 'u')
		i += print_unsigned(va_arg(args, unsigned int));
	else if (*input == 'x')
		i += ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (*input == 'X')
		i += ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	return (i);
}

int	ft_printf(const char *input, ...)
{
	unsigned int	f;
	va_list			args;

	if (!input)
		return (-1);
	va_start(args, input);
	f = 0;
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", *input))
				f += check(input, args);
			else if (*input == '%')
				f += ft_printe('%');
		}
		else
			f += ft_printe(*input);
		input++;
	}
	va_end(args);
	return (f);
}

// int main(void)
// {
// 	char caca = 'e';
// 	char *pipi = "sisi";
// 	int n = 45;
// 	unsigned int f = -12;

// 	ft_printf("%%, %s, %c, %p, %d, %u, %u, %X" ,pipi,caca,pipi,n,f,n,f);
// 	printf("\n");
// 	printf("%%, %s, %c, %p, %d, %u, %u, %X" ,pipi,caca,pipi,n,f,n,f);
// 	return 0;
// }