/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slide.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 11:50:43 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 11:51:40 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLIDE_H
# define SLIDE_H

void	slide_right_row(int *grid, int size);
void	slide_left_row(int *grid, int size);
void	slide_up_col(int **grid, int size, int j);
void	slide_down_col(int **grid, int size, int j);


#endif