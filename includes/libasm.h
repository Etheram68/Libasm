/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libasm.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: frfrey <frfrey@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 14:48:19 by frfrey       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/20 14:27:15 by frfrey      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <unistd.h>

int			ft_strlen(const char *s);
ssize_t		ft_write(int fd, const void *buf, size_t len);
ssize_t		ft_read(int fd, void *buf, size_t len);

#endif
