/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delegates.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:39:35 by omoreno-          #+#    #+#             */
/*   Updated: 2022/11/01 19:41:31 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_delegate_map_el(t_delegate_map	*map, \
			char c, t_ft_delegate ft_delegate)
{
	map->c = c;
	map->ft_delegate = ft_delegate;
}

void	ft_fill_delegate_map(t_delegate_map	*map)
{
	ft_fill_delegate_map_el(map + 0, 'i', &ft_process_int_arg);
	ft_fill_delegate_map_el(map + 1, 'd', &ft_process_int_arg);
	ft_fill_delegate_map_el(map + 2, 'u', &ft_process_uint_arg);
	ft_fill_delegate_map_el(map + 3, 'x', &ft_process_uihex_arg);
	ft_fill_delegate_map_el(map + 4, 'X', &ft_process_uihex_up_arg);
	ft_fill_delegate_map_el(map + 5, 'c', &ft_process_char_arg);
	ft_fill_delegate_map_el(map + 6, 's', &ft_process_str_arg);
	ft_fill_delegate_map_el(map + 7, 'p', &ft_process_pointer_arg);
	ft_fill_delegate_map_el(map + 8, '%', &ft_process_perc_arg);
}

long	ft_process_int_arg(char **p, va_list *ap)
{
	long	printed;
	int		val;
	char	*str;
	int		put_ret;

	printed = 0;
	if (!p || !*p || !ap)
		return (printed);
	val = va_arg(*ap, int);
	str = ft_itoa(val);
	if (str)
	{
		printed = (long) ft_strlen(str);
		put_ret = ft_putstr_fd(str, 1);
		free (str);
		if (! put_ret)
			return (-1);
	}
	return (printed);
}

long	ft_process_char_arg(char **p, va_list *ap)
{
	char	val;
	int		put_ret;

	if (!p || !*p || !ap)
		return (0);
	val = va_arg(*ap, int);
	put_ret = ft_putchar_fd(val, 1);
	if (! put_ret)
		return (-1);
	return (1);
}

long	ft_process_str_arg(char **p, va_list *ap)
{
	char	*val;
	int		put_ret;
	size_t	len;		

	if (!p || !*p || !ap)
		return (0);
	val = va_arg(*ap, char *);
	if (val)
	{
		len = ft_strlen(val);
		if (! len)
			return (0);
		put_ret = ft_putstr_fd(val, 1);
		if (! put_ret)
			return (-1);
		return (ft_strlen(val));
	}
	ft_putstr_fd("(null)", 1);
	return (6);
}
