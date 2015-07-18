/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguignar <rguignar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 23:42:16 by rguignar          #+#    #+#             */
/*   Updated: 2013/12/15 23:00:52 by rguignar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"hotrace.h"

void	ft_putchar(char c)
{
	if(write (1, &c, 1)){};
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));	
}

void		ft_strclr(char *s)
{
	int		i;

	i = (int)ft_strlen(s) - 1;
	while (i >= 0)
	{
		s[i] = '\0';
		i--;
	}
}

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (str)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
