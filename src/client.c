/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:07:26 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/17 19:37:35 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_bytesr	g_bsr;

static void	su1_handler(int s, siginfo_t *info, void *v);
static void	ft_send_char(char c, pid_t pid);

int	main(int ac, char *av[])
{
	int					i;
	struct sigaction	act;

	i = -1;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = su1_handler;
	sigaction(SIGUSR1, &act, NULL);
	g_bsr.byte_sent = 0;
	g_bsr.byte_received = 0;
	if (ac == 3)
	{
		while (av[2][++i])
			ft_send_char(av[2][i], (pid_t) ft_atoi(av[1]));
		ft_printf("Byte sent:\t%d\n", g_bsr.byte_sent);
		ft_printf("Byte received:\t%d\n", g_bsr.byte_received);
	}
	else
		exit(FEW_ARGUMENTS);
	return (0);
}

static void	su1_handler(int s, siginfo_t *info, void *v)
{
	(void) s;
	(void) info;
	(void) v;
	g_bsr.byte_received += 1;
}

static void	ft_send_char(char c, pid_t pid)
{
	unsigned int	byte;

	byte = 8;
	while (byte--)
	{
		if ((c >> byte) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
	g_bsr.byte_sent += 1;
}
