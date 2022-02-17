/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:40:44 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/17 19:28:24 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "../ft_printf/includes/ft_printf.h"

# define FEW_ARGUMENTS 1

typedef struct s_character
{
	unsigned char	character;
	unsigned int	n_bit;
}	t_character;

typedef struct s_bytesr
{
	unsigned int	byte_sent;
	unsigned int	byte_received;
}	t_bytesr;

#endif
