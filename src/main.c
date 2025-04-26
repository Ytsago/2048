/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilefebv <lilefebv@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:11:21 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 14:59:42 by lilefebv         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wong_car_wai.h"
#include <time.h>
#include "ft_printf.h"
#include "get_next_line.h"

int main(int ac, char **av) {
	setlocale(LC_ALL, "en_US.UTF-8");
    initscr();
	nodelay(stdscr, TRUE);
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	cbreak();

	WINDOW 	*death_screen;
	WINDOW 	*menu;
  char	*name;
	
  if (ac > 3)
		return (1);
	if (av[1])
		name = av[1];
	else
		name = NAME_D;
  
  srand(time(NULL));
  
	int		running = 1;
	int		youaredead_screen = 0;
	int		skippall = 0;

	int score = 0;

	signal(SIGWINCH, window_resize);

	start_color();
	assume_default_colors(COLOR_WHITE, COLOR_BLACK);
	
	menu = subwin(stdscr, LINES, COLS, 0, 0);
	int		selected_grid = 4;
	int		input;
	display_menu(&running, &skippall, menu, &selected_grid);

	int **grid = create_grid(selected_grid);
	if (!grid)
	{
		ft_printf("An error occured");
		return (1);
	}

	clear();

	int win_condition = WIN_VALUE;
	if (win_condition > 0 && (win_condition & (win_condition - 1)))
		win_condition = -1;
	int biggest = 0;

	if (skippall == 0)
	{
		int refreshnext = 1;
    	init_grid(grid, selected_grid);
	
		game_while(selected_grid, grid, &score, win_condition, &biggest, &youaredead_screen);
	
		clear();
		
		start_color();
		assume_default_colors(COLOR_RED, COLOR_BLACK);

		death_screen = subwin(stdscr, LINES, COLS, 0, 0);

		while (youaredead_screen == 1)
		{
			if (COLS < 36 || LINES <= 16) {
				mvwprintw(menu, LINES / 2, COLS / 2 - 13 / 2, "Win to small");
			}
			else
			{
				erase();
				box(death_screen, ACS_VLINE, ACS_HLINE);
				
				attron(COLOR_PAIR(1));
				
				if (win_condition == -1 || win_condition > biggest)
				{
					mvwprintw(death_screen, LINES / 2 - 3, COLS / 2 - 50 / 2, " _  _  __   _  _    __     __    __   ____  ____ ");
					mvwprintw(death_screen, LINES / 2 - 2, COLS / 2 - 50 / 2, "( \\/ )/  \\ / )( \\  (  )   /  \\  /  \\ / ___)(  __)");
					mvwprintw(death_screen, LINES / 2 - 1, COLS / 2 - 50 / 2, " )  /(  O )) \\/ (  / (_/\\(  O )(  O )\\___ \\ ) _) ");
					mvwprintw(death_screen, LINES / 2, COLS / 2 - 50 / 2, "(__/  \\__/ \\____/  \\____/ \\__/  \\__/ (____/(____)");
				}
				else
				{
					mvwprintw(death_screen, LINES / 2 - 3, COLS / 2 - 36 / 2, " _  _  __   _  _    _  _  __  __ _ ");
					mvwprintw(death_screen, LINES / 2 - 2, COLS / 2 - 36 / 2, "( \\/ )/  \\ / )( \\  / )( \\(  )(  ( \\");
					mvwprintw(death_screen, LINES / 2 - 1, COLS / 2 - 36 / 2, " )  /(  O )) \\/ (  \\ /\\ / )( /    /");
					mvwprintw(death_screen, LINES / 2, COLS / 2 - 36 / 2, "(__/  \\__/ \\____/  (_/\\_)(__)\\_)__)");
				}
				
				
				
				mvwprintw(death_screen, LINES / 2 + 2, COLS / 2 - ((8 + ft_get_n_size(score)) / 2), "Score : %d", score);
				attroff(COLOR_PAIR(1));
						
				input = getch();
				if (input != ERR) {
					if (input == 27 || input == 'q' || input == ' ') {
						youaredead_screen = 0;
					}
				}
			}
			
			if (sig_global == SIGWINCH)
			{
				endwin();
				//clear();
				wrefresh(death_screen);
				sig_global = -1;
				refreshnext = 1;
			}
			
			wrefresh(death_screen);
			refreshnext = 0;
			
		}
	}
	
    endwin();
	free_the_mallocs((void *)grid);
    return 0;
}
