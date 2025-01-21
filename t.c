#include <stdio.h>
#include <stdlib.h>


int	main(int ac, char **av)
{
	int	s = 0;
	for (int i = 1; i < ac; i++)
		s += atoi(av[i]);
	for (int i = 1; i < ac; i++)
		printf("%d ", atoi(av[i]));
	printf("\n%d -> (%d)\n", s, s / 2);
	return (0);
}


