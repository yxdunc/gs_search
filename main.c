/* *********************** */
/*                         */
/*  Robin Guignard-Perret  */
/*                   @42   */
/* *********************** */

#include "hotrace.h"

void		sort(char *line, char *value, node *db);
char		*search(char *line, node *db);
node		*new_node(node **tree);
node		*init_node(node *new);

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		n = -n;
		ft_putchar ('-');
	}
	if (n >= 10)
	{
		ft_putnbr (n / 10);
	}
		ft_putchar (n % 10 + '0');
}

int		main(void)
{
	char	*line;
	char	*value;
	node	*db;

	db = (node*)malloc(sizeof(node));
	db = init_node(db);
	while (get_next_line(0, &line) && *line != '\0')
	{
		get_next_line(0, &value);
		ft_putendl("--1--");
		ft_putendl(line);
		ft_putendl("--2--");
		ft_putendl(value);
		sort(line, value, db);
		free(line);
		free(value);
	}
	while (get_next_line(0, &line))
	{
		ft_putstr(line);
		ft_putstr(": ");
 		ft_putendl(search(line, db));
		free(line);
	}
	return (0);
}
int		char_to_ui(char c)
{
	return(((int)c < 0) ? (-((int)c) + 127) : (int)c);
}
void		sort(char *line, char *value, node *db)
{
	int	i;

	i = 0;
	while (line[i])
	{
/*		ft_putstr("||");
		ft_putnbr(char_to_ui(line[i]));
		ft_putstr(": ");
		ft_putchar(line[i]);
		ft_putendl("||");
*/		if (!db->next[char_to_ui(line[i])])
		{
			db = new_node(&db->next[char_to_ui(line[i])]);
		}
		else
			db = db->next[char_to_ui(line[i])]; 
		i++;
	}
	db->value = malloc(sizeof(char) * (ft_strlen(value) + 1));
	if(!db->value)
	{
		ft_putendl("ERROR: Malloc failled");
		exit(-1);
	}
	strcpy(db->value, value);
}
char		*search(char *line, node *db)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (db->next[char_to_ui(line[i])] == NULL)//
			return ("not found.");
		db = db->next[char_to_ui(line[i])]; //
		i++;
	}
	return ((db->value) ? db->value : "not found.");
}
node		*new_node(node **tree)
{
	node	*new;
	new = (node*)malloc(sizeof(node));
	if(!new)
	{
		ft_putendl("ERROR: Malloc failled");
		exit(-1);
	}
	*tree = new;
	new = init_node(new);
	return (new);
}
node		*init_node(node *new)
{	
	int	i;

	i = 0;
	new->value = NULL;
	while(i < ALPH_SIZE)
	{
		new->next[i] = NULL;
		i++;
	}
	return(new);
}
