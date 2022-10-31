/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:22:03 by omoreno-          #+#    #+#             */
/*   Updated: 2022/10/31 15:30:59 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("\\ n: %d\n", ft_printf("%c", 'D'));
	ft_printf("\\ n: %d\n", ft_printf("%s", "asdf1234"));
	ft_printf("\\ n: %d\n", ft_printf("%i", 10));
	ft_printf("\\ n: %d\n", ft_printf("%d", 999));
	ft_printf("\\ n: %d\n", ft_printf("%%", 999));
	ft_printf("\\ n: %d\n", ft_printf(" %c ", '0'));
	ft_printf("\n");
	ft_printf("\\ n: %d\n", ft_printf(" %c", '0' - 256));
	ft_printf("\n");
	ft_printf("\\ n: %d\n", ft_printf(" %c %c %c ", '0', 0, '1'));
	ft_printf("\n");
	ft_printf("\\ n: %d\n", ft_printf(" %c %c %c ", ' ', ' ', ' '));
	ft_printf("\n");
	ft_printf("\\ n: %d\n", ft_printf(" %c %c %c ", '1', '2', '3'));
	ft_printf("\n");
	ft_printf("\\ n: %d\n", ft_printf(" %c %c %c ", '2', '1', 0));
	ft_printf("\n");
	ft_printf("\\ n: %d\n", ft_printf(" %c %c %c ", 0, '1', '2'));
	ft_printf("\n");
	return (0);
}
