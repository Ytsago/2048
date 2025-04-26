/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highscore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:43:30 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 15:41:44 by secros           ###   ########.fr       */
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
			str[i] = '\0';
		new.name = str;
		new.score = ft_atol(&str[i + 1]);
	}
	return (new);
}

// int	lowest_score(t_high *board)
// {
// 	int	i = 0;
// 	size_t	max;
	
// 	while (i < BOARD_SIZE)
// 	{
		
// 	}
// }

int	get_highscore(char *filename, t_high *board)
{
	int		fd;
	char	*str;
	char	*tmp;
	int		i = 0;

	fd = open(filename, O_RDWR | O_CREAT, 0644);
	if (fd == -1)
		return (1);
	while ((str = get_next_line(fd)))
	{
		if (i < BOARD_SIZE)
			board->best[i] = convert_to_board(str);
		else
			free(str);
		i++;
	}
}

void	display_board(t_high board)
{
	int	i = 0;
	while (i < BOARD_SIZE)
	{
		if (!board.best[i].name)
			break ;
		ft_printf("%s :", board.best[i].name);
		ft_printf(" %s\n", ft_itoa(board.best[i].score));
		i++;
	}
}

int	main()
{
	t_high	board;

	ft_bzero(&board, sizeof(board));
	get_highscore(FILENAME, &board);
	display_board(board);
}