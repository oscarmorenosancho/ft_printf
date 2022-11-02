/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 13:22:03 by omoreno-          #+#    #+#             */
/*   Updated: 2022/11/02 15:39:53 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	ft_printf("\\ n: %d\n", ft_printf("%s", "asdf1234"));
	ft_printf("\\ n: %d\n", ft_printf("%p", "asdf1234"));
	ft_printf("\\ n: %d\n", ft_printf("%i", 324));
	ft_printf("\\ n: %d\n", ft_printf("%X", 10));
	ft_printf("\\ n: %d\n", ft_printf("%d", 999));
	ft_printf("\\ n: %d\n", ft_printf("%X", 0x01abcdef));
	ft_printf("\\ n: %d\n", ft_printf("%X", -1));
	ft_printf("\\ n: %d\n", ft_printf("%u", 1));
	ft_printf("\\ n: %d\n", ft_printf("%%", 10, 10, 10));
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
	ft_printf("\\ n: %d\n", ft_printf("\001a\002b\007c\vd\010e\ff\rg\n"));
	ft_printf("\\ n: %d\n", ft_printf("%s", ""));
	ft_printf("\\ n: %d\n", ft_printf("%s", NULL));
	return (0);
}
