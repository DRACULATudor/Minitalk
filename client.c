/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:58:03 by tlupu             #+#    #+#             */
/*   Updated: 2024/04/29 17:05:14 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("\t%s%s%s\n", GREEN, "Message delivered", END);
	else if (sig == SIGUSR2)
		ft_printf("\t%s%s%s\n", RED, "Message was not delivered", END);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		write(2, "Invalid PID=Negative PID\n", 25);
		exit(1);
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}



int	main(int argc, char *argv[])
{
	struct sigaction action;
	int pid_serv;
	if (argc != 3)
	{
		ft_printf("<-->Invalid arguments<-->\n");
		return (1);
	}
	action.sa_handler = signal_handler;
	action.sa_flags = 0;
	sigemptyset(&action.sa_mask);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	pid_serv = ft_atoi(argv[1]);
	send_characters(pid_serv, argv[2], ft_strlen_pf(argv[2]));
	return (0);
}