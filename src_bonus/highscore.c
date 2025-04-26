/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highscore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:43:30 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 16:40:13 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "wong_car_wai.h"
#include "ft_printf.h"

t_player	convert_to_board(char *str)
{
	t_player	new;
	int			i = 0;
	
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
	while (i < BOARD_SIZE)
	{
		if (board->best[i].score < min)
			min = board->best[i].score;
		i++;
	}
	i = 0;
	while (i < BOARD_SIZE)
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
	char		*tmp;
	t_player	new;
	int			i = 0;

	fd = open(filename, O_RDWR | O_CREAT, 0644);
	if (fd == -1)
		return (1);
	while ((str = get_next_line(fd)))
	{
		new = convert_to_board(str);
		if (!ft_strncmp(current->name, new.name, ft_strlen(current->name + 1)))
			current->score = new.score;
		if (i < BOARD_SIZE)
			board->best[i] = new;
		else if (replace(board, &new));
		else
			free(str);
		i++;
	}
	close(fd);
}

// void	display_board(t_high board)
// {
// 	int	i = 0;
// 	while (i < BOARD_SIZE)
// 	{
// 		if (!board.best[i].name)
// 			break ;
// 		ft_printf("%s :", board.best[i].name);
// 		ft_printf(" %s\n", ft_itoa(board.best[i].score));
// 		i++;
// 	}
// }

// int	main()
// {
// 	t_high		board;
// 	t_player 	current;

// 	ft_bzero(&current, sizeof(t_player));
// 	current.name = NAME_D;

// 	ft_bzero(&board, sizeof(board));
// 	get_highscore(FILENAME, &board, &current);
// 	// display_board(board);
// 	int i = 0;
// 	while (i < BOARD_SIZE)
// 	{
// 		if (board.best[i].name)
// 			free(board.best[i].name);
// 		i++;
// 	}
// 	ft_printf("\n--- Current score : %d\n", current.score);
// }