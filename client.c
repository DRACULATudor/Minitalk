/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:58:03 by tlupu             #+#    #+#             */
/*   Updated: 2024/05/03 17:48:58 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack = 0;

int	ft_atoi(const char *str)
{
	int	sign;
	int	value;

	sign = 1;
	value = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	while (*str >= '0' && *str <= '9')
		value = value * 10 + (*str++ - '0');
	if (*str != (*str >= '0' && *str <= '9'))
	{
		ft_printf("\t%s%s%s\n", RED, "Error: PID incorrect");
		exit(1);
	}
	return (sign * value);
}

void	received(int sig)
{
	(void)sig;
	g_ack = 1;
}

void	send_charact(int pid, char chr)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ack = 0;
		if (chr & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		while (!g_ack)
			pause();
	}
}

void	send_characters(int pid, char *str, int num)
{
	int	i;

	i = 0;
	while (i < num)
		send_charact(pid, str[i++]);
}

int	main(int argc, char *argv[])
{
	int	pid_serv;

	if (argc != 3)
	{
		ft_printf("<-->Invalid arguments<-->\n");
		return (1);
	}
	pid_serv = ft_atoi(argv[1]);
	signal(SIGUSR1, received);
	send_characters(pid_serv, argv[2], ft_strlen_pf(argv[2]));
	send_charact(pid_serv, '\0');
	return (0);
}
