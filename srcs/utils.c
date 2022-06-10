/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:53:28 by cgoth             #+#    #+#             */
/*   Updated: 2022/03/11 19:53:34 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		dst = data->addr + (y * data->line_length + \
				x * (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	clean(t_fdf *fdf)
{
	int	i;

	i = -1;
	while (fdf->map->map[++i])
		free(fdf->map->map[i]);
	free(fdf->map->map);
	i = -1;
	while (fdf->points[++i])
		free(fdf->points[i]);
	free(fdf->points);
	exit(0);
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit (0);
}

int	wrong_filename(char *name)
{
	if (!ft_strnstr(name, ".fdf", ft_strlen(name)))
		return (1);
	return (0);
}
