/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_bonus.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 14:49:18 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 15:48:52 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/libasm.h"

int			main(void)
{
	printf("%20%--ft_atoi_base--%%\n");
	printf("ft_atoi_base = %d  :  125", ft_atoi_base(" \n\t\r7d", "0123456789abcdef"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d  :  125\n", ft_atoi_base(" \n\t\r17", "abcdef0123456789"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d  :  135\n", ft_atoi_base("  \n\t\r   -135", "0123456789"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d  :  255 \n", ft_atoi_base(" \n\t\r\v\f \\\\\\\\\\\\\\\\", "0\\"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d  :  255 \n", ft_atoi_base(" \n\t\r\v\f 11111111", "01"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d  :  (0)Err\n", ft_atoi_base("145", "5"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d  :  (0)Err\n", ft_atoi_base("145", "0123450789"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d  :  (0)Err\n", ft_atoi_base("145", "1234567+89"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d  :  (0)Err\n", ft_atoi_base("145", "0123-450789"));
	printf("\n%20%--done--%%\n\n");
	return (0);
}
