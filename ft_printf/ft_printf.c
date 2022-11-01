/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:58:50 by omoreno-          #+#    #+#             */
/*   Updated: 2022/11/01 19:36:28 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ft_process_arg(char **p, va_list *ap, t_delegate_map *map)
{
	char	flag;
	int		i;
	int		put_ret;

	if (! p || ! *p || ! map)
		return (0);
	flag = **p;
	(*p)++;
	i = 0;
	while (i < DLGT_MAP_TAB_SIZE && map[i].c)
	{
		if (flag == map[i].c)
		{
			return ((*(map[i].ft_delegate))(p, ap));
		}
		i++;
	}
	put_ret = ft_putchar_fd(flag, 1);
	if (! put_ret)
		return (-1);
	return (1);
}

static int	ft_iterate(char **p, int *printed, \
				va_list *ap, t_delegate_map *map)
{
	long	proc_ret;

	if (**p != '%')
	{
		if (! ft_putchar_fd(**p, 1))
			return (-1);
		(*p)++;
		(*printed)++;
		return (*printed);
	}
	(*p)++;
	proc_ret = ft_process_arg(p, ap, map);
	if (proc_ret < 0)
		return (proc_ret);
	*printed += proc_ret;
	return (*printed);
}

int	ft_printf(const char *fmt, ...)
{
	char			*p;
	int				printed;
	va_list			ap;
	t_delegate_map	map[DLGT_MAP_TAB_SIZE];

	ft_fill_delegate_map(map);
	p = (char *)fmt;
	va_start(ap, fmt);
	printed = 0;
	while (*p)
	{
		if (! ft_iterate(&p, &printed, &ap, map))
		{
			va_end(ap);
			return (-1);
		}
	}
	va_end(ap);
	return (printed);
}
