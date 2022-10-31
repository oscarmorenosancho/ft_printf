/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delegates.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:39:35 by omoreno-          #+#    #+#             */
/*   Updated: 2022/10/31 11:55:26 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_process_int_arg(char **p, va_list ap)
{
	size_t	printed;
	int		val;
	char	*str;

	printed = 0;
	if (!p || !*p)
		return (printed);
	val = va_arg(ap, int);
	str = ft_itoa(val);
	if (str)
	{
		printed = ft_strlen(str);
		ft_putstr_fd(str, 1);
		free(str);
	}
	return (printed);
}

size_t	ft_process_char_arg(char **p, va_list ap)
{
	size_t	printed;
	char	val;

	printed = 0;
	if (!p || !*p)
		return (printed);
	val = va_arg(ap, int);
	printed++;
	ft_putchar_fd(val, 1);
	return (printed);
}