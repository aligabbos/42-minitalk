/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsemerar <gsemerar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:31:25 by gsemerar          #+#    #+#             */
/*   Updated: 2022/02/08 11:52:41 by gsemerar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define DECIMAL "0123456789"
# define HEX_ALPHA "0123456789abcdef"
# define HEX_ALPHA_UPPER "0123456789ABCDEF"
# define UPPER 1
# define LOWER 0

typedef struct s_print
{
	va_list	args;
	int		width;
	int		precision;
	int		dash;
	int		zero;
	int		dot;
	int		hashtag;
	int		space;
	int		plus;
	int		sign;
	int		null_str;
	int		total_length;
}	t_print;

int		ft_printf(const char *s, ...);

//format utils
int		ft_check_format(t_print **format, const char *str, int index);
//printf utils
void	ft_print_format(t_print *format, char c);
void	ft_initialize_format(t_print **format);
void	ft_re_initialize_format(t_print **format);
void	ft_padding(t_print *format, char c, int len);
//print chars
void	ft_print_char(t_print *format);
void	ft_print_str(t_print *format);
void	ft_print_percentage(t_print *format);
//char utils
int		ft_calculate_str_padding(t_print *format, char *str);
int		ft_str_length(t_print *format, char *str);
char	*ft_null_str(t_print *format);
//print pointers
void	ft_print_ptr(t_print *format);
void	ft_print_null_ptr(t_print *format);
//pointer utils
char	*ft_ultoaptr(unsigned long n);
//print numbers
void	ft_print_digit(t_print *format);
void	ft_print_unsigned_digit(t_print *format);
void	ft_print_hex(t_print *format, int upper);
//number utils
char	*ft_ditoa(t_print *format, int n);
char	*ft_uitoa(t_print *format, unsigned int n);
char	*ft_uitoahex(unsigned int n, int upper);
char	*ft_hex(t_print *format, unsigned int n, int upper);

#endif
