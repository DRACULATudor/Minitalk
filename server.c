/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:58:00 by tlupu             #+#    #+#             */
/*   Updated: 2024/05/03 17:49:22 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_decrypt(int signum, siginfo_t *info, void *s)
{
	static int	bits = 0;
	static char	received_char = 0;

	(void)s;
	if (signum == SIGUSR1)
		received_char |= (1 << bits);
	else if (signum == SIGUSR2)
		received_char &= ~(1 << bits);
	bits++;
	if (bits == 8)
	{
		if (received_char != '\0')
		{
			if (received_char != '\n')
			{
				ft_printf("%c", received_char);
			}
			else if (received_char == '\n')
			{
				ft_printf("\n");
			}
		}
		else
			ft_printf("\n");
		bits = 0;
		received_char = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction act;
	int pid;
	pid = getpid();
	printf("Server PID is :%d\n", pid);
	act.sa_sigaction = signal_decrypt;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}