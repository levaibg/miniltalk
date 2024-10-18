/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:13:33 by lloginov          #+#    #+#             */
/*   Updated: 2024/05/17 20:54:23 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(unsigned int n)
{
	int	len;

	len = 1;
	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	print_unsigned(unsigned int nb)
{
	unsigned int	len;

	len = ft_nbrlen(nb);
	if (nb > 9)
	{
		print_unsigned(nb / 10);
	}
	ft_printe(nb % 10 + '0');
	return (len);
}

// int main(void)
// {
// 	unsigned int number = -14;

// 	printf("printf ; %u \n	",number);
// 	print_unsigned(number);
// 	return 0;
// }