/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:29:04 by del-yaag          #+#    #+#             */
/*   Updated: 2022/11/02 21:29:07 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	int r;
	size_t i;
	size_t j;
	int size;
	char *buffer;
	char *line;
	// char *temp;
	static char *leftover;

	r = 1;
	i = 0;
	j = 0;
	size = 0;
	buffer = NULL;
	line = NULL;
	// temp = NULL;
	if (fd < 0)
		return (0);
	if (leftover)
	{
		while (leftover[i])
		{
			if (leftover[i] == '\n')
				return (ft_read(&leftover, line, i));
			i++;
		}
	}

	while (r > 0)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		r = read(fd, buffer, BUFFER_SIZE);
		leftover = ft_append(leftover, buffer);
		while (leftover[i])
		{
			if (leftover[i] == '\n')
				return (ft_read(&leftover, line, i));
			i++;
		}
		free(buffer);
		if (r == 0 && ft_strlen(leftover) != 0)
		{
			char *tmp = leftover;
			free(leftover);
			leftover = 0;
			return (tmp);
		}
	}

	return (0);
}

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	line = 0;
// 	fd = open("tesst.txt", O_CREAT | O_RDWR, 0777);
// 	// while (1)
// 	// {
// 	// 	line = get_next_line(fd);
// 	// 	if (!line)
// 	// 		break;
// 	// 	printf("%s", line);
// 	// }
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(0));
// 	// printf("%s", get_next_line(0));
// 	// printf("%s", get_next_line(0));
// 	return (0);
// }
