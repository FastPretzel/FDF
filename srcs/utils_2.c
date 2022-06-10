/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:36:31 by cgoth             #+#    #+#             */
/*   Updated: 2022/03/11 21:05:47 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*to_upper(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
	return (str);
}

int	ft_min(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	reset_img(t_fdf *fdf)
{
	int	size;

	size = WIDTH * HEIGHT * (fdf->data->bits_per_pixel / 8);
	while (size--)
		fdf->data->addr[size] = 0;
}

void	zoom(t_fdf *fdf)
{
	if (fdf->keys->plus_key)
		fdf->map->tile_size += 0.02 * fdf->map->tile_size;
	else if (fdf->keys->minus_key && fdf->map->tile_size > 0.01)
		fdf->map->tile_size -= 0.02 * fdf->map->tile_size;
}
