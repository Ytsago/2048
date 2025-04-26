/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:43:49 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 20:59:37 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

int	move_right(int **grid, int size, size_t *score)
{
	int	moved = 0;
	int	i;

	i = 0;
	while (i < size)
	{
		moved += slide_right_row(grid[i], size);
		moved += fuse_right(grid[i], size, score);
		moved += slide_right_row(grid[i], size);
		i++;
	}
	return (moved);
}

int	move_left(int **grid, int size, size_t *score)
{
	int	moved = 0;
	int	i;
	
	i = 0;
	while (i < size)
	{
		moved += slide_left_row(grid[i], size);
		moved += fuse_left(grid[i], size, score);
		moved += slide_left_row(grid[i], size);
		i++;
	}
	return (moved);
}

int	move_up(int **grid, int size, size_t *score)
{
	int	moved = 0;
	int	i;
	
	i = 0;
	while (i < size)
	{
		moved += slide_up_col(grid, size, i);
		moved += fuse_up(grid, size, i, score);
		moved += slide_up_col(grid, size, i);
		i++;
	}
	return (moved);
}

int	move_down(int **grid, int size, size_t *score)
{
	int	moved = 0;
	int	i;
	
	i = 0;
	while (i < size)
	{
		moved += slide_down_col(grid, size, i);
		moved += fuse_down(grid, size, i, score);
		moved += slide_down_col(grid, size, i);
		i++;
	}
	return (moved);
}
