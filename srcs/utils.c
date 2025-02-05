/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:52:06 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/05 22:52:27 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_stradd(char *s1, char *s2)
{
	char	*res;

	if (s1 == NULL)
	{
		res = ft_strdup(s2);
		return (res);
	}
	else
	{
		res = ft_strjoin(s1, s2);
		free(s1);
		return (res);
	}
}

void	floodfill(int r, int c, t_map *map)
{
	if ((r < 0 || r >= map->rows || c < 0 || c >= map->columns)
		|| map->full_map[r][c] == 'v' || map->full_map[r][c] == WALL)
		return ;
	map->full_map[r][c] = 'v';
	floodfill(r, c + 1, map);
	floodfill(r, c - 1, map);
	floodfill(r + 1, c, map);
	floodfill(r - 1, c, map);
}
