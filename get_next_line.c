#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "hotrace.h"

char					*str_char(char *str, char c)
{
	char	*cpy;
	int	y;

	cpy = malloc(sizeof(char) * (strlen(str) + 1));
	y = 0;
	while(str[y] != '\0')
	{
		cpy[y] = str[y];
		y++;
	}
	cpy[y] = str[y];
	free(str);
	str = malloc(sizeof(char) * (strlen(cpy) + 2));
	y = 0;
	while(cpy[y] != '\0')
	{
		str[y] = cpy[y];
		y++;
	}
	str[y] = c;
	str[y + 1] = '\0';
	free(cpy);
	return (str);
}

int					get_next_line(int const fd, char **line)
{
	unsigned char	buf;
	int	i;
	int	ret;

	i = 0;
	*line = malloc(sizeof (char) * (i + 1));
	*line[0] = '\0';
	while ((ret = read(fd, &buf, 1)))
	{
		if ((char)buf == '\n')
			break ;
		*line = str_char(*line, (buf > 127) ? (char)(-(buf-127)) : (char)buf);
		i++;
	}
	return (ret);
}
