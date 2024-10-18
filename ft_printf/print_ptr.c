/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:49:17 by lloginov          #+#    #+#             */
/*   Updated: 2024/05/17 20:53:49 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen_base(unsigned long nbr, int base_len)
{
	int	len;

	len = 1;
	while (nbr >= (unsigned long)base_len)
	{
		nbr /= base_len;
		len++;
	}
	return (len);
}

int	print_ptr(char *ptr, char *base)
{
	int	len;

	len = 0;
	if (ptr)
	{
		ft_putstr_fd("0x", 1);
		len += 2;
		ft_putnbr_base((unsigned long long)ptr, base);
		len += ft_numlen_base((unsigned long long)ptr, ft_strlen(base));
	}
	else
	{
		write(1, "(nil)", 5);
		len += 5;
	}
	return (len);
}
