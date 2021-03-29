/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 14:23:39 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/29 10:54:27 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H
# include <math.h>
# include <time.h>
# include <stdlib.h>

typedef	struct	s_ind
{
	int		i;
	int		j;
}				t_ind;

typedef	struct	s_col
{
	double	r;
	double	g;
	double	b;
}				t_col;

typedef	struct	s_dist
{
	double	dist;
	double	distance;
	t_col	col1;
	t_col	col2;
	t_ind	ind;
}				t_dist;

typedef struct	s_image
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}				t_image;

int				rgb_to_int_yatak(t_col col);
t_col			int_to_rgb_yatak(int val);
t_col			alpha_compositing(t_col c1, t_col c2, double a1, double a2);
t_col			divide_color(t_col c, double v);
t_col			plus_color(t_col c1, t_col c2);
void			grey_effect(int *img);
void			cartoon_effect(int *img);
void			sepia_effect(int *img);
void			anaglyph_effect(int *img);
void			blur_effect(int *img);
int				compare_color(int c1, int c2);
void			image_create(int *img);
char			*straddbmp(char *str, t_ind ind);

#endif
