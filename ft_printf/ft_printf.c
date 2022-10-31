/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:58:50 by omoreno-          #+#    #+#             */
/*   Updated: 2022/10/31 11:51:29 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_process_int_arg(char **p, va_list ap);
size_t	ft_process_char_arg(char **p, va_list ap);

void	ft_fill_delegate_map_el(t_delegate_map	*map, \
			char c, t_ft_delegate ft_delegate)
{
	map->c = c;
	map->ft_delegate = ft_delegate;
}

void	ft_fill_delegate_map(t_delegate_map	*map)
{
	ft_fill_delegate_map_el(map + 0, 'i', ft_process_int_arg);
	ft_fill_delegate_map_el(map + 1, 'd', ft_process_int_arg);
	ft_fill_delegate_map_el(map + 2, 'c', ft_process_char_arg);
}

static size_t	ft_process_arg(char **p, va_list ap, t_delegate_map	*map)
{
	char			flag;
	int				i;

	if (!p || !*p || ! map)
		return (0);
	flag = **p;
	(*p)++;
	i = 0;
	while (i < DLGT_MAP_TAB_SIZE && map[i].c)
	{
		if (flag == map[i].c)
		{
			return ((*(map[0].ft_delegate))(p, ap));
		}
		i++;
	}
	write(1, &flag, 1);
	return (1);
}

int	ft_printf(const char *fmt, ...)
{
	char			*p;
	size_t			printed;
	va_list			ap;
	t_delegate_map	map[DLGT_MAP_TAB_SIZE];

	ft_fill_delegate_map(map);
	p = (char *)fmt;
	va_start(ap, fmt);
	while (*p)
	{
		if (*p != '%')
		{
			write(1, p, 1);
			p++;
			printed++;
		}
		else
		{
			p++;
			printed = ft_process_arg(&p, ap, map);
		}
	}
	va_end(ap);
	return (printed);
}
