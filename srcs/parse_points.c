/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:45:46 by cgoth             #+#    #+#             */
/*   Updated: 2022/03/11 22:08:30 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	**malloc_points(t_map *map)
{
	t_point	**points;
	int		i;

	points = malloc(sizeof(t_point *) *(map->height + 1));
	if (!points)
		return (0);
	points[map->height] = 0;
	i = -1;
	while (++i < map->height)
	{
		points[i] = malloc(sizeof(t_point) * map->width);
		if (!points[i])
			return (0);
	}
	return (points);
}

char	*is_colored(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == ',' && str[i + 1])
			return (str + i);
	return (0);
}

static unsigned int	get_color(char *split)
{
	int				i;
	int				j;
	unsigned int	color;
	int				len;
	char			*base;

	base = "0123456789ABCDEF";
	color = 0;
	i = -1;
	len = 0;
	split = to_upper(split);
	while (split[++i])
		len++;
	i = 1;
	while (split[++i])
	{
		j = -1;
		while (++j < 16)
			if (split[i] == base[j])
				color += j * pow(16, len - (i + 1));
	}
	return (color);
}

static void	set_color(char *split, t_point *point)
{	
	if (is_colored(split))
		point->color = get_color(is_colored(split));
	else
		point->color = 0x00FFFFFF;
}

t_point	**parse_points(t_map *map)
{
	t_point	**points;
	int		x;
	int		y;	
	char	**split;

	y = -1;
	points = malloc_points(map);
	if (!points)
		return (0);
	while (map->map[++y])
	{
		x = -1;
		split = ft_split(map->map[y], ' ');
		while (split[++x])
		{
			set_color(split[x], &(points[y][x]));
			points[y][x].x = x;
			points[y][x].y = y;
			points[y][x].z = ft_atoi(split[x]);
		}
		free_split(split);
	}
	return (points);
}
