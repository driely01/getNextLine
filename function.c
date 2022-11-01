#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	int	i;

	i = -1;
	while (str[++i]);
	return (i);
}

char *ft_cpy(char *s, char *p)
{
	int i;
	size_t lent;

	i = -1;
	lent = ft_strlen(s);
	p = malloc(sizeof(char) * (lent + 1));
	if (!p)
		return (0);
	while (s[++i])
		p[i] = s[i];
	p[i] = 0;
	return (p);
}

char	*ft_append(char *s1, char *s2)
{
	size_t	i;
	size_t	len1;
	char	*p;

	i = -1;
	p = NULL;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		p = ft_cpy(s2, p);
	else if (!s2)
		p = ft_cpy(s1, p);
	else
	{
		len1 = ft_strlen(s1);
		p = malloc(sizeof(char) * (len1 + ft_strlen(s2) + 1));
		if (!p)
			return (0);
		while (s1[++i])
			p[i] = s1[i];
		i = -1;
		while (s2[++i])
			p[len1++] = s2[i];
		p[len1] = '\0';
	}
	return (p);
}

// char *ft_read(char *ptr, char *buffer, int size, char *leftover)
// {
// 	int i;
// 	int z;
// 	int k;
// 	char *overbuff;

// 	i = 0;
// 	z = -1;
// 	k = 0;
// 	while (buffer[i])
// 		{
// 			if (buffer[i] == '\n')
// 			{
// 				k = i + 1;
// 				leftover = calloc(size - k, sizeof(char));
// 				while (k < size)
// 					leftover[++z] = buffer[k++];
// 				z = -1;
// 				overbuff = calloc(i + 2, sizeof(char));
// 				while (++z <= i)
// 					overbuff[z] = buffer[z];
// 				ptr = ft_append(ptr, overbuff);
// 				return (ptr);
// 			}
// 			i++;
// 		}
// 		i = 0;
// 		ptr = ft_append(ptr, buffer);
// 	return (ptr);
// }

char *ft_get_next_line(int fd)
{
	char *ptr;
	char *overbuff;
	static char *leftover;
	// char *temp;
	// char *temp1;
	int size;
	int i;
	int z;
	int k;

	i = 0;
	z = -1;
	k = 0;
	size = 20;
	ptr = NULL;

	char buffer[size + 1];
	buffer[size] = 0;
	// check if the static variable leftover are empty or not
	ptr = ft_append(ptr, leftover);
	if (buffer[0] != '\0')
	{
		printf("buffer: %s\n\n", buffer);
		free(leftover);
		// leftover = NULL;
		printf("%s|\n", leftover);
		printf("sf saliiina\n");
	}
	while (read(fd, buffer, size) > 0)
	{
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				k = i + 1;
				if (size - k > 0)
				{
					leftover = calloc(size - k, sizeof(char));
					while (k <= size)
						leftover[++z] = buffer[k++];
				}
				z = -1;
				overbuff = calloc(i + 2, sizeof(char));
				while (++z <= i)
					overbuff[z] = buffer[z];
				ptr = ft_append(ptr, overbuff);
				// free(overbuff);
				return (ptr);
			}
			i++;
		}
		ptr = ft_append(ptr, buffer);
	}
	// if (buffer[0] != '\0')
	// {
	// 	printf("%s\n\n", buffer);
	// 	free(leftover);
	// 	// leftover = NULL;
	// 	printf("%s|\n", leftover);
	// 	printf("sf saliiina\n");
	// }
	return (ptr);
}

int main(void)
{
	int fd;

	fd = open("tesst.txt", O_CREAT | O_RDWR, 0777);
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

	// char *str = "Hello gffghjg  ";
	// char *s = "worldkhjfyfufgfhfhjfghvf";
	// char *ptr = ft_append(str, s);
	// printf("%s", ptr);
	return (0);
}