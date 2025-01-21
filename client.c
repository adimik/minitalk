/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:18:03 by didimitr          #+#    #+#             */
/*   Updated: 2025/01/21 16:38:30 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	bitshift(char c, int pid)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if (((c >> i) & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(500);
	}
}

void	msgsend(int pid, char *str)
{
	while (*str != '\0')
	{
		bitshift(*str, pid);
		str++;
	}
	bitshift('\0', pid);
}

int	ft_atoi(char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i = i * 10 + (*s - 48);
		s++;
	}
	return (i);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc != 3)
		return (printf("Incorrect Input"));
	i = ft_atoi(argv[1]);
	msgsend(i, argv[2]);
	return (0);
}
