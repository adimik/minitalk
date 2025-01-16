/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:58:33 by didimitr          #+#    #+#             */
/*   Updated: 2025/01/16 17:08:59 by didimitr         ###   ########.fr       */
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

void	handler0(void)
{
	write(1, "0", 1);
}
void	handler1(void)
{
	write(1, "1", 1);
}

int	main(void)
{
	int i;
	signal(SIGUSR1, &assembler);
	signal(SIGUSR2, &assembler);

	i = getpid();
	printf("PID:%d \n", i);
	while (1)
		pause();
	return (1);
}