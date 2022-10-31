/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:59:25 by omoreno-          #+#    #+#             */
/*   Updated: 2022/10/31 15:58:02 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DLGT_MAP_TAB_SIZE 10

//# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef size_t	(*t_ft_delegate)(char **p, va_list ap);

typedef struct s_delegate_map
{
	char			c;
	t_ft_delegate	ft_delegate;
}	t_delegate_map;

size_t	ft_process_int_arg(char **p, va_list ap);
size_t	ft_process_uint_arg(char **p, va_list ap);
size_t	ft_process_char_arg(char **p, va_list ap);
size_t	ft_process_str_arg(char **p, va_list ap);
int		ft_printf(const char *fmt, ...);
#endif