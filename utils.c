#include <unistd.h>

long int ft_atoi(const char *str) {
    long int i = 0;
    long int sign = 1;
    unsigned long long result = 0;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while ((str[i] >= '0' && str[i] <= '9') && str[i]) {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (str[i])
        return (0);
    return (result * sign);
}

void ft_putstr(char *str) {
    while (*str) {
        write(1, str, 1);
        str++;
    }
}

int ft_strlen(char *str) {
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putnbr(int nb) {
    if (nb < 0) {
        ft_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        ft_putnbr(nb / 10);
        nb = nb % 10;
    }
    if (nb < 10)
        ft_putchar(nb + 48);
}