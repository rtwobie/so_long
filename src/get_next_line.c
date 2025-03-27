/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:57:14 by rha-le            #+#    #+#             */
/*   Updated: 2025/01/15 16:06:00 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int	read_file(int fd, t_vars *gn)
{
	gn->bytes_read = 1;
	while (!ft_strchr(gn->stash[fd], '\n') && gn->bytes_read != 0)
	{
		gn->buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!gn->buf)
			return (-1);
		gn->bytes_read = read(fd, gn->buf, BUFFER_SIZE);
		if (gn->bytes_read < 0 || (gn->bytes_read == 0 && !gn->buf))
		{
			(free(gn->buf), gn->buf = NULL);
			(free(gn->stash[fd]), gn->stash[fd] = NULL);
			return (-1);
		}
		if (!gn->stash[fd])
			gn->stash[fd] = ft_strdup(gn->buf);
		else
			gn->stash[fd] = ft_strjoin(gn->stash[fd], gn->buf);
		(free(gn->buf), gn->buf = NULL);
		if (!gn->stash[fd])
			return (-1);
	}
	return (0);
}

void	read_line(int fd, t_vars *gn)
{
	char			*left;
	unsigned int	len;

	len = 0;
	while (gn->stash[fd][len] != '\n' && gn->stash[fd][len])
		len++;
	gn->line = ft_substr(gn->stash[fd], 0, len + 1);
	left = ft_substr(gn->stash[fd], len + 1, ft_strlen(gn->stash[fd]) - len);
	free(gn->stash[fd]);
	gn->stash[fd] = left;
}

char	*get_next_line(int fd)
{
	static t_vars	gn;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_file(fd, &gn) == -1)
		return (NULL);
	read_line(fd, &gn);
	return (gn.line);
}
