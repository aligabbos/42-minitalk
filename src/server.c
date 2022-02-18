/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:07:24 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/18 15:28:27 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_character	g_c;

static void	ft_sigusr1_handler(int s, siginfo_t *info, void *v);
static void	ft_sigusr2_handler(int s, siginfo_t *info, void *v);

int	main(void)
{
	struct sigaction	su1;
	struct sigaction	su2;

	su1.sa_flags = SA_SIGINFO;
	su2.sa_flags = SA_SIGINFO;
	su1.sa_sigaction = ft_sigusr1_handler;
	su2.sa_sigaction = ft_sigusr2_handler;
	sigaction(SIGUSR1, &su1, NULL);
	sigaction(SIGUSR2, &su2, NULL);
	g_c.n_bit = 0;
	g_c.character = 0;
	ft_printf("Server PID:\t%d\n", getpid());
	while (1)
		pause();
	return (0);
}

static void	ft_sigusr1_handler(int s, siginfo_t *info, void *v)
{
	(void) s;
	(void) v;
	g_c.character <<= 1;
	g_c.character |= 1;
	g_c.n_bit += 1;
	if (g_c.n_bit == 8)
	{
		write(1, &g_c.character, 1);
		g_c.character = 0;
		g_c.n_bit = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

static void	ft_sigusr2_handler(int s, siginfo_t *info, void *v)
{
	(void) s;
	(void) v;
	g_c.character <<= 1;
	g_c.n_bit += 1;
	if (g_c.n_bit == 8)
	{
		write(1, &g_c.character, 1);
		g_c.character = 0;
		g_c.n_bit = 0;
		kill(info->si_pid, SIGUSR1);
	}
}
