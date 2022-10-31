#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "libft.h"

char	*ft_append(char *s1, char *s2)
{
	size_t	i;
	size_t	len1;
	char	*p;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1)
	{
		len1 = ft_strlen(s2);
		p = malloc(sizeof(char) * (len1 + 1));
		if (!p)
			return (0);
		while (s2[i])
		{
			p[i] = s2[i];
			i++;
		}
		p[i] = 0;
	}
	else if (!s2)
	{
		len1 = ft_strlen(s1);
		p = malloc(sizeof(char) * (len1 + 1));
		if (!p)
			return (0);
		while (s2[i])
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = 0;
	}
	else
	{
		len1 = ft_strlen(s1);
		p = malloc(sizeof(char) * (len1 + ft_strlen(s2) + 1));
		if (!p)
			return (0);
		while (s1[i] != '\0')
		{
			p[i] = s1[i];
			i++;
		}
		i = 0;
		while (s2[i] != '\0')
		{
			p[len1] = s2[i];
			i++;
			len1++;
		}
		p[len1] = '\0';
	}
	return (p);
}

char *ft_get_next_line(int fd)
{
	char *ptr;
	static char *leftover;
	int size;
	int i;
	int j;
	int z;

	i = 0;
	j = 0;
	z = 0;
	size = 5;
	ptr = NULL;

	char buffer[size + 1];
	buffer[size] = 0;

	while (read(fd, buffer, size) != 0)
	{
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				i++;
				leftover = malloc(sizeof(char) * size - i);
				while (i < size)
					leftover[z++] = buffer[i++];
				leftover[z] = '\0';
				printf("%s", leftover);
				ptr = ft_append(ptr, buffer);
				return (ptr);
			}
			i++;
		}
		ptr = ft_append(ptr, buffer);
	}

	return (ptr);
}

int main(void)
{
	int fd;

	fd = open("hello.txt", O_CREAT | O_RDWR, 0777);
	if (fd != -1)
	{
		printf("%s", ft_get_next_line(fd));
	}
	return (0);
}