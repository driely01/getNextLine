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
		while (s1[i])
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

// char *ft_check_leftover(char *leftover, char *ptr)
// {
// 	// if (leftover != 0)
// 	// 	printf("true");
// 	// else
// 	// 	printf("ghir katrawan");
// 	if (leftover != 0)
// 	{
// 		ptr = ft_append(ptr, leftover);
// 	}
// 	return (ptr);
// }

char *ft_get_next_line(int fd)
{
	char *ptr;
	char *overbuff;
	static char *leftover;
	char *temp;
	char *temp1;
	int size;
	int i;
	int j;
	int z;
	int k;

	i = 0;
	j = 0;
	z = -1;
	k = 0;
	size = 1000;
	ptr = NULL;

	char *buffer;
	buffer = calloc(size + 1, sizeof(char));
	// check if the static variable leftover are empty or not
	if (leftover != 0)
	{
		// if it's full chack if there is a new line ito it
		while (leftover[i])
		{
			// if there is a new line we need to fill another variable with the first line before a new line and return it
			if (leftover[i] == '\n')
			{
				temp = calloc(i + 1, sizeof(char));
				while (++z <= i)
					temp[z] = leftover[z];
				k = i;
				// temp[z] = 10;
				temp1= calloc(ft_strlen(leftover) - z + 1, sizeof(char));
				z = 0;
				while ((size_t)++k <= ft_strlen(leftover))
				{
					temp1[z] = leftover[k];
					z++;
				}
				// temp1[z] = 10;
				leftover = temp1;
				ptr = ft_append(ptr, temp);
				// free(temp1);
				// free(temp);
				return (ptr);
			}
			i++;
		}
		ptr = ft_append(ptr, leftover);
	}
	else
		ptr = ft_append(ptr, leftover);
	// read the lines and save the leftover into a static variable called leftover
	while (read(fd, buffer, size) > 0)
	{
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				k = i;
				leftover = calloc(size - k, sizeof(char));
				while (k <= size)
					leftover[z++] = buffer[k++];
				z = -1;
				overbuff = calloc(i + 2, sizeof(char));
				while (++z <= i)
					overbuff[z] = buffer[z];
				ptr = ft_append(ptr, overbuff);
				free(overbuff);
				return (ptr);
			}
			i++;
		}
		ptr = ft_append(ptr, buffer);
	}
	// printf("%s\n", leftover);
	// printf("%s\n", buffer);
	return (ptr);
}

int main(void)
{
	int fd;

	fd = open("hello.txt", O_CREAT | O_RDWR, 0777);
	if (fd != -1)
	{
		printf("%s", ft_get_next_line(fd));
		printf("%s", ft_get_next_line(fd));
		printf("%s", ft_get_next_line(fd));
		printf("%s", ft_get_next_line(fd));
		printf("%s", ft_get_next_line(fd));
		printf("%s", ft_get_next_line(fd));
		printf("%s", ft_get_next_line(fd));
		printf("%s", ft_get_next_line(fd));
		printf("%s", ft_get_next_line(fd));
		printf("%s", ft_get_next_line(fd));
		printf("%s", ft_get_next_line(fd));
		printf("%s", ft_get_next_line(fd));
	}
	return (0);
}