#include "push_swap.h"
static int	count_occ(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}
int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
size_t	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}
char	*ft_strdup(char *s1)
{
	int		x;
	int		size;
	char	*dup;

	size = ft_strlen(s1) + 1;
	x = -1;
	dup = malloc(sizeof(char) * size);
	if (!dup)
		return (NULL);
	while (s1[++x] != '\0')
		dup[x] = s1[x];
	dup[x] = '\0';
	return (dup);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = (ft_strlen(s) - start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
static	int	do_pls(const char *s_1, char c_1, char **str_1, int set1)
{
	int	y1;
	int	x1;

	x1 = 0;
	y1 = 0;
	while (s_1[x1] != '\0')
	{
		if (s_1[x1] == c_1 && ft_isprint(s_1[x1]))
		{
			while (s_1[x1] == c_1)
				x1++;
			set1 = x1;
		}
		else if (s_1[x1] != c_1 && ft_isprint(s_1[x1]))
		{
			while (s_1[x1] != c_1 && s_1[x1] != '\0')
				x1++;
			str_1[y1] = ft_substr (s_1, set1, x1 - set1);
			set1 = x1 + 1;
			if (s_1[x1] != '\0')
				x1++;
			y1++;
		}
	}
	return (y1);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	int		y;
	int		set;

	if (!s)
		return (NULL);
	y = 0;
	set = 0;
	str = (char **)malloc (sizeof (char *) * ((count_occ(s, c) + 1)));
	if (!str)
		return (NULL);
	y = do_pls(s, c, str, set);
	str[y] = NULL;
	return (str);
}