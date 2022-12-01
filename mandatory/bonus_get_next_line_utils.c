/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_next_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:03:36 by yonamog2          #+#    #+#             */
/*   Updated: 2022/12/02 02:37:09 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(char *s, int c)
{
	int	x;

	x = -1;
	if (!s)
		return (0);
	if (c == '\0')
		return (&s[ft_strlen(s)]);
	while (s[++x] != '\0')
		if (s[x] == (char) c)
			return (&s[x]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		x;
	int		y;
	char	*ret;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	ret = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!ret)
		return (NULL);
	x = 0;
	y = -1;
	if (s1)
		while (s1[++y] != '\0')
			ret[y] = s1[y];
	while (s2[x] != '\0')
		ret[y++] = s2[x++];
	ret[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (ret);
}

char	*ft_get_line(char *all)
{
	int		i;
	char	*line;

	i = 0;
	if (!all[i])
		return (NULL);
	while (all[i] && all[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (all[i] && all[i] != '\n')
	{
		line[i] = all[i];
		i++;
	}
	if (all[i] == '\n')
	{
		line[i] = all[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_get_remain(char *left)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left[i] && left[i] != '\n')
		i++;
	if (!left[i])
	{
		free(left);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(left) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left[i])
		str[j++] = left[i++];
	str[j] = '\0';
	free(left);
	return (str);
}
