/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grey.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:12:05 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/26 08:31:59 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	grey_effect(int *img)
{
	int		i;
	t_col	col;
	t_col	out;

	i = 0;
	while (i < W * H)
	{
		col = int_to_rgb_yatak(img[i]);
		out.r = (col.r * 0.2126) + (col.g * 0.7152) + (col.b * 0.0722);
		out.g = (col.r * 0.2126) + (col.g * 0.7152) + (col.b * 0.0722);
		out.b = (col.r * 0.2126) + (col.g * 0.7152) + (col.b * 0.0722);
		out.r = out.r > 255 ? 255 : out.r;
		out.g = out.g > 255 ? 255 : out.g;
		out.b = out.b > 255 ? 255 : out.b;
		img[i] = rgb_to_int_yatak(out);
		i++;
	}
}

char	*straddbmp(char *str, t_ind ind)
{
	char *tmp;

	tmp = ".bmp";
	ind.i = 0;
	while (tmp[ind.i])
	{
		str[ind.j] = tmp[ind.i];
		ind.j++;
		ind.i++;
	}
	str[ind.j] = '\0';
	return (str);
}
