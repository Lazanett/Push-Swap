/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:41:38 by lazanett          #+#    #+#             */
/*   Updated: 2022/12/21 14:33:29 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_read(int fd, char *lu)
{
	char	*buffer;
	int		condition;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	condition = 1;
	while (!ft_strchr(lu, '\n') && condition != 0)
	{
		condition = read(fd, buffer, BUFFER_SIZE);
		if (condition == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[condition] = '\0';
		lu = ft_strjoin(lu, buffer);
	}
	free (buffer);
	return (lu);
}

char	*ft_verif_line(char *lu)
{
	char	*ligne;
	int		i;

	i = 0;
	if (!lu[0])
		return (NULL);
	while (lu[i] && lu[i] != '\n')
		i++;
	ligne = (char *)malloc(sizeof(char) * (i + 2));
	if (!ligne)
		return (NULL);
	i = 0;
	while (lu[i] != '\n' && lu[i])
	{
		ligne[i] = lu[i];
		i++;
	}
	if (lu[i] == '\n')
	{
		ligne[i] = lu[i];
		i++;
	}
	ligne[i] = '\0';
	return (ligne);
}

char	*ft_new_line(char *lu)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	if (!lu)
		return (NULL);
	while (lu[i] && lu[i] != '\n')
		i++;
	if (!lu[i])
	{
		free(lu);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(lu) - i + 1));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (lu[i])
		new[j++] = lu[i++];
	new[j] = '\0';
	free(lu);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*lu[1024];
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (0);
	lu[fd] = ft_read(fd, lu[fd]);
	if (!lu[fd])
		return (NULL);
	line = ft_verif_line(lu[fd]);
	lu[fd] = ft_new_line(lu[fd]);
	return (line);
}
