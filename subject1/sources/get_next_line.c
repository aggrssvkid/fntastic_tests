#include "../headers/convert.h"

static char	*end_string(t_var *var, int fd)
{
	while (var->n != 0 && *(var->runman - 1) != '\n')
	{
		var->n = read(fd, var->runman, 1);
		if (var->n == -1)
		{
			free(var->tmp);
			return (0);
		}
		var->runman++;
		if (*var->runman == '\0' && *(var->runman - 1) != '\n' && var->n != 0)
		{
			var->runman = var->buffer;
			var->fre = var->tmp;
			var->tmp = ft_strjoin(var->tmp, var->buffer);
			free(var->fre);
			if (var->tmp == 0)
				return (0);
		}
	}
	if (var->n == 0)
		*(var->runman - 1) = '\0';
	else
		*var->runman = '\0';
	return (var->tmp);
}

static char	*emptystr(void)
{
	char	*ptr;

	ptr = malloc(1 * sizeof(char));
	if (ptr == 0)
		return (0);
	*ptr = '\0';
	return (ptr);
}

static void	full(char *str)
{
	char	*tmp;
	int		n;

	tmp = str;
	n = BUFFER_SIZE;
	while (n > 0)
	{
		*tmp = 'A';
		tmp++;
		n--;
	}
}

static t_var	*init(t_var *var)
{
	var->n = 1;
	var->buffer[BUFFER_SIZE] = '\0';
	full(var->buffer);
	var->tmp = emptystr();
	return (var);
}

char	*get_next_line(int fd)
{
	t_var	*var;
	t_var	kek;

	var = &kek;
	var->runman = var->buffer;
	var = init(var);
	if (var->tmp == 0)
		return (0);
	var->tmp = end_string(var, fd);
	if (var->tmp == 0)
		return (0);
	var->getline = ft_strjoin(var->tmp, var->buffer);
	if (var->getline == 0 || *var->getline == '\0')
	{
		free(var->getline);
        free(var->tmp);
		return (0);
	}
	free(var -> tmp);
	return (var->getline);
}
