
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nb)
{
    if (nb < 0)
    {
        ft_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
        nb = nb % 10;
    }
    if (nb < 10)
        ft_putchar(nb + 48);
}
void sig_handler(int signo)
{
    static char c;
    static int byte;

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

int main(void)
{
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);
    long int pid = getpid();
    write(1, "PID: ", 6);
    ft_putnbr(pid);
    write(1, "\n", 1);
    while (1);
    return 0;
}