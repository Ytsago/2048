/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:50:43 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 14:04:19 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

int	slide_right_row(int *grid, int size);
int	slide_left_row(int *grid, int size);
int	slide_up_col(int **grid, int size, int j);
int	slide_down_col(int **grid, int size, int j);

int	fuse_left(int *grid, int size);
int	fuse_right(int *grid, int size);
int	fuse_down(int **grid, int size, int j);
int	fuse_up(int **grid, int size, int j);

#endif