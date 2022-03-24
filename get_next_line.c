/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenonat <gvenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:42:08 by gvenonat          #+#    #+#             */
/*   Updated: 2021/01/18 11:27:50 by gvenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_part1(char *str, char *part2)
{
	int		i;
	int		j;
	char	*part1;

	i = 0;
	j = 0;
	while (str && str[i] != '\0' && str[i] != '\n')
		i++;
	part1 = (char*)malloc(ft_strlen(part2) + i + 1);
	if (part1 == 0)
		return (NULL);
	i = 0;
	while (part2 && part2[i] != '\0' && part2[i] != '\n')
	{
		part1[i] = part2[i];
		i++;
	}
	while (str && str[j] != '\0' && str[j] != '\n')
	{
		part1[i] = str[j];
		j++;
		i++;
	}
	part1[i] = '\0';
	return (part1);
}

char	*ft_rep2(char *part2)
{
	int		i;
	int		j;
	char	*re;

	i = 0;
	j = 0;
	while (part2 && part2[i] != '\0' && part2[i] != '\n')
		i++;
	re = (char*)malloc(ft_strlen(part2) - i + 1);
	if (re == 0)
		return (NULL);
	if (part2 && part2[i] == '\n')
		i++;
	while (part2 && part2[i] != '\0')
	{
		re[j] = part2[i];
		i++;
		j++;
	}
	re[j] = '\0';
	free(part2);
	return (re);
}

char	*ft_part2(char *str, char *part2)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (str == 0)
		return (ft_rep2(part2));
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	free(part2);
	part2 = (char*)malloc(ft_strlen(str) + i + 1);
	if (part2 == 0)
		return (0);
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		part2[j] = str[i];
		i++;
		j++;
	}
	part2[j] = '\0';
	return (part2);
}

int		ft_read_str(int fd, char **str)
{
	int		len;
	char	*buffer;

	buffer = (char*)malloc(BUFFER_SIZE + 1);
	if (buffer == 0)
		return (0);
	while ((len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[len] = '\0';
		*str = ft_strjoin(*str, buffer);
		if (ft_check_n(buffer) == 0)
			break ;
	}
	free(buffer);
	if (len == -1 || len == 0)
		return (len);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			res;
	int			flag;
	char		*str;
	static char	*part2;

	str = NULL;
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	if ((flag = ft_check_p2(part2)) == 0)
		res = ft_read_str(fd, &str);
	else
		res = 1;
	if (res == -1 || (res == 0 && str && !*str))
	{
		free(str);
		free(part2);
		return (res);
	}
	*line = ft_part1(str, part2);
	if ((part2 = ft_part2(str, part2)) == 0)
		return (-1);
	free(str);
	if (res == 0 || fd == 1)
		free(part2);
	return (res);
}
