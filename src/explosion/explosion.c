#include "explosion.h"
#include "shmup.h"

void	put_explosion(int row, int col, int step)
{
	if (step >= 0 && step < 5)
	{
		wattron(game_win, COLOR_PAIR(3));
		mvwaddch(game_win, row, col, '*');
		wattroff(game_win, COLOR_PAIR(3));
	}
	if (step >= 5 && step < 10)
	{
		wattron(game_win, COLOR_PAIR(3));
		mvwaddstr(game_win, row - 1, col - 1, "%%%");
		mvwaddch(game_win, row, col - 1, '%');
		mvwaddch(game_win, row, col + 1, '%');
		mvwaddstr(game_win, row + 1, col - 1, "%%%");
		wattroff(game_win, COLOR_PAIR(3));
		wattron(game_win, COLOR_PAIR(6));
		mvwaddch(game_win, row, col, '#');
		wattroff(game_win, COLOR_PAIR(6));
	}
	if (step >= 10)
	{
		wattron(game_win, COLOR_PAIR(3));
		mvwaddch(game_win, row, col, '#');
		wattroff(game_win, COLOR_PAIR(3));
	}
}

t_explosion	*new_explosion(int row, int col)
{
	t_explosion	*explosion;

	explosion = malloc(sizeof(t_explosion));
	if (!explosion)
		return (NULL);
	explosion->col = col;
	explosion->row = row;
	explosion->step = 0;
	return (explosion);
}

void	spawn_explosion(t_list **explosions, int row, int col)
{
	t_explosion	*explosion;
	t_list		*list;

	explosion = new_explosion(row, col);
	if (!explosion)
		return ;
	list = ft_lstnew((void *)explosion);
	if (!list)
	{
		free(explosion);
		return ;
	}
	ft_lstadd_back(explosions, list);
}

void	render_explosion(t_list **explosions)
{
	t_list			*last;
	t_list			*current;
	t_explosion 	*explosion;

	if (!explosions || *explosions == NULL)
		return ;
	current = *explosions;
	last = NULL;
	while (current)
	{
		explosion = (t_explosion *)current->content;
		put_explosion(explosion->row, explosion->col, explosion->step);
		if (explosion->step == 15)
			current = lstdel_relink(explosions, current, last);
		else
		{
			(explosion->step)++;
			last = current;
			current = current->next;
		}
	}
}
