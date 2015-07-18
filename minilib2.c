/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguignar <rguignar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/14 01:20:05 by rguignar          #+#    #+#             */
/*   Updated: 2013/12/15 23:01:41 by rguignar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"hotrace.h"

char		*ft_strsub(char const *s, unsigned int i, size_t len)
{
	size_t	j;
	char	*str;

	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(char) * len + 1);
	if (str)
	{
		j = 0;
		while (j < len)
		{
			str[j] = (s + i)[j];
			j++;
		}
		str[j] = '\0';
		return (str);
	}
	return (NULL);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str)
	{
		i = 0;
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j] != '\0')
		{
			str[i] = s2[j];
			i++;
			j++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] < s2[i])
		{
			return (-1);
		}
		else if (s1[i] > s2[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}
void		ft_putendl(char *str)
{
		ft_putstr(str);
		ft_putchar('\n');
}
