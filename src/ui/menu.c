#include "shmup.h"
#include <ncurses.h>
#include <stdio.h>

int		startx = 0;
int		starty = 0;

char	*choices[] = {"Game", "Exit"};
int		n_choices = sizeof(choices) / sizeof(char *);
int		setting_n_choices = sizeof(choices) / sizeof(char *);

void	print_ascii(void)
{
	int	start_y;
	int	start_x;

	int win_height, win_width;
	wclear(menu_win);
	getmaxyx(menu_win, win_height, win_width);
	start_y = (win_height - 8) / 2;
	start_x = (win_width - 48) / 2;
	mvwaddstr(menu_win, start_y + 2, start_x, SHMUP_0);
	mvwaddstr(menu_win, start_y + 3, start_x, SHMUP_1);
	mvwaddstr(menu_win, start_y + 4, start_x, SHMUP_2);
	mvwaddstr(menu_win, start_y + 5, start_x, SHMUP_3);
	mvwaddstr(menu_win, start_y + 6, start_x, SHMUP_4);
	mvwaddstr(menu_win, start_y + 7, start_x, SHMUP_5);
	mvwaddstr(menu_win, start_y + 8, start_x, SHMUP_6);
	mvwaddstr(menu_win, start_y + 9, start_x, SHMUP_7);
	wrefresh(menu_win);
}

void	print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;
	x = 2;
	y = 2;
	wclear(menu_win);
	print_ascii();
	box(menu_win, 0, 0);
	for (i = 0; i < n_choices; ++i)
	{
		if (highlight == i + 1)
		{
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}

int	menu(void)
{
	int	highlight;
	int	choice;
	int	c;

	highlight = 1;
	choice = 0;
	keypad(menu_win, TRUE);
	refresh();
	print_menu(menu_win, highlight);
	while (1)
	{
		c = wgetch(menu_win);
		switch (c)
		{
		case 'w':
		case KEY_UP:
			if (highlight == 1)
				highlight = n_choices;
			else
				--highlight;
			break ;
		case 's':
		case KEY_DOWN:
			if (highlight == n_choices)
				highlight = 1;
			else
				++highlight;
			break ;
		case 10:
			choice = highlight;
			break ;
		case 27:
			timeout(0);
			erase();
			return (0);
		}
		print_menu(menu_win, highlight);
		if (choice != 0)
			break ;
	}
	if (choice == 1)
	{
		timeout(0);
		erase();
		return (0);
	}
	else
	{
		endwin();
		return (1);
	}
}
