/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:50:57 by cgoth             #+#    #+#             */
/*   Updated: 2022/03/14 17:54:05 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	mlx_start(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1280, 720, "fdf");
	data->img = mlx_new_image(data->mlx, 1280, 720);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
			&data->line_length, &data->endian);
}

int	cross_exit(t_fdf *fdf)
{
	mlx_destroy_window(fdf->data->mlx, fdf->data->win);
	clean(fdf);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf		fdf;
	t_data		data;
	t_map		map;
	t_key		keys;
	t_camera	camera;

	if (argc != 2 || wrong_filename(argv[1]))
		error("\e[1;41mERROR ARG\e[0m");
	init(&fdf, &data, &map);
	init_keys(&fdf, &keys);
	parse_map(argv[1], &fdf);
	if (!map.map)
		error("\e[1;41mERROR MAP\e[0m");
	fdf.points = parse_points(&map);
	if (!fdf.points)
		return (0);
	init_camera(&camera, &fdf);
	mlx_start(&data);
	init_hooks(&fdf);
	map.tile_size = ft_min(WIDTH / map.width / 2, HEIGHT / map.height / 2);
	mlx_loop_hook(data.mlx, &draw, &fdf);
	mlx_loop(data.mlx);
	return (0);
}
