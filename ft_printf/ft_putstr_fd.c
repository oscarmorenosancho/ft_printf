/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:10:59 by omoreno-          #+#    #+#             */
/*   Updated: 2022/11/07 10:42:56 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	ssize_t	len;
	ssize_t	w_r;

	len = (ssize_t) ft_strlen(s);
	w_r = write(fd, s, len);
	return (w_r == len);
}
