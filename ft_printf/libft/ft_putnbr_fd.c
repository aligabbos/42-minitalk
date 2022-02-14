/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:23:31 by gsemerar          #+#    #+#             */
/*   Updated: 2022/01/18 11:01:13 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		num *= -1;
		ft_putchar_fd('-', fd);
	}
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	else if (num >= 0)
	{
		ft_putchar_fd(num + '0', fd);
		return ;
	}
	num %= 10;
	ft_putchar_fd(num + '0', fd);
	return ;
}
