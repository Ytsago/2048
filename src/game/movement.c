/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:43:49 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 12:20:27 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

void	move_right(int **grid, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		slide_right_row(grid[i], size);
		fuse_right(grid[i], size);
		slide_right_row(grid[i], size);
		i++;
	}
}

void	move_left(int **grid, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		slide_left_row(grid[i], size);
		fuse_left(grid[i], size);
		slide_left_row(grid[i], size);
		i++;
	}
}

void	move_up(int **grid, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		slide_up_col(grid, size, i);
		fuse_up(grid, size, i);
		slide_up_col(grid, size, i);
		i++;
	}

}

void	move_down(int **grid, int size)
{
	int	i;
	
	i = 0;
	while (i < size)
	{
		slide_down_col(grid, size, i);
		fuse_down(grid, size, i);
		slide_down_col(grid, size, i);
		i++;
	}
}
