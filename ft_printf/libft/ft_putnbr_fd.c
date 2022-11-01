/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:17:32 by omoreno-          #+#    #+#             */
/*   Updated: 2022/11/01 17:26:58 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_get_last_digit(unsigned long *n, unsigned int base)
{
	char	ls;

	ls = *n % base;
	*n = *n / base;
	return (ls);
}

size_t	ft_utobuf(unsigned long nb, char *buf)
{
	unsigned long	restant_digits;
	size_t			ret;
	char			digit;

	ret = 0;
	restant_digits = nb;
	digit = '0' + ft_get_last_digit(&restant_digits, 10);
	if (restant_digits > 0)
		ret = ft_utobuf(restant_digits, buf);
	buf[ret] = digit;
	return (ret + 1);
}

int	ft_putnbr_fd(int n, int fd)
{
	char		neg;
	long int	aux;
	size_t		len;
	char		buf[12];
	char		*p;

	p = buf;
	neg = (n < 0);
	aux = (long int) n;
	if (neg)
	{
		aux = -aux;
		buf[0] = '-';
		p++;
	}
	len = ft_utobuf ((unsigned int)aux, p);
	p[len] = 0;
	return (ft_putstr_fd(buf, fd));
}
