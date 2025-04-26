#include <ncurses.h>
#include "wong_car_wai.h"


int	ft_get_n_size(int n)
{
	int	nsize;

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
		box(menu, ACS_VLINE, ACS_HLINE);
		mvwprintw(menu, 2, COLS / 2 - 31 / 2, " ,---.   ,--.    ,---. ,---.  ");
		mvwprintw(menu, 3, COLS / 2 - 31 / 2, "'.-.  \\ /    \\  /    ||  o  | ");
		mvwprintw(menu, 4, COLS / 2 - 31 / 2, " .-' .'|  ()  |/  '  |.'   '. ");
		mvwprintw(menu, 5, COLS / 2 - 31 / 2, "/   '-. \\    / '--|  ||  o  | ");
		mvwprintw(menu, 6, COLS / 2 - 31 / 2, "'-----'  `--'     `--' `---'  ");
		
		mvwprintw(menu, 9, COLS / 2 - 22 / 2, "PRESS [SPACE] TO START");


		if (*selected_grid == 4)
		{
			mvwprintw(menu, 12, COLS / 2 - 6 / 2, "> 4x4");
			mvwprintw(menu, 13, COLS / 2 - 6 / 2, "  5x5");
		}
		else
		{
			mvwprintw(menu, 12, COLS / 2 - 6 / 2, "  4x4");
			mvwprintw(menu, 13, COLS / 2 - 6 / 2, "> 5x5");
		}


		mvwprintw(menu, LINES - 3, COLS / 2 - 22 / 2, "By secros & lilefebv");

		input = getch();
		if (input != ERR) {
			if (input == 'q') {
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
		
		wrefresh(menu);
	}
}

int main(void) {
	setlocale(LC_ALL, "en_US.UTF-8");
    initscr();
	nodelay(stdscr, TRUE);
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	cbreak();

	if (COLS < 7 || LINES < 7) {
        endwin();
        printf("Le terminal est trop petit. Résolution minimale requise : 80x24.\n");
        return 1;          
    }
	
    WINDOW	*game;
	WINDOW 	*infos;
	WINDOW 	*death_screen;
	WINDOW 	*menu;
	
	int				running = 1;
	
	int				youaredead_screen = 0;
	
	int				skippall = 0;

	int score = 0;


	start_color();
	assume_default_colors(COLOR_WHITE, COLOR_BLACK);
	
	menu = subwin(stdscr, LINES, COLS, 0, 0);
	int		selected_grid = 4;
	int		input;
	display_menu(&running, &skippall, menu, &selected_grid);
	
	running = 1;
	clear();

	if (skippall == 0)
	{
		game = subwin(stdscr, LINES - 5, COLS, 0, 0);
		infos = subwin(stdscr, 5, COLS, LINES - 5, 0);

		init_pair(1 , COLOR_RED, COLOR_BLACK);
	
		box(game, ACS_VLINE, ACS_HLINE);
		box(infos, ACS_VLINE, ACS_HLINE);

		while (running)
		{
			input = getch();
			if (input != ERR) {
				if (input == 'q') {
					running = 0;
				} else {
					mvwprintw(game, 10, 10, "%d", input);
				}
			}

			wrefresh(game);
		}

	
		clear();
		
		start_color();
		assume_default_colors(COLOR_RED, COLOR_BLACK);

		if (youaredead_screen == 1)
		{		
			death_screen = subwin(stdscr, LINES, COLS, 0, 0);
			box(death_screen, ACS_VLINE, ACS_HLINE);
			
			attron(COLOR_PAIR(1));
			mvwprintw(death_screen, LINES / 2 - 3, COLS / 2 - 63 / 2, " _  _  __   _  _     __   ____  ____    ____  ____   __   ____ ");
			mvwprintw(death_screen, LINES / 2 - 2, COLS / 2 - 63 / 2, "( \\/ )/  \\ / )( \\   / _\\ (  _ \\(  __)  (    \\(  __) / _\\ (    \\");
			mvwprintw(death_screen, LINES / 2 - 1, COLS / 2 - 63 / 2, " )  /(  O )) \\/ (  /    \\ )   / ) _)    ) D ( ) _) /    \\ ) D (");
			mvwprintw(death_screen, LINES / 2, COLS / 2 - 63 / 2, "(__/  \\__/ \\____/  \\_/\\_/(__\\_)(____)  (____/(____)\\_/\\_/(____/");
			
			mvwprintw(death_screen, LINES / 2 + 2, COLS / 2 - ((8 + ft_get_n_size(score)) / 2), "Score : %d", score);
			attroff(COLOR_PAIR(1));
			
			wrefresh(death_screen);
			usleep(5000000);

		}
	}
	
    endwin();    
    return 0;
}
