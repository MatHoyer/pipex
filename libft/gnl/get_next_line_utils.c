/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:22:51 by mhoyer            #+#    #+#             */
/*   Updated: 2023/05/25 14:36:47 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy_gnl(void *dest, const void *src, int deb, int end)
{
	const char	*s;
	char		*d;
	int			i;

	if (!dest)
		return (NULL);
	s = src;
	d = dest;
	i = 0;
	while (deb < end)
	{
		d[i] = s[deb];
		deb++;
		i++;
	}
	return (dest);
}

char	*ft_strdup_gnl(char *s, int deb, int end)
{
	char	*str;

	str = malloc((end - deb) + 1);
	if (!str)
		return (NULL);
	if (ft_memcpy_gnl(str, s, deb, end) == NULL)
		return (NULL);
	str[end - deb] = '\0';
	return (str);
}

char	*ft_strdup_free(char *s, int deb, int end)
{
	char	*str;

	str = ft_strdup_gnl(s, deb, end);
	free(s);
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int t_s2)
{
	int		i;
	int		t_s1;
	char	*conc;

	if (!s1)
		return (ft_strdup_free(s2, 0, t_s2));
	t_s1 = ft_strlen_gnl(s1);
	i = 0;
	conc = malloc(t_s1 + t_s2 + 1);
	if (conc == NULL)
		return (NULL);
	while (i < t_s1)
	{
		conc[i] = s1[i];
		i++;
	}
	while (i < t_s1 + t_s2)
	{
		conc[i] = s2[i - t_s1];
		i++;
	}
	conc[i] = '\0';
	free(s1);
	free(s2);
	return (conc);
}
