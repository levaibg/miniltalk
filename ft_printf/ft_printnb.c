/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:09:53 by lloginov          #+#    #+#             */
/*   Updated: 2024/05/17 20:50:58 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int n)
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

int	ft_printnb(int n)
{
	int	len;

	len = ft_nbrlen(n);
	ft_putnbr_fd(n, 1);
	return (len);
}
