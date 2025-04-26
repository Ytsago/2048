/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong_car_wai.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:13:16 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 17:11:42 by secros           ###   ########.fr       */
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
# define FILENAME "highscore.txt"
# define TMP_FILENAME "tmp_highscore.txt"
# define SCORE_SIZE 5

typedef struct	s_player	t_player;

typedef struct	s_high	t_high;

enum e_const
{
	WIN_VALUE = 2048
};

enum colors_pairs {
	COLOR_PAIR_BG = 2,
	COLOR_PAIR_2,
	COLOR_PAIR_4,
	COLOR_PAIR_8,
	COLOR_PAIR_16,
	COLOR_PAIR_32,
	COLOR_PAIR_64,
	COLOR_PAIR_128,
	COLOR_PAIR_256,
	COLOR_PAIR_512,
	COLOR_PAIR_1024,
	COLOR_PAIR_2048,
	COLOR_PAIR_HIGHER
};

struct s_player
{
	char	*name;
	size_t	score;
};

struct s_high
{
	t_player	best[SCORE_SIZE];
};

void	init_grid(int **grid, int size);
int		generat_number(int **grid, int size);

//-------Movement-------//
int		move_left(int **grid, int size, int *score);
int		move_down(int **grid, int size, int *score);
int		move_up(int **grid, int size, int *score);
int		move_right(int **grid, int size, int *score);

//--------Utils--------//
void draw_game_grid(int size);
void rectangle(int y1, int x1, int y2, int x2);
void window_resize(int signal);
void	display_menu(int *running, int *skippall, WINDOW *menu, int *selected_grid);
int	**create_grid(int size);
void	display(int **grid, int size);
int	ft_get_n_size(int n);
void	game_while(int selected_grid, int **grid, int *score, int win_condition, int *biggest, int *youaredead_screen);
void init_display_colors();

#endif