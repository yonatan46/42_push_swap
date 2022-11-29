/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:59:34 by yonamog2          #+#    #+#             */
/*   Updated: 2022/11/29 18:42:37 by yonamog2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int main()
{
	int fd = open("commands", O_RDWR | O_TRUNC);
	char s;
	while (read(0, &s, 1))
		write(fd, &s, 1);
	write(1, "Done\n", 5);
	char *str;
	int fd1 = open("commands", O_RDONLY);
	// printf("%s",get_next_line(fd1));
	str = get_next_line(fd1);
	while (str)
	{
		printf("%s", str);
		str = get_next_line(fd);
	}
}
