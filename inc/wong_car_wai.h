/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong_car_wai.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:13:16 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 14:03:56 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_CAR_WAI_H
# define WONG_CAR_WAI_H

# include <ncurses.h>
# include <time.h>
# include <unistd.h>
# include <locale.h>
# include <signal.h>
# include "libft.h"
# include "ft_printf.h"

extern int sig_global;

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
int		move_left(int **grid, int size);
int		move_down(int **grid, int size);
int		move_up(int **grid, int size);
int		move_right(int **grid, int size);

#endif