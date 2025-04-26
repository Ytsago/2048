/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:44:56 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 11:55:55 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wong_car_wai.h"

int	is_full(int **grid, int size)
{
	int	i, j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (grid[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	generat_number(int **grid, int size)
{
	int		i, j;
	bool	new = TRUE;

	i = 0;
	if (is_full(grid, size))
		return (1);
	while (new)
	{
		i = i % size;
		j = 0;
		while (new && j < size)
		{
			if (grid[i][j] == 0 && rand() % 10 == 0)
			{
				if (rand() % 4 == 0)
					grid[i][j] = 4;
				else
					grid[i][j] = 2;
				new = FALSE;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	init_grid(int **grid, int size)
{
	int	i = 0;
	int	start = 0;

	while (start != 2)
	{
		if (i == size)
			i = 0;
		int j = 0;
		while (j < size && start != 2)
		{
			if (rand() % 10 == 0)
			{
				if (rand() % 4 == 0)
					grid[i][j] = 4;
				else
					grid[i][j] = 2;
				start++;
			}
			j++;
		}
		i++;
	}
}
