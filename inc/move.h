/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:50:43 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 12:08:06 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

void	slide_right_row(int *grid, int size);
void	slide_left_row(int *grid, int size);
void	slide_up_col(int **grid, int size, int j);
void	slide_down_col(int **grid, int size, int j);

int		fuse_left(int *grid, int size);
int		fuse_right(int *grid, int size);
int		fuse_down(int **grid, int size, int j);
int		fuse_up(int **grid, int size, int j);

#endif