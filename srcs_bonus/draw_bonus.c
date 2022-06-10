/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:36:11 by cgoth             #+#    #+#             */
/*   Updated: 2022/03/11 20:36:24 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_draw(t_draw *draw, t_point *p1, t_point *p2)
{
	draw->dx = abs(p2->x - p1->x);
	draw->dy = abs(p2->y - p1->y);
	if (p1->x < p2->x)
		draw->sx = 1;
	else
		draw->sx = -1;
	if (p1->y < p2->y)
		draw->sy = 1;
	else
		draw->sy = -1;
	draw->err = draw->dx - draw->dy;
}

static void	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	int		e2;
	t_draw	draw;

	init_draw(&draw, &p1, &p2);
	my_mlx_pixel_put(fdf->data, p2.x, p2.y, p2.color);
	while (p1.x != p2.x || p1.y != p2.y)
	{
		my_mlx_pixel_put(fdf->data, p1.x, p1.y, p1.color);
		e2 = draw.err * 2;
		if (e2 > -draw.dy)
		{
			draw.err -= draw.dy;
			p1.x += draw.sx;
		}
		if (e2 < draw.dx)
		{
			draw.err += draw.dx;
			p1.y += draw.sy;
		}
	}
}

static void	bresenham(t_fdf *fdf, t_map *map, t_point **points)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height - 1)
	{
		j = -1;
		while (++j < map->width - 1)
		{
			draw_line(fdf, init_point(points[i][j], fdf), \
					init_point(points[i + 1][j], fdf));
			draw_line(fdf, init_point(points[i][j], fdf), \
					init_point(points[i][j + 1], fdf));
			if (i == map->height - 2)
				draw_line(fdf, init_point(points[i + 1][j], fdf), \
						init_point(points[i + 1][j + 1], fdf));
			if (j == map->width - 2)
				draw_line(fdf, init_point(points[i][j + 1], fdf), \
						init_point(points[i + 1][j + 1], fdf));
		}
	}
}

int	draw(t_fdf *fdf)
{
	if (fdf->keys->esc_key)
		clean(fdf);
	reset_img(fdf);
	rotate(fdf->keys, fdf->camera);
	translate(fdf->keys, fdf->camera);
	zoom(fdf);
	bresenham(fdf, fdf->map, fdf->points);
	mlx_put_image_to_window(fdf->data->mlx, fdf->data->win, \
			fdf->data->img, 0, 0);
	return (0);
}
