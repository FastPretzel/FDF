/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:52:32 by cgoth             #+#    #+#             */
/*   Updated: 2022/03/12 14:59:10 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	size(char **split)
{
	int	i;
	int	size;

	i = -1;
	size = 0;
	while (split[++i])
		size++;
	return (size);
}

static int	wrong_chars(char **split)
{
	int	i;
	int	j;

	i = -1;
	while (split[++i])
	{
		j = -1;
		while (split[i][++j] && split[i][j] != ',')
			if (!(ft_isdigit(split[i][j]) || split[i][j] == '-'))
				return (1);
	}
	return (0);
}

static int	check_dig(t_map *map)
{
	int		i;
	char	**split;

	if (!map->map)
		return (0);
	split = ft_split(map->map[0], ' ');
	map->width = size(split);
	free_split(split);
	i = 0;
	while (map->map[++i])
	{
		split = ft_split(map->map[i], ' ');
		if (map->width != size(split) || wrong_chars(split))
		{
			free_split(split);
			return (0);
		}
		free_split(split);
	}
	return (1);
}

static int	calc_height(char *line)
{
	int	i;
	int	height;

	i = -1;
	height = 0;
	while (line[++i])
		if (line[i] == '\n')
			height++;
	if (line[i - 1] != '\n')
		height++;
	return (height);
}

void	parse_map(char *file, t_fdf *fdf)
{
	int		fd;
	char	*line;
	char	*buf;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	line = 0;
	buf = get_next_line(fd);
	while (buf)
	{
		line = ft_strjoin(line, buf);
		free(buf);
		buf = get_next_line(fd);
	}
	fdf->map->map = ft_split(line, '\n');
	if (!check_dig(fdf->map))
	{
		fdf->map->map = 0;
		return ;
	}
	fdf->map->height = calc_height(line);
	free(line);
	close(fd);
}
