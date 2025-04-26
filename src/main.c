
#include "wong_car_wai.h"

int main(int ac, char **av)
{
	int		**grid;
	int		i = 0;
	int		size;
	char	*name;

	if (ac > 3)
		return (1);
	if (av[1])
		name = av[1];
	else
		name = NAME_D;
	if (av[2])
		size = ft_atoi(av[2]);
	else
		size = 4;
	grid = ft_calloc(sizeof(int *), size);
	if (!grid)
		return (1);
	while (i < size)
	{
		grid[i] = ft_calloc(sizeof(int), size);
		i++;
	}
	i = 0;
	while (i < size)
		free(grid[i++]);
	free(grid);
	return (0);
}
