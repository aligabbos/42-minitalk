/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:07:24 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/16 02:44:32 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 199309L
#include "../includes/minitalk.h"

t_str	c;

static void	ft_sigusr1_handler(int s, siginfo_t *info, void *v);
static void	ft_sigusr2_handler(int s, siginfo_t *info, void *v);
static void	ft_allocate_more_space(void);
static void	ft_print_server(void);
static void	put_nbr_base(unsigned char num, unsigned int bl, char *base);

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
	c.str = NULL;
	c.n_bit = 0;
	c.n_byte_str = 4;
	ft_allocate_more_space();
	ft_printf("%d\n", getpid());
	while (1)
		pause();
	return (0);
}

static void	ft_sigusr1_handler(int s, siginfo_t *info, void *v)
{
	// ft_putchar_fd('1', 1);
	c.str[c.n_bit / 8] <<= 1;
	c.str[c.n_bit / 8] |= 1;
	c.n_bit += 1;
	ft_allocate_more_space();
	// put_nbr_base(c.str[0], 10, "0123456789");
	// ft_putchar_fd('\n', 1);
	ft_print_server();
	kill(info->si_pid, SIGUSR1);
}

static void	ft_sigusr2_handler(int s, siginfo_t *info, void *v)
{
	// ft_putchar_fd('0', 1);
	c.str[c.n_bit / 8] <<= 1;
	c.n_bit += 1;
	ft_allocate_more_space();
	// put_nbr_base(c.str[1], 10, "0123456789");
	// ft_putchar_fd('\n', 1);
	ft_print_server();
	kill(info->si_pid, SIGUSR1);
}

static void	ft_allocate_more_space(void)
{
	char	*tmp;
	// printf("(BSTR %d) (NBIT %d) (NBIT / 8 %d)\n", c.n_byte_str, c.n_bit, c.n_bit / 8);

	if (!c.n_bit || c.n_bit / 8 >= c.n_byte_str)
	{
		// printf("-> OK <-\n");
		tmp = c.str;
		c.str = (char *) malloc(sizeof(char) * c.n_byte_str + 1);
		c.n_byte_str *= 2;
		ft_memcpy(c.str, tmp, ft_strlen(tmp));
		free(tmp);
		if (!c.str)
			exit(BAD_MEMORY_ALLOCATION);
	}
}

static void	ft_print_server(void)
{
	if (!(c.n_bit % 8) && !(c.str[(c.n_bit / 8) - 1]))
	{
		write(1, c.str, c.n_bit / 8);
		c.n_bit = 0;
		ft_bzero(c.str, ft_strlen(c.str));
	}
}

static void	put_nbr_base(unsigned char num, unsigned int bl, char *base)
{
	if (num > bl - 1)
		put_nbr_base(num / bl, bl, base);
	ft_putchar_fd(base[num % bl], 1);
}
