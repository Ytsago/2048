/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highscore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:43:30 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 18:35:08 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "wong_car_wai.h"
#include "ft_printf.h"

int	check_file(char *str)
{
	int		i = 0;
	bool	origin = FALSE;

	while (str[i])
	{
		if (str[i] == ':')
		{
			if (origin == FALSE)
				origin = TRUE;
			else
				return (FALSE);
		}
		i++;
	}
	return (origin);
}

t_player	convert_to_board(char *str)
{
	t_player	new;
	int			i = 0;

	if (!check_file(str))
	{
		new.name = NULL;
		free (str);
		write (2, "Incorrect highscore file\n", 26);
		return (new);
	}
	while(str[i])
	{
		if (str[i] == ':')
		{
			str[i] = '\0';
			new.name = str;
			new.score = ft_atol(&str[i + 1]);
		}
		i++;
	}
	return (new);
}

size_t	lowest_score(t_high *board, int *j)
{
	int	i = 0;
	size_t	min;
	
	min = board->best[0].score;
	while (i < SCORE_SIZE)
	{
		if (board->best[i].score < min)
			min = board->best[i].score;
		i++;
	}
	i = 0;
	while (i < SCORE_SIZE)
	{
		if (board->best[i].score == min)
		{
			*j = i;
			break ;
		}
		i++;
	}
	return (min);
}

int	replace(t_high *board, t_player *new)
{
	size_t		min_score;
	int			i;

	min_score = lowest_score(board, &i);
	if (new->score > min_score)
	{
		free(board->best[i].name);
		board->best[i] = *new;
		return (1);
	}
	return (0);
}

int	get_highscore(char *filename, t_high *board, t_player *current)
{
	int			fd;
	char		*str;
	t_player	new;
	int			i = 0;

	fd = open(filename, O_RDWR | O_CREAT, 0644);
	if (fd == -1)
		return (1);
	while ((str = get_next_line(fd)))
	{
		new = convert_to_board(str);
		if (!new.name)
			return (2);
		if (!ft_strncmp(current->name, new.name, ft_strlen(current->name + 1)))
			current->score = new.score;
		if (i < SCORE_SIZE)
			board->best[i] = new;
		else if (replace(board, &new));
		else
			free(str);
		i++;
	}
	close(fd);
	return (0);
}

void	write_in_file(int fd, t_player actual, int new_score)
{
	size_t	i;
	char	*new;

	i = ft_strlen(actual.name);
	write (fd, actual.name, i);
	if (!new_score)
	{
		actual.name[i] = ':';
		write (fd, &actual.name[i], ft_strlen(&actual.name[i]));
	}
	else
	{
		write(fd, ":", 1);
		new = ft_itoa(actual.score);
		if (!new)
			write(fd, "0\n", 2);
		else
		{
			write (fd, new, ft_strlen(new));
			free(new);
		}
	}
}

int	update_score(char *filename, t_player *current)
{
	char		*str;
	bool		new_player = TRUE;
	t_player	readed;
	int			fd;
	int			fd2;

	fd = open(filename, O_RDWR);
	if (fd == -1)
		return (1);
	fd2 = open(TMP_FILENAME, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd2 == -1)
	{
		close(fd);
		return (1);
	}
	while ((str = get_next_line(fd)))
	{
		readed = convert_to_board(str);
		if (!readed.name)
			return (2);
		if (!ft_strncmp(current->name, readed.name, ft_strlen(current->name) + 1))
		{
			readed.score = current->score;
			write_in_file(fd2, readed, 1);
			new_player = FALSE;
		}
		else
			write_in_file(fd2, readed, 0);
		free(str);
	}
	if (new_player)
	{
		write_in_file(fd2, *current, 1);
		write(fd2, "\n", 1);
	}
	close(fd);
	close(fd2);
	unlink(filename);
	rename(TMP_FILENAME, filename);
	return (0);
}

void	sort_board(t_high *board)
{
	bool		sorted = FALSE;
	t_player	tmp;
	int			i = 0;

	while (!sorted)
	{
		if (i == SCORE_SIZE - 1)
		{
			i = 0;
			sorted = TRUE;
		}
		if (board->best[i].score < board->best[i + 1].score)
		{
			tmp = board->best[i];
			board->best[i] = board->best[i + 1];
			board->best[i + 1] = tmp;
			sorted = FALSE;
		}
		i++;
	}
}
