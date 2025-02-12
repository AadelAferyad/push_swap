#include <stdio.h>
#include <stdlib.h>

int	deja_vue(int n, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (n == arr[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;
	int	j;
	int	s;
	int	sign;
	int	random;
	int	p;
	int	arr[600];

	i = 0;
	sign = 1;
	if (ac < 2)
		return (0);
	if (*av[2] == 'N')
		sign = -1;
	s = atoi(av[1]);
	j = 0;
	p = 10;
	while (i < s)
	{
		random = rand() % p;
		if (p != 1000000)
			p *= 10;
		else
			p = 10;
		if (deja_vue(random, arr, j))
		{
			printf("%d ", random * sign);
			arr[j] = random;
			j++;
		}
		else
			i--;
		i++;
	}
	return (0);
}

