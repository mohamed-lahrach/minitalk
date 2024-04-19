/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahrach <mlahrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:42:14 by mlahrach          #+#    #+#             */
/*   Updated: 2024/04/18 20:46:33 by mlahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	char_sent(char c, long int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putstr("problem in send signal");
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putstr("problem in send signal");
				exit(1);
			}
		}
		usleep(150);
		bit--;
	}
}

int	main(int argc, char *argv[])
{
	long int	pid;
	int			i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0 || pid > 2147483647 || ft_strlen(argv[1]) > 12)
		{
			ft_putstr("Invalid pid\n");
			exit(0);
		}
		i = 0;
		while (argv[2][i])
		{
			char_sent(argv[2][i], pid);
			i++;
		}
		char_sent(argv[2][i], pid);
	}
	else
		ft_putstr("There is an error in the arguments!");
}
