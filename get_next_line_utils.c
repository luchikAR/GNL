/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenonat <gvenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:42:55 by gvenonat          #+#    #+#             */
/*   Updated: 2021/01/09 12:45:25 by gvenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t count;

	count = 0;
	while (str && str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*s1_now;
	char	*s2_now;
	char	*res;
	int		i;

	if (s2 == NULL)
		return ((char *)s1);
	i = 0;
	s1_now = (char *)s1;
	s2_now = (char *)s2;
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (res == 0)
		return (NULL);
	while (s1 && *s1_now != '\0')
		res[i++] = *s1_now++;
	while (*s2_now != '\0')
		res[i++] = *s2_now++;
	res[i] = '\0';
	free(s1);
	return (res);
}

int		ft_check_n(char *buffer)
{
	int i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_p2(char *part2)
{
	int i;

	i = 0;
	while (part2 && part2[i] != '\0' && part2[i] != '\n')
		i++;
	if (part2 && part2[i] == '\n')
		return (1);
	return (0);
}
