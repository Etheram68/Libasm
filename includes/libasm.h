/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libasm.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 14:48:19 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 17:07:21 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <unistd.h>

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

int					ft_strlen(const char *s);
ssize_t				ft_write(int fd, const void *buf, size_t len);
ssize_t				ft_read(int fd, void *buf, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
int					ft_atoi_base(char *str, char *base);
void				ft_list_push_front(t_list **begin_list, void *data);
int					ft_list_size(t_list *begin_list);

#endif
