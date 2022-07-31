#ifndef CONVERT_H
# define CONVERT_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

typedef struct s_var
{
	char	buffer[BUFFER_SIZE + 1];
	char	*runman;
	char	*tmp;
	char	*fre;
	char	*getline;
	int		n;

}	t_var;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
void    convert_str(char *convert_str, char *source_str);
size_t	ft_strlen(const char *str);
int		is_duplicate(char checker, char source);
int 	check_valid_str(char *str);

#endif
