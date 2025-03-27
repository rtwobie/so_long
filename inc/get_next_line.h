/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rha-le <rha-le@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:08:49 by rha-le            #+#    #+#             */
/*   Updated: 2025/01/15 16:03:49 by rha-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_FD
#  define OPEN_FD 4096
# endif

# include <unistd.h>

typedef struct s_vars
{
	char	*stash[OPEN_FD];
	char	*buf;
	char	*line;
	ssize_t	bytes_read;
	int		len;
}	t_vars;

int		read_file(int fd, t_vars *gn);
void	read_line(int fd, t_vars *gn);
char	*get_next_line(int fd);

#endif
