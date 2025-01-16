/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:58:33 by didimitr          #+#    #+#             */
/*   Updated: 2025/01/15 22:39:25 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void handler0(int sig)
{
    write(1, "0", 1);
}
void handler1(int sig)
{
    write(1, "1", 1);
}

int main(void)
{
    int i;
    signal(SIGUSR1, handler0);
    signal(SIGUSR2, handler1);

    i = getpid();
    printf("PID:%d \n", i);    
    while(1)
        pause();
    return(1);       
}