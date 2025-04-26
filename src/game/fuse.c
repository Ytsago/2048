/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuse.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:56:02 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 12:23:16 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	fuse_left(int *grid, int size)
{
	int	i = 0;
	int	fuse = 0;

	while (i < size - 1)
	{
		if (grid[i] == grid[i + 1] && grid[i] != 0)
		{
			grid[i] += grid[i + 1];
			grid[i + 1] = 0;
			fuse = 1;
		}
		i++;
	}
	return (fuse);
}

int	fuse_right(int *grid, int size)
{
	int	i = size - 1;
	int	fuse = 0;

	while (i)
	{
		if (grid[i] == grid[i - 1] && grid[i] != 0)
		{
			grid[i] += grid[i - 1];
			grid[i - 1] = 0;
			fuse = 1;
		}
		i--;
	}
	return (fuse);
}

int	fuse_up(int **grid, int size, int j)
{
	int	i = 0;
	int	fuse = 0;

	while (i < size - 1)
	{
		if (grid[i][j] == grid[i + 1][j] && grid[i][j] != 0)
		{
			grid[i][j] += grid[i + 1][j];
			grid[i + 1][j] = 0;
			fuse = 1;
		}
		i++;
	}
	return (fuse);
}

int	fuse_down(int **grid, int size, int j)
{
	int	i = size - 1;
	int	fuse = 0;

	while (i)
	{
		if (grid[i][j] == grid[i - 1][j] && grid[i][j] != 0)
		{
			grid[i][j] += grid[i - 1][j];
			grid[i - 1][j] = 0;
			fuse = 1;
		}
		i--;
	}
	return (fuse);
}