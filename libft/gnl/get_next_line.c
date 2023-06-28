/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:22:40 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/27 10:51:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	valide(char *str, int start)
{
	int	i;

	i = start;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int	find_retour(char *str, int i)
{
	if (i == 0 && str[0] == '\n')
		return (0);
	while (i != 0)
	{
		i--;
		if (str[i] == '\n')
			return (i + 1);
	}
	return (0);
}

char	*get_read(int fd, char *buffer, int *val)
{
	char	*buffer_tmp;

	buffer_tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer_tmp)
		return (NULL);
	*val = read(fd, buffer_tmp, BUFFER_SIZE);
	if (*val <= 0 && !buffer)
	{
		free(buffer_tmp);
		return (NULL);
	}
	buffer_tmp[*val] = '\0';
	buffer = ft_strjoin_gnl(buffer, buffer_tmp, *val);
	return (buffer);
}

char	*free_return(char **buffer)
{
	if (*buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd, int s)
{
	static char			*buffer = NULL;
	static int			deb = 0;
	int					val;

	if (s && (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0 || deb == -1))
		return (NULL);
	if (s)
		buffer = get_read(fd, buffer, &val);
	while (s && (buffer && deb >= 0 && buffer[deb]))
	{
		if (!valide(buffer, deb) && val > 0)
			buffer = get_read(fd, buffer, &val);
		deb++;
		if (buffer[deb - 1] == '\n')
			return (ft_strdup_gnl(buffer, find_retour(buffer, deb - 1), deb));
	}
	if (s && (buffer && val == 0 && deb > 0))
	{
		val = deb;
		deb = -1;
		if (val != find_retour(buffer, val))
			return (ft_strdup_gnl(buffer, find_retour(buffer, val), val));
	}
	deb = 0;
	return (free_return(&buffer));
}

/*#include <stdio.h>
int main()
{
	int file = open("trip/files/big_line_with_nl", O_RDONLY);
	char *str = get_next_line(file);
	printf("(1)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(2)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(3)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(4)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(5)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(6)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(7)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(8)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(9)%s", str);
	free(str);
	str = get_next_line(file);
	printf("(10)%s", str);
	free(str);
	

	close(file);
	return 0;
}*/
