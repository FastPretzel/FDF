/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:43:08 by cgoth             #+#    #+#             */
/*   Updated: 2022/03/11 20:43:11 by cgoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <limits.h>
//#include <stdio.h>
# define DEF =
# define BUFFER_SIZE 10
# define HEIGHT 720
# define WIDTH 1280

typedef struct s_key
{
	int	cross;
	int	plus_key;
	int	minus_key;
	int	esc_key;
	int	w_key;
	int	s_key;
	int	a_key;
	int	d_key;
	int	e_key;
	int	q_key;
	int	up_key;
	int	down_key;
	int	left_key;
	int	right_key;
	int	p_key;
	int	o_key;
}	t_key;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	double	tile_size;
	int		max_z;
	int		min_z;
}	t_map;

typedef struct s_camera
{
	double	off_x;
	double	off_y;
	float	alpha;
	float	beta;
	float	gamma;
}	t_camera;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned int	color;
}	t_point;

typedef struct s_draw
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_draw;

typedef struct s_prev
{
	int		x;
	int		y;
	float	a;
	float	b;
	float	g;
}	t_prev;

typedef struct s_fdf
{
	t_data		*data;
	t_map		*map;
	t_point		**points;
	t_key		*keys;
	t_camera	*camera;
}	t_fdf;

void	error(char *str);
char	*get_next_line(int fd);
char	*free_all(char **s1, char **s2);
int		find_n(char *s);
size_t	ft_strlen(const char *s);
void	free_cache(char **s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	cache_gen(char **buf, char **cache, int r);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
void	parse_map(char *file, t_fdf *fdf);
int		ft_atoi(char *nptr);
void	clean(t_fdf *fdf);
t_point	**parse_points(t_map *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		draw(t_fdf *fdf);
void	free_split(char **split);
int		cross_exit(t_fdf *fdf);
int		ft_min(int x, int y);
void	rotate(t_key *keys, t_camera *camera);
void	translate(t_key *keys, t_camera *camera);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		wrong_filename(char *name);
void	rotate_x(t_point *p, float alpha);
void	rotate_y(t_point *p, float beta);
void	rotate_z(t_point *p, float gamma);
void	init(t_fdf *fdf, t_data *data, t_map *map);
void	init_keys(t_fdf *fdf, t_key *keys);
void	init_camera(t_camera *camera, t_fdf *fdf);
void	init_hooks(t_fdf *fdf);
char	*to_upper(char *str);
void	zoom(t_fdf *fdf);
void	reset_img(t_fdf *fdf);
t_point	init_point(t_point p, t_fdf *fdf);

#endif
