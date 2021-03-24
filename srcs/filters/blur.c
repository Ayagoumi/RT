/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blur.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:27:21 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/24 16:24:20 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	blur_effect(int *img)
{
	t_ind		ind;
	t_col		col;
	t_col		sum;

	ind.i = 0;
	while (ind.i < W * H)
	{
		ind.j = 1;
		sum = int_to_rgb_yatak(img[ind.i]);
		while (ind.j < 30)
		{
			if (ind.i + ind.j < W * H)
				col = int_to_rgb_yatak(img[ind.i + ind.j]);
			sum = plus_color(sum, col);
			ind.j++;
		}
		sum = divide_color(sum, 30.0);
		img[ind.i] = rgb_to_int_yatak(sum);
		ind.i++;
	}
}
