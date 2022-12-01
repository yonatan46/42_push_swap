/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:03:43 by yonamog2          #+#    #+#             */
/*   Updated: 2022/12/02 02:38:27 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_full_str(int fd, char *store)
{
	char	*str;
	int		rd;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	rd = 1;
	while (ft_strchr(store, '\n') == 0 && rd != 0)
	{
		rd = read(fd, str, BUFFER_SIZE);
		if (rd == -1)
		{
			free(str);
			return (NULL);
		}
		str[rd] = '\0';
		store = ft_strjoin(store, str);
	}
	free(str);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*stor;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	stor = ft_full_str(fd, stor);
	if (!stor)
		return (NULL);
	line = ft_get_line(stor);
	stor = ft_get_remain(stor);
	return (line);
}

// int main()
// {
// 	int fd = open("text", O_RDONLY);
// 	printf("%s",get_next_line(fd));
// }
