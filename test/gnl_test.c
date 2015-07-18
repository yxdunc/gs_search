#include <stdio.h>
#include <stdlib.h>

int	get_next_line(int const fd, char **line);

int	main(int argc, char **argv)
{
	char	*line;
	while (1)
	{
		get_next_line(0, &line);
		printf("%s\n",line);
		free(line);
	}
	return(0);
}
