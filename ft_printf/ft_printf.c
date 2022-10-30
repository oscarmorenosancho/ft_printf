/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:58:50 by omoreno-          #+#    #+#             */
/*   Updated: 2022/10/30 13:07:36 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static size_t	ft_process_int_arg(char **p, va_list ap)
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

static size_t	ft_process_char_arg(char **p, va_list ap)
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

static size_t	ft_process_arg(char **p, va_list ap)
{
	size_t	printed;
	char	flag;

	printed = 0;
	if (!p || !*p)
		return (printed);
	flag = **p;
	if (flag == 'd')
	{
		(*p)++;
		printed += ft_process_int_arg(p, ap);
	}
	else if (flag == 'c')
	{
		(*p)++;
		printed += ft_process_char_arg(p, ap);
	}
	return (printed);
}

int	ft_printf(const char *fmt, ...)
{
	char	*p;
	size_t	printed;
	va_list	ap;

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
			printed = ft_process_arg(&p, ap);
		}
	}
	va_end(ap);
	return (printed);
}
