#ifndef MAIN_H
#define MAIN_H

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function declarations from client.c
long int	ft_atoi(const char *str);
void	ft_putstr(char *str);
int	ft_strlen(char *str);

// Function declarations from server.c
void	ft_putchar(char c);
void	ft_putnbr(int nb);

#endif