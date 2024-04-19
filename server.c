/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:42:08 by mlahrach          #+#    #+#             */
/*   Updated: 2024/04/18 20:47:40 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	sig_handler(int signo)
{
	static char	c;
	static int	byte;

	if (signo == SIGUSR1)
		c = (c << 1) | 1;
	else if (signo == SIGUSR2)
		c = (c << 1);
	byte++;
	if (byte == 8)
	{
		write(1, &c, 1);
		c = 0;
		byte = 0;
	}
}

int	main(void)
{
	long int	pid;

	pid = getpid();
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	write(1, "PID: ", 6);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		;
	return (0);
}
