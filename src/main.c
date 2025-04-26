#include <ncurses.h>
#include "libft.h"
#include "wong_car_wai.h"

int main(int ac, char **av)
{
	int		**grid;
	int		i = 0;
	int		size;
	char	*name;

	if (ac == 1 || ac > 2)
		return (1);
	size = ft_atoi(av[1]);
	grid = ft_calloc(sizeof(int *), size);
	if (!grid)
		return (1);
	while (i < size)
	{
		grid[i] = ft_calloc(sizeof(int), size);
		if (!grid[i])
		i++;
	}
	i = 0;
	while (i < size)
		free(grid[i++]);
	free(grid);
	return (0);
}
