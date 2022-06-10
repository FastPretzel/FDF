/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:50:37 by cgoth             #+#    #+#             */
/*   Updated: 2022/03/11 19:50:45 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init(t_fdf *fdf, t_data *data, t_map *map)
{
	data->mlx = 0;
	data->win = 0;
	data->img = 0;
	data->addr = 0;
	map->map = 0;
	map->width = 0;
	map->height = 0;
	map->tile_size = 0;
	map->max_z = 0;
	map->min_z = 0;
	fdf->map = map;
	fdf->data = data;
	fdf->points = 0;
}

void	init_keys(t_fdf *fdf, t_key *keys)
{
	keys->cross = 0;
	keys->plus_key = 0;
	keys->minus_key = 0;
	keys->esc_key = 0;
	keys->w_key = 0;
	keys->s_key = 0;
	keys->a_key = 0;
	keys->d_key = 0;
	keys->e_key = 0;
	keys->q_key = 0;
	keys->up_key = 0;
	keys->down_key = 0;
	keys->left_key = 0;
	keys->right_key = 0;
	keys->p_key = 0;
	keys->o_key = 0;
	fdf->keys = keys;
}

void	init_camera(t_camera *camera, t_fdf *fdf)
{
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->off_x = 0;
	camera->off_y = 0;
	fdf->camera = camera;
}
