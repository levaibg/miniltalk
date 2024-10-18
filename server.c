/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:33:33 by lloginov          #+#    #+#             */
/*   Updated: 2024/10/17 19:31:52 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_btoa(int sigur)
{
	static int	bit_pos = 0;
	static char	character = 0;

	if (sigur == SIGUSR1)
		character |= (1 << (7 - bit_pos));
	bit_pos++;
	if (bit_pos == 8)
	{
		ft_printf("%c", character);
		if (character == '\0')
			ft_printf("\n");
		character = 0;
		bit_pos = 0;
	}
}


int main(void)
{
    int pid;

    pid = getpid();
    ft_printf("Pid : %i\n", pid);
    while (1)
    {
        signal(SIGUSR1,ft_btoa);
        signal(SIGUSR2, ft_btoa);
        pause ();
    }
    return (0);
}