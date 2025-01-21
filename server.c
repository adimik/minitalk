/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:58:33 by didimitr          #+#    #+#             */
/*   Updated: 2025/01/21 17:10:58 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	assembler(int sig)
{
	static int	i = 0;
	static char	c = 0;

	if (sig == SIGUSR2)
		c |= 1 << i++;
	else
		i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	itoa(int pid)
{
	int	i;

	if (pid > 9)
		itoa(pid / 10);
	i = pid % 10 + '0';
	write(1, &i, 1);
}

int	main(void)
{
	int	i;

	signal(SIGUSR1, &assembler);
	signal(SIGUSR2, &assembler);
	i = getpid();
	write(1, "PID:", 4);
	itoa(i);
	write(1, "\n", 1);
	while (1)
		pause();
	return (1);
}
