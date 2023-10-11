#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "./inc/libft/ft_printf.h"


int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}



int main()
{
	// printf("%d\n", 6&5);
	// char a = 12;
	// write(1, &a, 1);
	// printf("%d\n", 6&5);

	// int *list;

	// list[0] = 13;
	// list[1] = 21;
	// list[2] = 33;
	// list[3] = '\0';

	// int i = 4;
	// // while (list != (void *)'\0')
	// while (i)
	// {
	// 	printf("%i\n", *list++);
	// 	i--;
	// }

	char *aa = " ";

	int a = ft_strncmp(aa, "ab  ", strlen(aa));

	if (ft_strcmp(aa, " "))
		printf("equal\n");
	printf("%i\n", a);

	char **split = ft_split(aa, ' ');
	printf("%s\n", split[0]);
}
