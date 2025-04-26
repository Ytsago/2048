/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong_car_wai.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:13:16 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 14:59:53 by lilefebv         ###   ########lyon.fr   */
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
	WIN_VALUE = 1
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
int		move_left(int **grid, int size, int *score);
int		move_down(int **grid, int size, int *score);
int		move_up(int **grid, int size, int *score);
int		move_right(int **grid, int size, int *score);

//--------Utils--------//
void	put_grid_to_win(int **grid, int size);
void draw_game_grid(int size);
void rectangle(int y1, int x1, int y2, int x2);
void window_resize(int signal);
void	display_menu(int *running, int *skippall, WINDOW *menu, int *selected_grid);
int	**create_grid(int size);
void	display(int **grid, int size);
int	ft_get_n_size(int n);
void	game_while(int selected_grid, int **grid, int *score, int win_condition, int *biggest, int *youaredead_screen);

#endif