/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvenonat <gvenonat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:42:39 by gvenonat          #+#    #+#             */
/*   Updated: 2021/01/18 12:04:00 by gvenonat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_read_str(int fd, char **str);
int		ft_check_n(char *buffer);
int		ft_check_p2(char *part2);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_part1(char *str, char *part2);
char	*ft_part2(char *str, char *part2);
char	*ft_rep2(char *part2);

#endif
