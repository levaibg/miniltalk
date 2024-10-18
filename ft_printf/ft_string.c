/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:40:02 by lloginov          #+#    #+#             */
/*   Updated: 2024/05/17 20:50:44 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_string(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	else
	{
		write(1, "(null)", 6);
		i += 6;
	}
	return (i);
}
