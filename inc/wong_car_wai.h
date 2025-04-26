/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wong_car_wai.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:13:16 by secros            #+#    #+#             */
/*   Updated: 2025/04/26 09:42:47 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WONG_CAR_WAI_H
# define WONG_CAR_WAI_H

typedef struct	s_player	t_player;

# define NAME_D "Unknow"

enum e_const
{
	WIN_VALUE = 2048
};

struct t_player
{
	char	*name;
	size_t	score;
	int		**grid;
	int		size;
};

#endif