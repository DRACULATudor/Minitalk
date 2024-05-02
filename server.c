/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlupu <tlupu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:58:00 by tlupu             #+#    #+#             */
/*   Updated: 2024/05/02 13:52:28 by tlupu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    signal_decrypt()

int main(void)
{
    struct sigaction    act;
    int     pid;
    pid = getpid();
    printf("Server PID is :%d\n", pid);
    act.sa_flags = SIGINT;
    act.sa_handler = signal_decrypt;
    
    
}