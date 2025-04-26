/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong_car_wai.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:13:16 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 12:00:18 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_CAR_WAI_H
# define WONG_CAR_WAI_H

# include <ncurses.h>
# include "libft.h"

# define NAME_D "Unknow"

typedef struct	s_player	t_player;

enum e_const
{
	WIN_VALUE = 2048
};

struct t_player
{
	char	*name;
	size_t	score;
	int		**grid;
	int		size;
};

void	init_grid(int **grid, int size);
int		generat_number(int **grid, int size);

//-------Movement-------//
void	move_left(int **grid, int size);
void	move_down(int **grid, int size);
void	move_up(int **grid, int size);
void	move_right(int **grid, int size);

//--------fusion--------//



#endif