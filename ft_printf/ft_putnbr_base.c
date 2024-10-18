/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 23:11:49 by lloginov          #+#    #+#             */
/*   Updated: 2024/05/24 18:59:35 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	erreure(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (!str || ft_strlen(str) < 2)
		return (0);
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	teste(int i, int *n, char *base)
{
	while (i > 0)
	{
		i--;
		ft_printe(base[n[i]]);
	}
}

int	ft_putnbr_base(unsigned long long nbr, char *base)
{
	int	i;
	int	n[16];
	int	size;
	int	len;

	i = 0;
	len = 0;
	if (erreure(base))
	{
		if (nbr == 0)
		{
			ft_printe(base[0]);
			return (1);
		}
		size = ft_strlen(base);
		while (nbr)
		{
			n[i] = nbr % size;
			nbr = nbr / size;
			i++;
		}
		len = i;
		teste(i, n, base);
	}
	return (len);
}

// int main()
// {
// 	char *ptr;

// 	ptr = "aaa";

// 	ft_putnbr_base(41, "87");
// 	printf("\n");
// 	ft_putnbr_base(-123, "0123456789");
// 	printf("\n");
// 	ft_putnbr_base(255, "0123456789abcdef");
// 	printf("\n");
// 	unsigned int a = -1145114;
// 	int b = -1;
// 	printf("%x\n", a);
// 	printf("%x\n", b);

// 	printf("%d\n", a);
// 	printf("%d\n", b);

// 	printf("%u\n", a);
// 	printf("%u\n", b);
// 	return 0;

// 	return 0;
// }
