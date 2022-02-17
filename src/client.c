/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:07:26 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/16 02:01:31 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 199309L
#include "../includes/minitalk.h"

static void	ft_send_char(char c, __pid_t pid);

static void	su1_handler(int s, siginfo_t *info, void *v)
{
	// write(1, "OK\n", 3);
}

int	main(int ac, char *av[])
{
	int	i = -1;
	struct sigaction act;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = su1_handler;
	sigaction(SIGUSR1, &act, NULL);
	while (av[2][++i])
		ft_send_char(av[2][i], (__pid_t) atoi(av[1]));
	ft_send_char('\0', (__pid_t) atoi(av[1]));

	return (0);
}

static void	ft_send_char(char c, __pid_t pid)
{
	unsigned int	byte;

	byte = 8;
	while (byte--)
	{
		if ((c >> byte) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		// pause();
		usleep(300);
	}
}
