#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
// #include "./inc/libft/ft_printf.h"
#include <limits.h>


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

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}



// int main()
// {
// 	// printf("%d\n", 6&5);
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

#include <unistd.h>

#include <unistd.h>

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 2)
	{
		while(argv[1][i])
		{
			if(argv[1][i] >= 65 && argv[1][i] <= 90)
			{
				argv[1][i] = 90 - argv[1][i] + 65;
			}
			else if (argv[1][i] >= 97 && argv[1][i] <= 122)
			{
				argv[1][i] = 122-argv[1][i] + 97;
			}
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write (1,"\n",1);
}		
