#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long int	ft_atoi(const char *str)
{
	long int			i;
	long int			sin;
	unsigned long long	rus;

	i = 0;
	sin = 1;
	rus = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sin = -1;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		rus = rus * 10 + (str[i] - '0');
		i++;
	}
	if (str[i])
		return (0);
	return (rus * sin);
}
void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
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
	if (argc == 3)
	{
		long int pid = ft_atoi(argv[1]);
		if (pid <= 0 || pid > 2147483647 || ft_strlen(argv[1]) > 12)
		{
			ft_putstr("Invalid pid\n");
			exit(0);
		}

		int i = 0;

		while (argv[2][i])
		{
			char_sent(argv[2][i], pid);
			i++;
		}
		char_sent(argv[2][i], pid);
	}
	else
	{
		ft_putstr("There is an error in the arguments!");
	}
}