/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:50:56 by cgoth             #+#    #+#             */
/*   Updated: 2022/03/11 19:50:58 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(t_point *p, float alpha)
{
	int	prev_y;

	prev_y = p->y;
	p->y = prev_y * cos(alpha) + p->z * sin(alpha);
	p->z = -prev_y * sin(alpha) + p->z * cos(alpha);
}

void	rotate_y(t_point *p, float beta)
{
	int	prev_x;

	prev_x = p->x;
	p->x = prev_x * cos(beta) + p->z * sin(beta);
	p->z = -prev_x * sin(beta) + p->z * cos(beta);
}

void	rotate_z(t_point *p, float gamma)
{
	int	prev_x;
	int	prev_y;

	prev_x = p->x;
	prev_y = p->y;
	p->x = prev_x * cos(gamma) - p->y * sin(gamma);
	p->y = prev_x * sin(gamma) + p->y * cos(gamma);
}

void	rotate(t_key *keys, t_camera *camera)
{
	if (keys->w_key)
		camera->alpha += 0.05;
	if (keys->s_key)
		camera->alpha -= 0.05;
	if (keys->a_key)
		camera->beta += 0.05;
	if (keys->d_key)
		camera->beta -= 0.05;
	if (keys->e_key)
		camera->gamma += 0.05;
	if (keys->q_key)
		camera->gamma -= 0.05;
}

void	translate(t_key *keys, t_camera *camera)
{
	if (keys->up_key)
		camera->off_y -= 5;
	if (keys->down_key)
		camera->off_y += 5;
	if (keys->right_key)
		camera->off_x += 5;
	if (keys->left_key)
		camera->off_x -= 5;
}
