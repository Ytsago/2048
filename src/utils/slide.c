/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:50:23 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 11:50:30 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	slide_right_row(int *grid, int size)
{
	int		i;
	int		move = 1;

	i = 0;
	while (i < size - 1 || move)
	{
		if (i == size - 1)
		{
			if (move == 0)
				break ;
			i = 0;
			move = 0;
		}
		if (grid[i] && grid[i + 1] == 0)
		{
			grid[i + 1] = grid[i];
			grid[i] = 0;
			move = 1;
		}
		i++;
	}
}

void	slide_left_row(int *grid, int size)
{
	int		i;
	int		move = 1;

	i = size - 1;
	while (i || move)
	{
		if (i == 0)
		{
			if (move == 0)
				break ;
			i = size - 1;
			move = 0;
		}
		if (grid[i] && grid[i - 1] == 0)
		{
			grid[i - 1] = grid[i];
			grid[i] = 0;
			move = 1;
		}
		i--;
	}
}

void	slide_up_col(int **grid, int size, int j)
{
	int		i;
	int		move = 1;

	i = size - 1;
	while (i || move)
	{
		if (i == 0)
		{
			if (move == 0)
				break ;
			i = size - 1;
			move = 0;
		}
		if (grid[i][j] && grid[i - 1][j] == 0)
		{
			grid[i - 1][j] = grid[i][j];
			grid[i][j] = 0;
			move = 1;
		}
		i--;
	}
}

void	slide_down_col(int **grid, int size, int j)
{
	int		i;
	int		move = 1;

	i = 0;
	while (i < size - 1 || move)
	{
		if (i == size - 1)
		{
			if (move == 0)
				break ;
			i = 0;
			move = 0;
		}
		if (grid[i][j] && grid[i + 1][j] == 0)
		{
			grid[i + 1][j] = grid[i][j];
			grid[i][j] = 0;
			move = 1;
		}
		i++;
	}
}
