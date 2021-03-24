/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartoon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:09:12 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/24 17:02:10 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int		*ft_tableu_color_2(int *tab)
{
	tab[26] = 0xF0F3F4;
	tab[27] = 0xDC7633;
	tab[28] = 0xEB984E;
	tab[29] = 0xF5B041;
	tab[30] = 0xF4D03F;
	tab[31] = 0x58D68D;
	tab[32] = 0x52BE80;
	tab[33] = 0x45B39D;
	tab[34] = 0x48C9B0;
	tab[35] = 0x5DADE2;
	tab[36] = 0x5499C7;
	tab[37] = 0xA569BD;
	tab[38] = 0xAF7AC5;
	tab[39] = 0xCD6155;
	tab[40] = 0xf2f4f4;
	tab[41] = 0x839192;
	tab[42] = 0x95a5a6;
	tab[43] = 0xaab7b8;
	tab[44] = 0x424949;
	tab[45] = 0xeaecee;
	tab[46] = 0x2e4053;
	tab[47] = 0x2c3e50;
	tab[48] = 0x5d6d7e;
	tab[49] = 0x17202a;
	return (tab);
}

int		*ft_tableu_color_1(int *tab)
{
	tab[2] = 0x424949;
	tab[3] = 0xCD6155;
	tab[4] = 0x626567;
	tab[5] = 0x7B7D7D;
	tab[6] = 0x6E2C00;
	tab[7] = 0x784212;
	tab[8] = 0x7E5109;
	tab[9] = 0x7D6608;
	tab[10] = 0x186A3B;
	tab[11] = 0x145A32;
	tab[12] = 0x0B5345;
	tab[13] = 0x0E6251;
	tab[14] = 0x1B4F72;
	tab[15] = 0x154360;
	tab[16] = 0x512E5F;
	tab[17] = 0x78281F;
	tab[18] = 0x641E16;
	tab[19] = 0x566573;
	tab[20] = 0x5D6D7E;
	tab[21] = 0x99A3A4;
	tab[22] = 0xAAB7B8;
	tab[23] = 0xCACFD2;
	tab[24] = 0xAAB7B8;
	tab[25] = 0xCACFD2;
	return (ft_tableu_color_2(tab));
}

int		*ft_tableu_color(void)
{
	int		*tab;

	if (!(tab = (int *)malloc(sizeof(int) * 50)))
		return (NULL);
	tab[0] = 0x17202A;
	tab[1] = 0x1B2631;
	return (ft_tableu_color_1(tab));
}

t_col	alpha_compositing(t_col c1, t_col c2, double a1, double a2)
{
	t_col	col;
	double	alpha;

	alpha = a2 + a1 * (1.0 - a2);
	col.r = (c2.r * a2 + c1.r * a1 * (1 - a2)) / alpha;
	col.g = (c2.g * a2 + c1.g * a1 * (1 - a2)) / alpha;
	col.b = (c2.b * a2 + c1.b * a1 * (1 - a2)) / alpha;
	return (col);
}

void	cartoon_effect(int *img)
{
	int		*tab;
	t_dist	dist;

	tab = ft_tableu_color();
	dist.ind.i = -1;
	while (++dist.ind.i < W * H)
	{
		if (img[dist.ind.i] == 0)
			continue ;
		dist.col1 = int_to_rgb_yatak(img[dist.ind.i]);
		dist.dist = INFINITY;
		dist.ind.j = -1;
		while (++dist.ind.j < 50)
		{
			dist.col2 = int_to_rgb_yatak(tab[dist.ind.j]);
			dist.distance = sqrt(pow(dist.col2.r - dist.col1.r, 2) +\
	pow(dist.col2.g - dist.col1.g, 2) + pow(dist.col2.b - dist.col1.b, 2));
			if (dist.distance < dist.dist)
			{
				dist.dist = dist.distance;
				img[dist.ind.i] = tab[dist.ind.j];
			}
		}
	}
	free(tab);
}
