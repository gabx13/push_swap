#include <stdio.h>
#include <unistd.h>

int main()
{
	// printf("%d\n", 6&5);
	// char a = 12;
	// write(1, &a, 1);
	// printf("%d\n", 6&5);

	int *list;

	list[0] = 13;
	list[1] = 21;
	list[2] = 33;
	list[3] = '\0';

	int i = 4;
	// while (list != (void *)'\0')
	while (i)
	{
		printf("%i\n", *list++);
		i--;
	}
}
