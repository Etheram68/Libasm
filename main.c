/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/18 17:28:00 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/22 14:49:43 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libasm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

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
	close(fd);
	printf("%20%--done--%%\n\n");

	printf("%20%--strcmp--%%\n");
	printf("ft_strcmp = %d ", ft_strcmp("Salut", "Salut"));
	printf("strcmp = %d\n", strcmp("Salut", "Salut"));
	printf("\n-------------------\n");
	printf("ft_strcmp = %d ", ft_strcmp("", ""));
	printf("strcmp = %d\n", strcmp("", ""));
	printf("\n-------------------\n");
	printf("ft_strcmp = %d ", ft_strcmp("qwertjkl\n", "qwertyuiop\n"));
	printf("strcmp = %d\n", strcmp("qwertjkl\n", "qwertyuiop\n"));
	printf("\n-------------------\n");
	printf("ft_strcmp = %d ", ft_strcmp("qwertyuiop\n", "qwerty\n"));
	printf("strcmp = %d\n", strcmp("qwertyuiop\n", "qwerty\n"));
	printf("\n-------------------\n");
	printf("ft_strcmp = %d ", ft_strcmp("789\n", "987\n"));
	printf("strcmp = %d\n", strcmp("789\n", "987\n"));
	printf("\n-------------------\n");
	printf("ft_strcmp = %d ", ft_strcmp("qwerty\0uiop\n", "qwerty\0uiop\n"));
	printf("strcmp = %d\n", strcmp("qwerty\0uiop\n", "qwerty\0uiop\n"));
	printf("%20%--done--%%\n\n");

	printf("%20%--strcpy--%%\n");
	printf("ft_strcpy = %s  :  Salut", ft_strcpy(buffer, "Salut"));
	printf("\n-------------------\n");
	printf("ft_strcpy = %s  :  \n", ft_strcpy(buffer, ""));
	printf("\n-------------------\n");
	printf("ft_strcpy = %s  :  qwertyuiop\n", ft_strcpy(buffer, "qwertyuiop"));
	printf("\n-------------------\n");
	printf("ft_strcpy = %s  :  qwerty\n", ft_strcpy(buffer, "qwerty"));
	printf("\n-------------------\n");
	printf("ft_strcpy = %s  :  987\n", ft_strcpy(buffer, "987"));
	printf("\n-------------------\n");
	printf("ft_strcpy = %s  :  qwerty\n", ft_strcpy(buffer, "qwerty\0uiop"));
	printf("\n%20%--done--%%\n\n");

	printf("%20%--strdup--%%\n");
	test = ft_strdup("Salut");
	printf("ft_strdup = %s  :  Salut", test);
	free(test);
	printf("\n-------------------\n");
	test = ft_strdup("");
	printf("ft_strdup = %s  :  \n", test);
	free(test);
	printf("\n-------------------\n");
	test = ft_strdup("qwertyuiop");
	printf("ft_strdup = %s  :  qwertyuiop\n", test);
	free(test);
	printf("\n-------------------\n");
	test = ft_strdup("qwerty");
	printf("ft_strdup = %s  :  qwerty\n", test);
	free(test);
	printf("\n-------------------\n");
	test = ft_strdup("987");
	printf("ft_strdup = %s  :  987\n", test);
	free(test);
	printf("\n-------------------\n");
	test = ft_strdup("qwerty\0uiop");
	printf("ft_strdup = %s  :  qwerty\n", test);
	free(test);
	printf("\n-------------------\n");
	test = ft_strdup(NULL);
	printf("ft_strdup = %s  :  (null))\n", test);
	printf("\n%20%--done--%%\n\n");
	return (0);
}
