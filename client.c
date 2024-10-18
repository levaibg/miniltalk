/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:33:26 by lloginov          #+#    #+#             */
/*   Updated: 2024/10/17 19:32:01 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "minitalk.h"


int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number * sign);
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Erreur : envoi du signal SIGUSR1\n");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Erreur : envoi du signal SIGUSR2\n");
				exit(1);
			}
		}
		bit--;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("Erreur : %s <PID> <Message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	send_char(pid, '\0');
	return (1);
}
