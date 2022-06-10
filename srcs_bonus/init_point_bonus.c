/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:35:56 by cgoth             #+#    #+#             */
/*   Updated: 2022/03/11 20:36:28 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_vals(t_point *p, t_fdf *fdf)
{
	p->x *= fdf->map->tile_size;
	p->y *= fdf->map->tile_size;
	p->z *= fdf->map->tile_size;
}

static void	reset_camera(t_camera *camera)
{
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
}

static void	prev_camera(t_camera *camera, t_prev *prev)
{
	camera->alpha = prev->a;
	camera->beta = prev->b;
	camera->gamma = prev->g;
}

t_point	init_point(t_point p, t_fdf *fdf)
{
	t_prev	prev;

	init_vals(&p, fdf);
	p.x -= fdf->map->tile_size * (fdf->map->width / 2);
	p.y -= fdf->map->tile_size * (fdf->map->height / 2);
	prev.a = fdf->camera->alpha;
	prev.b = fdf->camera->beta;
	prev.g = fdf->camera->gamma;
	if (fdf->keys->p_key || fdf->keys->o_key)
		reset_camera(fdf->camera);
	rotate_x(&p, fdf->camera->alpha);
	rotate_y(&p, fdf->camera->beta);
	rotate_z(&p, fdf->camera->gamma);
	prev.x = p.x;
	prev.y = p.y;
	if (!fdf->keys->p_key)
	{
		p.x = (prev.x - prev.y) * cos(0.523599);
		p.y = (prev.x + prev.y - p.z) * sin(0.523599);
	}
	if (!fdf->keys->o_key)
		prev_camera(fdf->camera, &prev);
	p.x += fdf->camera->off_x + (WIDTH / 2);
	p.y += fdf->camera->off_y + (HEIGHT / 2);
	return (p);
}
