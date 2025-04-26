/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:11:21 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 12:30:37 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_car_wai.h"
#include <time.h>
#include "ft_printf.h"
#include "get_next_line.h"

int	**create_grid(int size)
{
	int	**grid;
	int	i = 0;

	grid = ft_calloc(sizeof(int *), size + 1);
	if (!grid)
		return (NULL);
	while (i < size)
	{
		grid[i] = ft_calloc(sizeof(int), size);
		if (!grid[i])
		{
			free_the_mallocs((void *)grid);
			return (NULL);
		}
		i++;
	}
	return (grid);
}

void	display(int **grid, int size)
{
	int	j;
	int	i = 0;

	while (grid[i])
	{
		j = 0;
		while (j < size)
			ft_printf("[%d]", grid[i][j++]);
		ft_printf("\n");
		i++;
	}
}

int main(int ac, char **av)
{
	int		**grid;
	int		size;
	char	*move;
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
	grid = create_grid(size);
	srand(time(NULL));
	init_grid(grid, size);
	while ((move = get_next_line(0)))
	{
		if (move[0] == 'd')
			move_right(grid, size);
		else if (move[0] == 'a')
			move_left(grid, size);
		else if (move[0] == 's')
			move_down(grid, size);
		else if (move[0] == 'w')
			move_up(grid, size);
		generat_number(grid, size);
		display(grid, size);
		free(move);
	}
	free_the_mallocs((void *)grid);
	display(grid, size);
	return (0);
}
