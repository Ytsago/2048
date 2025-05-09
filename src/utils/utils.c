/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:38:25 by lilefebv          #+#    #+#             */
/*   Updated: 2025/04/27 11:37:20 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wong_car_wai.h"
#include <time.h>
#include "ft_printf.h"
#include "get_next_line.h"

void init_display_colors()
{
    init_pair(COLOR_PAIR_BG, COLOR_BLACK, COLOR_WHITE);
    init_pair(COLOR_PAIR_2, COLOR_BLACK, COLOR_WHITE);
    init_pair(COLOR_PAIR_4, COLOR_BLACK, COLOR_YELLOW);
    init_pair(COLOR_PAIR_8, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(COLOR_PAIR_16, COLOR_WHITE, COLOR_RED);
    init_pair(COLOR_PAIR_32, COLOR_WHITE, COLOR_GREEN);
    init_pair(COLOR_PAIR_64, COLOR_WHITE, COLOR_CYAN);
    init_pair(COLOR_PAIR_128, COLOR_BLACK, COLOR_YELLOW);
    init_pair(COLOR_PAIR_256, COLOR_BLACK, COLOR_CYAN);
    init_pair(COLOR_PAIR_512, COLOR_WHITE, COLOR_BLUE);
    init_pair(COLOR_PAIR_1024, COLOR_WHITE, COLOR_MAGENTA);
    init_pair(COLOR_PAIR_2048, COLOR_WHITE, COLOR_RED);
    init_pair(COLOR_PAIR_HIGHER, COLOR_WHITE, COLOR_BLACK);
}

int get_tile_color(int value)
{
    switch (value) {
        case 0: return COLOR_PAIR_BG;
        case 2: return COLOR_PAIR_2;
        case 4: return COLOR_PAIR_4;
        case 8: return COLOR_PAIR_8;
        case 16: return COLOR_PAIR_16;
        case 32: return COLOR_PAIR_32;
        case 64: return COLOR_PAIR_64;
        case 128: return COLOR_PAIR_128;
        case 256: return COLOR_PAIR_256;
        case 512: return COLOR_PAIR_512;
        case 1024: return COLOR_PAIR_1024;
        case 2048: return COLOR_PAIR_2048;
        default: return COLOR_PAIR_HIGHER;
    }
}

int	**create_grid(int size)
{
	int	**grid;
	int	i = 0;

	grid = ft_calloc(sizeof(int *), size + 1);
	if (!grid)
		return (NULL);
	while (i < size)
	{
		grid[i] = ft_calloc(sizeof(int), size);
		if (!grid[i])
		{
			free_the_mallocs((void *)grid);
			return (NULL);
		}
		i++;
	}
	return (grid);
}

void	display(int **grid, int size)
{
	int	j;
	int	i = 0;

	while (grid[i])
	{
		j = 0;
		while (j < size)
			ft_printf("[%d]", grid[i][j++]);
		ft_printf("\n");
		i++;
	}
}

int sig_global = -1;

int	ft_get_n_size(size_t n)
{
	size_t	nsize;

	if (n == 0)
		return (1);
	nsize = 0;
	while (n > 0)
	{
		nsize++;
		n = n / 10;
	}
	return (nsize);
}

void	display_menu(int *running, int *skippall, WINDOW *menu, int *selected_grid)
{
	int	input;
	*running = 1;
	clear();

	while (*running)
	{
		if (COLS < 36 || LINES < 16) {
			mvwprintw(menu, LINES / 2, COLS / 2 - 13 / 2, "Win to small");
		}
		else
		{
			box(menu, ACS_VLINE, ACS_HLINE);
			mvwprintw(menu, 2, COLS / 2 - 31 / 2, " ,---.   ,--.    ,---. ,---.    ");
			mvwprintw(menu, 3, COLS / 2 - 31 / 2, "'.-.  \\ /    \\  /    ||  o  | ");
			mvwprintw(menu, 4, COLS / 2 - 31 / 2, " .-' .'|  ()  |/  '  |.'   '.   ");
			mvwprintw(menu, 5, COLS / 2 - 31 / 2, "/   '-. \\    / '--|  ||  o  |  ");
			mvwprintw(menu, 6, COLS / 2 - 31 / 2, "'-----'  `--'     `--' `---'    ");
			
			mvwprintw(menu, 8, COLS / 2 - 22 / 2, "PRESS [SPACE] TO START  ");


			if (*selected_grid == 4)
			{
				mvwprintw(menu, 10, COLS / 2 - 6 / 2 - 2, "> 4x4  ");
				mvwprintw(menu, 11, COLS / 2 - 6 / 2 - 2, "  5x5  ");
			}
			else
			{
				mvwprintw(menu, 10, COLS / 2 - 6 / 2 - 2, "  4x4  ");
				mvwprintw(menu, 11, COLS / 2 - 6 / 2 - 2, "> 5x5  ");
			}


			mvwprintw(menu, LINES - 3, COLS / 2 - 22 / 2, "By secros & lilefebv");

			input = getch();
			if (input != ERR) {
				if (input == 'q' || input == 27) {
					*skippall = 1;
					*running = 0;
				}
				else if (input == ' ') {
					*running = 0;
				}
				else if (input == KEY_DOWN) {
					if (*selected_grid == 4)
						*selected_grid = 5;
				}
				else if (input == KEY_UP) {
					if (*selected_grid == 5)
						*selected_grid = 4;
				}
			}
		}
		if (sig_global == SIGWINCH)
		{
			endwin();
			clear();
			wrefresh(menu);
			sig_global = -1;
		}
		wrefresh(menu);
	}
}

void window_resize(int signal)
{
	sig_global = SIGWINCH;
	(void)signal;
}

void rectangle(int y1, int x1, int y2, int x2)
{
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

void draw_game_grid(int size) {
    int grid_top = 0;
    int grid_bottom = LINES - 5;
    int grid_left = 0;
    int grid_right = COLS - 1;

    int cell_width = (grid_right - grid_left) / size;
    int cell_height = (grid_bottom - grid_top) / size;

    for (int row = 0; row <= size; ++row) {
        int y = grid_top + row * cell_height;
		if (row == size)
			y = grid_bottom;
        for (int x = grid_left; x <= grid_right; ++x) {
            move(y, x);

            if (x == grid_left) {
                if (row == 0)
                    addstr("┌");
                else if (row == size)
                    addstr("└");
                else
                    addstr("├");
            }
            else if (x == grid_right) {
                if (row == 0)
                    addstr("┐");
                else if (row == size)
                    addstr("┘");
                else
                    addstr("┤");
            }
            else if ((x - grid_left) % cell_width == 0 && (x - grid_left) < size * cell_width) {
                if (row == 0)
                    addstr("┬");
                else if (row == size)
                    addstr("┴");
                else
                    addstr("┼");
				
            }
            else {
                addstr("─");
            }
        }
    }

    for (int col = 0; col < size; ++col) {
        int x = grid_left + col * cell_width;
        for (int y = grid_top; y <= grid_bottom; ++y) {
			int c = (y - grid_top) % cell_height == 0;
			if ((y - grid_top) >= size * cell_height)
				c = y == grid_bottom;
            if (c)
                continue;

            move(y, x);
            addstr("│");
        }
    }
}

void	fill_cell(int y, int x, int size)
{
	int grid_top = 0;
    int grid_bottom = LINES - 5;
    int grid_left = 0;
    int grid_right = COLS - 1;

	int cell_width = (grid_right - grid_left) / size;
    int cell_height = (grid_bottom - grid_top) / size;

	int x1 = x * cell_width + 1;
	int y1 = y * cell_height + 1;
	int x2 = x1 + cell_width - 1;
	int y2 = y1 + cell_height - 1;
	if (y == size - 1)
		y2 = LINES - 5;
	if (x == size - 1)
		x2 = COLS - 1;
	
	while (y1 < y2)
	{
		int t = x1;
		while (t < x2)
		{
			mvprintw(y1, t, " ");
			t++;
		}
		y1++;
	}
}

void	print_chiffre(int x, int y, int nb)
{
	static const unsigned char	nb_tab[10][5] = {
		{0x3E, 0x51, 0x49, 0x45, 0x3E},
		{0x00, 0x42, 0x7F, 0x40, 0x00},
		{0x42, 0x61, 0x51, 0x49, 0x46},
		{0x21, 0x41, 0x45, 0x4B, 0x31},
		{0x18, 0x14, 0x12, 0x7F, 0x10},
		{0x27, 0x45, 0x45, 0x45, 0x39},
		{0x3C, 0x4A, 0x49, 0x49, 0x30},
		{0x03, 0x01, 0x71, 0x09, 0x07},
		{0x36, 0x49, 0x49, 0x49, 0x36},
		{0x06, 0x49, 0x49, 0x29, 0x1E}
	};

	int i, j;
	i = -1;
	while (++i < 5)
	{
		j = -1;
		while (++j < 7)
			if (nb_tab[nb][i] & (1 << j))
				mvprintw(y + j, x + i, "█");
	}
}

void print_nb_recur(int *x, int y, int nb)
{
	if (nb > 10)
		print_nb_recur(x, y, nb / 10);
	print_chiffre(*x, y, nb % 10);
	*x += 6;
}

void	print_nb(int x, int y, int nb)
{
	y -= 3;
	x -= ft_get_n_size(nb) * 3 - 1;

	print_nb_recur(&x, y, nb);
}

void	put_grid_to_win(int **grid, int size, int biggest)
{
	int grid_top = 0;
    int grid_bottom = LINES - 5;
    int grid_left = 0;
    int grid_right = COLS - 1;

    int cell_width = (grid_right - grid_left) / size;
    int cell_height = (grid_bottom - grid_top) / size;

	int printbignb = 0;
	if (ft_get_n_size(biggest) * 6 < cell_width && cell_height >= 9)
		printbignb = 1;
	
	int x, y;
	y = 0;
	while (y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (grid[y][x] == 0)
				continue ;
			attron(COLOR_PAIR(get_tile_color(grid[y][x])));
			fill_cell(y, x, size);
			if (printbignb)
				print_nb(x * cell_width + cell_width / 2 - ft_get_n_size(grid[y][x]) / 2, y * cell_height + cell_height / 2, grid[y][x]);
			else
				mvprintw(y * cell_height + cell_height / 2, x * cell_width + cell_width / 2 - ft_get_n_size(grid[y][x]) / 2, "%d", grid[y][x]);
			attroff(COLOR_PAIR(get_tile_color(grid[y][x])));
		}
		y++;
	}
}

int is_game_blocked(int **grid, int size)
{
	int x, y;

	y = -1;
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			if (grid[y][x] == 0)
				return (0);
			if (x > 0 && grid[y][x] == grid[y][x - 1])
				return (0);
			if (x < size - 1 && grid[y][x] == grid[y][x + 1])
				return (0);
			if (y > 0 && grid[y][x] == grid[y - 1][x])
				return (0);
			if (y < size - 1 && grid[y][x] == grid[y + 1][x])
				return (0);
		}
	}
	return (1);
}

void	game_while(int selected_grid, int **grid, size_t *score, int win_condition, int *biggest, int *youaredead_screen, t_player *current_player, t_player *high)
{
	WINDOW	*game;
	int input;

	int		running = 1;
	game = subwin(stdscr, LINES, COLS, 0, 0);
	int y, x;

	init_display_colors();
	
	while (running)
	{
		if (COLS < 36 || LINES <= 16) {
			mvwprintw(game, LINES / 2, COLS / 2 - 13 / 2, "Win to small");
		}
		else
		{
			erase();
			assume_default_colors(COLOR_WHITE, COLOR_BLACK);
			box(game, ACS_VLINE, ACS_HLINE);
			draw_game_grid(selected_grid);
			mvwprintw(game, LINES - 5, 0, "├");
			mvwprintw(game, LINES - 5, COLS - 1, "┤");
			put_grid_to_win(grid, selected_grid, *biggest);

			if (current_player->score == 0 && high->score == 0)
				mvwprintw(game, LINES - 3, 10, "Score : %zu", *score);
			else if (current_player->score != 0 && high->score == 0)
				mvwprintw(game, LINES - 3, 10, "Score : %zu    Personal best : %zu", *score, current_player->score);
			else if (current_player->score == 0 && high->score != 0 && high->name)
				mvwprintw(game, LINES - 3, 10, "Score : %zu    Global best : %s: %zu", *score, high->name, high->score);
			else if (current_player->score != 0 && high->score != 0 && high->name)
				mvwprintw(game, LINES - 3, 10, "Score : %zu    Personal best : %zu    Global best : %s: %zu", *score, current_player->score, high->name, high->score);

			y = 0;
			while (y < selected_grid)
			{
				x = 0;
				while (x < selected_grid)
				{
					if (*biggest < grid[y][x])
						*biggest = grid[y][x];
					x++;
				}
				y++;
			}

			if (win_condition != -1 && win_condition <= *biggest)
			{
				if (current_player->score == 0 && high->score == 0)
					mvwprintw(game, LINES - 3, 30, "You won, you can leave the game with [SPACE]");
				else
					mvwprintw(game, LINES - 2, 30, "You won, you can leave the game with [SPACE]");
			}
	
			input = getch();
			if (input != ERR) {
				if (input == 'q' || input == 27) {
					running = 0;
				} else if (input == KEY_LEFT) {
					if (move_left(grid, selected_grid, score))
					{
						if (generat_number(grid, selected_grid))
						{
							*youaredead_screen = 1;
							running = 0;
						}

					}
					if (is_game_blocked(grid, selected_grid))
					{
						*youaredead_screen = 1;
						running = 0;
					}
				} else if (input == KEY_RIGHT) {
					if (move_right(grid, selected_grid, score))
					{
						if (generat_number(grid, selected_grid))
						{
							*youaredead_screen = 1;
							running = 0;
						}
					}
					if (is_game_blocked(grid, selected_grid))
					{
						*youaredead_screen = 1;
						running = 0;
					}
				} else if (input == KEY_UP) {
					if (move_up(grid, selected_grid, score))
					{
						if (generat_number(grid, selected_grid))
						{
							*youaredead_screen = 1;
							running = 0;
						}
					}
					if (is_game_blocked(grid, selected_grid))
					{
						*youaredead_screen = 1;
						running = 0;
					}
				} else if (input == KEY_DOWN) {
					if (move_down(grid, selected_grid, score))
					{
						if (generat_number(grid, selected_grid))
						{
							*youaredead_screen = 1;
							running = 0;
						}
					}
					if (is_game_blocked(grid, selected_grid))
					{
						*youaredead_screen = 1;
						running = 0;
					}
				} else if (input == ' ') {
					if (win_condition != -1 && win_condition <= *biggest)
					{
						*youaredead_screen = 1;
						running = 0;
					}
				}
			}
		}
		
		if (sig_global == SIGWINCH)
		{
			endwin();
			clear();
			wrefresh(game);
			sig_global = -1;
		}
		wrefresh(game);
	}

	init_pair(1 , COLOR_RED, COLOR_BLACK);
}
