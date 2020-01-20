/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/18 17:28:00 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 15:46:09 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int		main(void)
{
	long	r;
	char	buffer[100];
	int		i;
	int		fd;
	char	*test;

	r = 0;
	i = 0;
	fd = open("Makefile", O_RDONLY);
	while (i < 100)
		buffer[i++] = 0;
	printf("%20%--strlen--%%\n");
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
	printf("%20%--done--%%\n\n");

	printf("%20%--write--%%\n");
	printf("_ft_write = %zd ", ft_write(42, "Salut\n", 6));
	printf("write = %ld\n", write(42, "Salut\n", 6));
	printf("\n-------------------\n");
	printf("_ft_write = %zd ", ft_write(1, "", 1));
	printf("write = %ld\n", write(1, "\n", 1));
	printf("\n-------------------\n");
	printf("_ft_write = %zd ", ft_write(1, "ieukthfiSUODLghISOLgdhkjvmsOLdg\n", 33));
	printf("write = %ld\n", write(1, "ieukthfiSUODLghISOLgdhkjvmsOLdg\n", 33));
	printf("\n-------------------\n");
	printf("_ft_write = %zd ", ft_write(1, "Salut bro tu vas bien ?\n", 25));
	printf("write = %ld\n", write(1, "Salut bro tu vas bien ?\n", 25));
	printf("\n-------------------\n");
	printf("_ft_write = %zd ", ft_write(1, "Salut bro tu \0vas bien ?\n", 26));
	printf("write = %ld\n", write(1, "Salut bro tu \0vas bien ?\n", 26));
	printf("%20%--done--%%\n\n");

	printf("%20%--read--%%\n");
	r = ft_read(fd, buffer, 80);
	buffer[r] = 0;
	printf("'%s':%ld\n", buffer, r);
	r = ft_read(fd, buffer, 25);
	buffer[r] = 0;
	printf("'%s':%ld\n", buffer, r);
	r = ft_read(fd, buffer, 4);
	buffer[r] = 0;
	printf("'%s':%ld\n", buffer, r);
	r = ft_read(fd, buffer, 0);
	buffer[r] = 0;
	printf("'%s':%ld\n", buffer, r);
	printf("%20%--done--%%\n\n");
	close(fd);
	return (0);
}
