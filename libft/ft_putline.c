/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:05:35 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/03 16:05:47 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_putline(char *src, char *dest)
{
	int	i;

	i = 0;
	if (src[0] == '\0')
		return (NULL);
	while (src[i] != '\n')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}
