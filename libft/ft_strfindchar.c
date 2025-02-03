/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfindchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:04:10 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/03 16:04:47 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strfindchar(char *src, int c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
