/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:01:30 by cgoth             #+#    #+#             */
/*   Updated: 2022/03/11 17:01:32 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_down_2(int keycode, t_key *keys)
{
	if (keycode == 126)
		keys->up_key = 1;
	if (keycode == 125)
		keys->down_key = 1;
	if (keycode == 124)
		keys->right_key = 1;
	if (keycode == 123)
		keys->left_key = 1;
}

static void	key_up_2(int keycode, t_key *keys)
{
	if (keycode == 126)
		keys->up_key = 0;
	if (keycode == 125)
		keys->down_key = 0;
	if (keycode == 124)
		keys->right_key = 0;
	if (keycode == 123)
		keys->left_key = 0;
}

static int	key_down(int keycode, t_key *keys)
{
	if (keycode == 53)
		keys->esc_key = 1;
	if (keycode == 24)
		keys->plus_key = 1;
	if (keycode == 27)
		keys->minus_key = 1;
	if (keycode == 13)
		keys->w_key = 1;
	if (keycode == 1)
		keys->s_key = 1;
	if (keycode == 0)
		keys->a_key = 1;
	if (keycode == 2)
		keys->d_key = 1;
	if (keycode == 14)
		keys->e_key = 1;
	if (keycode == 12)
		keys->q_key = 1;
	if (keycode == 35)
		keys->p_key = 1;
	if (keycode == 31)
		keys->o_key = 1;
	if (keycode > 100)
		key_down_2(keycode, keys);
	return (0);
}

static int	key_up(int keycode, t_key *keys)
{
	if (keycode == 24)
		keys->plus_key = 0;
	if (keycode == 27)
		keys->minus_key = 0;
	if (keycode == 13)
		keys->w_key = 0;
	if (keycode == 1)
		keys->s_key = 0;
	if (keycode == 0)
		keys->a_key = 0;
	if (keycode == 2)
		keys->d_key = 0;
	if (keycode == 14)
		keys->e_key = 0;
	if (keycode == 12)
		keys->q_key = 0;
	if (keycode == 35)
		keys->p_key = 0;
	if (keycode == 31)
		keys->o_key = 0;
	if (keycode > 100)
		key_up_2(keycode, keys);
	return (0);
}

void	init_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->data->win, 17, 0, cross_exit, fdf);
	mlx_hook(fdf->data->win, 2, 0, key_down, fdf->keys);
	mlx_hook(fdf->data->win, 3, 0, key_up, fdf->keys);
}
