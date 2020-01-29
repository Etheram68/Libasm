/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_bonus.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/22 14:49:18 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/29 11:29:12 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libasm.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void		printf_list(t_list *list)
{
	while (list)
	{
		printf("; %s\n", list->data);
		list = list->next;
	}
}

void		ft_lstclear(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->data)
			free((*list)->data);
		free(*list);
		*list = tmp;
	}
}

int			main(void)
{
	t_list	list;
	t_list	list_next;
	t_list	list_last;

	list.data = strdup("toto");
	list.next = &list_next;
	list_next.data = strdup("bar");
	list_next.next = &list_last;
	list_last.data = strdup("monkaS");
	list_last.next = NULL;

	printf("\n--ft_list_size\n\n");
	printf("list content:\n");
	printf_list(&list);
	printf("\n%d : 3\n", ft_list_size(&list));
	printf("%d : 2\n", ft_list_size(&list_next));
	printf("%d : 0 (NULL)\n", ft_list_size(NULL));
	printf("%d : 1\n", ft_list_size(&list_last));
	printf("-done\n");
	free(list_next.data);
	free(list_last.data);
	printf("\n-------------------\n");

	printf("%20%--ft_list_push_front--%%\n\n");
	t_list	*push_test = &list;
	ft_list_push_front(&push_test, strdup("toto"));
	printf("added: `%s` (next: %p)\n", push_test->data, push_test->next);
	printf("new list size: %d (%d)\n", ft_list_size(push_test), 4);
	free(list.data);
	free(push_test->data);
	free(push_test);
	printf("\n-------------------\n");
	push_test = NULL;
	ft_list_push_front(&push_test, strdup("barbar"));
	printf("added: `%s` (s %p : n %p)\n", \
			push_test->data, push_test, push_test->next);
	ft_list_push_front(&push_test, NULL);
	printf("added: `%s` (s %p : n %p)\n", \
			push_test->data, push_test, push_test->next);
	free(push_test->next);
	push_test->next = NULL;
	ft_list_push_front(&push_test, strdup("toto_r"));
	printf("added: `%s` (s %p : n %p)\n", \
			push_test->data, push_test, push_test->next);
	ft_lstclear(&push_test);
	printf("\n-------------------\n");
	printf("\n%20%--done--%%\n\n");

	printf("%20%--ft_atoi_base--%%\n");
	printf("ft_atoi_base = %d  :  125\n", \
			ft_atoi_base("7d", "0123456789abcdef"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d  :  -135\n", \
			ft_atoi_base("  \n\t\r   -135", "0123456789"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d  :  255 \n", \
			ft_atoi_base(" \n\t\r\v\f \\\\\\\\\\\\\\\\", "0\\"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d  :  255 \n", \
			ft_atoi_base(" \n\t\r\v\f 11111111", "01"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d  :  (0)Err\n", \
			ft_atoi_base("145", "5"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d  :  (0)Err\n", \
			ft_atoi_base("145", "0123450789"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d  :  (0)Err\n", \
			ft_atoi_base("145", "1234567+89"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d  :  (0)Err\n", \
			ft_atoi_base("145", "0123-450789"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d : (0)Err\n", \
			ft_atoi_base(NULL, "0123456789"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d : (0)Err\n", \
			ft_atoi_base(" -+--2147448", NULL));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d : -2147448\n", \
			ft_atoi_base(" -+--2147448", "0123456789"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d : -26\n", \
			ft_atoi_base("    ++---222", "012"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d : -63\n", \
			ft_atoi_base(" -333f", "0123"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d : 4\n", \
			ft_atoi_base("04f4", "01234"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d : -35\n", \
			ft_atoi_base("-55+5", "012345"));
	printf("\n-------------------\n");
	printf("ft_atoi_base = %d : 2381\n", \
			ft_atoi_base("6641-6", "0123456"));
	printf("\n-------------------\n");
	printf("\n%20%--done--%%\n\n");
	return (0);
}
