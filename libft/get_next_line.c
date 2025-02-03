/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmenard <pmenard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:08:41 by pmenard           #+#    #+#             */
/*   Updated: 2025/02/03 16:18:01 by pmenard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*free_and_move_index(char **str)
{
	char	*temp;
	int		index;

	temp = malloc((ft_strlen(*str) + 1) * sizeof(char));
	if (temp == NULL)
	{
		free(*str);
		return (NULL);
	}
	temp = ft_stricpy(*str, temp, 0);
	if (ft_strfindchar(*str, '\n') != -1)
		index = (ft_strfindchar(*str, '\n') + 1);
	else
		index = ft_strlen(*str);
	temp += index;
	free(*str);
	*str = malloc((ft_strlen(temp) + 1) * sizeof(char));
	*str = ft_stricpy(temp, *str, 0);
	temp -= index;
	free(temp);
	return (*str);
}

char	*is_newline(char **str)
{
	char	*result;

	if (ft_strfindchar(*str, '\n') != -1)
	{
		result = malloc((ft_strfindchar(*str, '\n') + 2) * sizeof(char));
		if (!result)
			return (NULL);
		result = ft_putline(*str, result);
		*str = free_and_move_index(str);
		return (result);
	}
	else
	{
		result = malloc((ft_strlen(*str) + 1) * sizeof(char));
		if (!result)
			return (NULL);
		result = ft_stricpy(*str, result, 0);
		*str = free_and_move_index(str);
		return (result);
	}
}

char	*get_next_string(char **str, char *buffer, int fd, ssize_t bytes_read)
{
	if (bytes_read == 0 && **str == '\0')
	{
		free(*str);
		return (NULL);
	}
	if (bytes_read > 0)
	{
		*str = ft_realloc(*str, buffer);
		*str = ft_stricpy(buffer, *str, ft_strlen(*str));
	}
	while (ft_strfindchar(*str, '\n') == -1 && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		if (bytes_read > 0)
		{
			*str = ft_realloc(*str, buffer);
			*str = ft_stricpy(buffer, *str, ft_strlen(*str));
		}
	}
	return (is_newline(str));
}

char	*set_str(char *str, char **buffer, ssize_t bytes_read)
{
	if (bytes_read == 0)
	{
		free(*buffer);
		return (NULL);
	}
	str = malloc((bytes_read + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;
	char		*result;
	ssize_t		bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	if (str == NULL)
	{
		str = set_str(str, &buffer, bytes_read);
		if (str == NULL)
			return (NULL);
	}
	result = get_next_string(&str, buffer, fd, bytes_read);
	if (buffer)
		free(buffer);
	return (result);
}

/* #include <fcntl.h>
int	main(void)
{
	char	*file_content;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur lors de l'ouverture du fichier.\n");
		return (1);
	}
	file_content = get_next_line(fd);
	printf("%s", file_content);
	while (file_content != NULL)
	{
		free(file_content);
		file_content = get_next_line(fd);
		printf("%s", file_content);
	}
	printf("\n");
	free(file_content);
	close(fd); 

	printf("Entrez du texte (Ctrl+D pour terminer) :\n");
	while ((file_content = get_next_line(STDIN_FILENO)) != NULL)
	{
		write(STDOUT_FILENO, "Vous avez tapé : ", 18);
		printf("%s", file_content);
		free(file_content);
	}
	return (0);
} */
