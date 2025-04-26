/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:50:23 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 13:59:07 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	slide_right_row(int *grid, int size)
{
	int		i;
	int		moved = 0;
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
			moved = 1;
			move = 1;
		}
		i++;
	}
	return (moved);
}

int	slide_left_row(int *grid, int size)
{
	int		i;
	int		moved = 0;
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
			moved = 1;
			move = 1;
		}
		i--;
	}
	return (moved);
}

int	slide_up_col(int **grid, int size, int j)
{
	int		i;
	int		moved = 0;
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
			moved = 1;
			move = 1;
		}
		i--;
	}
	return (moved);
}

int	slide_down_col(int **grid, int size, int j)
{
	int		i;
	int		moved = 0;
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
			moved = 1;
			move = 1;
		}
		i++;
	}
	return (moved);
}
