/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:12:57 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/24 16:58:10 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	sepia_effect(int *img)
{
	int		i;
	t_col	col;
	t_col	out;

	i = 0;
	while (i < W * H)
	{
		col = int_to_rgb_yatak(img[i]);
		out.r = (col.r * 0.393) + (col.g * 0.769) + (col.b * 0.189);
		out.g = (col.r * 0.349) + (col.g * 0.686) + (col.b * 0.168);
		out.b = (col.r * 0.272) + (col.g * 0.534) + (col.b * 0.131);
		out.r = out.r > 255 ? 255 : out.r;
		out.g = out.g > 255 ? 255 : out.g;
		out.b = out.b > 255 ? 255 : out.b;
		img[i] = rgb_to_int_yatak(out);
		i++;
	}
}
