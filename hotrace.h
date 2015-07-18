/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguignar <rguignar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 23:42:29 by rguignar          #+#    #+#             */
/*   Updated: 2013/12/15 22:51:31 by rguignar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HOTRACE_H__
# define __HOTRACE_H__

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# define BUF_SIZE 8
# define ALPH_SIZE 256

typedef struct		s_elmt
{
	char			*key_w;
	char			*value;
	struct s_elmt 		*next;
}			t_elmt;
typedef struct		s_node
{
	char			*value;
	struct s_node		*next[ALPH_SIZE];
}			node;

int	get_next_line(int const fd, char **line);
int	get_buf(int const fd, char **buffer, int *last_l, int ret);
char	*join_buf(char *tmp, char *buf, char **big_buf);
int	end_of_line(char *buf, int i, int end, int *last_l);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putendl(char *str);
void	ft_strclr(char *s);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strsub(char const *s, unsigned int i, size_t len);
int	ft_strcmp(const char *s1, const char *s2);
t_elmt	*l_new(t_elmt *list);
int	research(t_elmt *list, t_elmt *list1, int ret, char *buf, int ret1);
void	rankle(int ret, t_elmt *list);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
