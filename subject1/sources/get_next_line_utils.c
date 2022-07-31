#include <stdlib.h>
#include <stddef.h>

size_t	ft_strlen(const char *str)
{
	char	*runingman;
	size_t	len;

	len = 0;
	runingman = (char *) str;
	while (*runingman != '\0')
	{
		len++;
		runingman++;
	}
	return (len);
}

static char	*copys1(char *runman, char *runjoin)
{
	while (*runman != '\0')
	{
		*runjoin = *runman;
		runjoin++;
		runman++;
	}
	return (runjoin);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*runman;
	char	*runjoin;

	if (s1 == 0 || s2 == 0)
		return (0);
	runman = (char *) s1;
	join = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * 1);
	if (join == 0)
		return (0);
	runjoin = join;
	runjoin = copys1(runman, runjoin);
	runman = (char *) s2;
	while (*runman != '\0')
	{
		*runjoin = *runman;
		runjoin++;
		runman++;
	}
	*runjoin = '\0';
	return (join);
}
