/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:06:56 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/03 16:18:43 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, char *buffer)
{
	size_t	len_str;
	char	*new_str;

	len_str = ft_strlen(str);
	new_str = malloc((len_str + ft_strlen(buffer) + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	if (str)
	{
		new_str = ft_stricpy(str, new_str, 0);
		free(str);
	}
	return (new_str);
}
