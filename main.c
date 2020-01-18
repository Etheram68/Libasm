/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/18 17:28:00 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/18 17:55:22 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libasm.h"
#include <stdio.h>
#include <string.h>

int		main(void)
{
	printf("--strlen\n");
	printf("_ft_strlen = %d ", ft_strlen("Salut"));
	printf("strlen = %ld\n", strlen("Salut"));
	printf("\n-------------------\n");
	printf("_ft_strlen = %d ", ft_strlen(""));
	printf("strlen = %ld\n", strlen(""));
	printf("\n-------------------\n");
	printf("_ft_strlen = %d ", ft_strlen("ieukthfiSUODLghISOLgdhkjvmsOLdg"));
	printf("strlen = %ld\n", strlen("ieukthfiSUODLghISOLgdhkjvmsOLdg"));
	printf("\n-------------------\n");
	printf("_ft_strlen = %d ", ft_strlen("Salut bro tu vas bien ?"));
	printf("strlen = %ld\n", strlen("Salut bro tu vas bien ?"));
	printf("\n-------------------\n");
	printf("_ft_strlen = %d ", ft_strlen("Salut bro tu \0vas bien ?"));
	printf("strlen = %ld\n", strlen("Salut bro tu \0vas bien ?"));
	printf("--done--\n");
}
