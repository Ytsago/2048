/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highscore.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:43:30 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 15:06:04 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
#include "wong_car_wai.h"

int	get_highscore(char *filename, t_player *player)
{
	int	fd = open(filename, O_RDWR | O_CREAT, 0644);

	if (fd == -1)
		return (1);
	
	
}

int	main()
{
	
}