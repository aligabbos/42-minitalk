/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:40:44 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/17 17:53:33 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

//	ELIMINARE	//
# include <stdio.h>
/////////////////
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "../ft_printf/includes/ft_printf.h"

# define BAD_MEMORY_ALLOCATION 1

typedef struct s_str
{
	char			*str;
	unsigned int	n_bit;
	unsigned int	n_byte_str;
}	t_str;

#endif
