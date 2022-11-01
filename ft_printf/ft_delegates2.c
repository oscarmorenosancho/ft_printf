/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delegates2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:39:35 by omoreno-          #+#    #+#             */
/*   Updated: 2022/11/01 13:29:43 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_process_uihex_up_arg(char **p, va_list ap)
{
	size_t			printed;
	unsigned int	val;
	char			str[9];
	int				i;

	printed = 0;
	if (!p || !*p)
		return (printed);
	val = va_arg(ap, unsigned int);
	printed = ft_utohex(val, str);
	str[printed] = 0;
	i = 0;
	while (str[i])
	{
		str[i] = (char)ft_toupper(str[i]);
		i++;
	}
	ft_putstr_fd(str, 1);
	return (printed);
}

size_t	ft_process_pointer_arg(char **p, va_list ap)
{
	size_t			printed;
	size_t			num_len;
	void			*val;
	char			str[17];

	printed = 0;
	if (!p || !*p)
		return (printed);
	str[0] = 0;
	ft_putstr_fd("0x", 1);
	printed += 2;
	val = va_arg(ap, void *);
	num_len = ft_utohex((unsigned long)val, str);
	str[num_len] = 0;
	printed += num_len;
	ft_putstr_fd(str, 1);
	return (printed);
}
