/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delegates2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:39:35 by omoreno-          #+#    #+#             */
/*   Updated: 2022/11/02 16:15:56 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_process_uint_arg(char **p, va_list *ap)
{
	long			printed;
	unsigned int	val;
	char			str[14];

	printed = 0;
	if (!p || !*p || !ap)
		return (-1);
	val = va_arg(*ap, unsigned int);
	printed = ft_utobuf(val, str);
	str[printed] = 0;
	if (! ft_putstr_fd(str, 1))
		return (-1);
	return (printed);
}

long	ft_process_uihex_arg(char **p, va_list *ap)
{
	long			printed;
	unsigned int	val;
	char			str[9];

	printed = 0;
	if (!p || !*p || !ap)
		return (-1);
	val = va_arg(*ap, unsigned int);
	printed = ft_utohex(val, str);
	str[printed] = 0;
	if (! ft_putstr_fd(str, 1))
		return (-1);
	return (printed);
}

long	ft_process_uihex_up_arg(char **p, va_list *ap)
{
	long			printed;
	unsigned int	val;
	char			str[9];
	int				i;

	printed = 0;
	if (!p || !*p || !ap)
		return (-1);
	val = va_arg(*ap, unsigned int);
	printed = ft_utohex(val, str);
	str[printed] = 0;
	i = 0;
	while (str[i])
	{
		str[i] = (char)ft_toupper(str[i]);
		i++;
	}
	if (! ft_putstr_fd(str, 1))
		return (-1);
	return (printed);
}

long	ft_process_pointer_arg(char **p, va_list *ap)
{
	long			printed;
	size_t			num_len;
	void			*val;
	char			str[17];

	printed = 0;
	if (!p || !*p || !ap)
		return (-1);
	str[0] = 0;
	if (! ft_putstr_fd("0x", 1))
		return (-1);
	printed += 2;
	val = va_arg(*ap, void *);
	num_len = ft_utohex((unsigned long)val, str);
	str[num_len] = 0;
	printed += num_len;
	if (! ft_putstr_fd(str, 1))
		return (-1);
	return (printed);
}

long	ft_process_perc_arg(char **p, va_list *ap)
{
	void	*ap_p;

	ap_p = ap;
	if (!p || !*p || !ap)
		return (-1);
	if (! ft_putchar_fd('%', 1))
		return (-1);
	return (1);
}
