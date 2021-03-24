/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:58:48 by yoouali           #+#    #+#             */
/*   Updated: 2021/03/24 17:01:47 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/image.h"

t_col	int_to_rgb_yatak(int val)
{
	t_col	col;

	col.r = (val >> 16) & 255;
	col.g = (val >> 8) & 255;
	col.b = val & 255;
	return (col);
}

int		rgb_to_int_yatak(t_col col)
{
	return ((int)(col.r) << 16 | (int)(col.g) << 8 | (int)(col.b));
}

t_col	plus_color(t_col c1, t_col c2)
{
	t_col	col;

	col.r = c1.r + c2.r;
	col.g = c1.g + c2.g;
	col.b = c1.b + c2.b;
	return (col);
}

t_col	divide_color(t_col c, double v)
{
	t_col	col;

	col.r = c.r / v;
	col.g = c.g / v;
	col.b = c.b / v;
	return (col);
}

int		compare_color(int c1, int c2)
{
	t_col	col1;
	t_col	col2;

	col1 = int_to_rgb_yatak(c1);
	col2 = int_to_rgb_yatak(c2);
	if (col1.r == col2.r && col1.g == col2.g && col1.b == col2.b)
		return (1);
	return (0);
}
