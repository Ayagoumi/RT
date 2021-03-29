/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilfunc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:27:51 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/29 09:10:27 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	new_objects2(t_object *n_obj)
{
	n_obj->type = -1;
	n_obj->position = (t_point){0, 0, 0};
	n_obj->point_a = (t_point){0, 0, 0};
	n_obj->point_b = (t_point){0, 0, 0};
	n_obj->point_c = (t_point){0, 0, 0};
	n_obj->point_d = (t_point){0, 0, 0};
	n_obj->orientation = (t_vect3){0, 0, 0};
	n_obj->rotation = (t_vect3){0, 0, 0};
	n_obj->translation = (t_vect3){0, 0, 0};
	n_obj->color = (t_color){0, 0, 0};
	n_obj->slice = (t_point){0, 0, 0};
	n_obj->slice_check = false;
	n_obj->corner[0] = (t_point){0, 0, 0};
	n_obj->corner[1] = (t_point){0, 0, 0};
	n_obj->radius = 0;
	n_obj->radius2 = 0;
	n_obj->radius1 = 0;
	n_obj->angle = 0;
	n_obj->slice_flag = 1;
	n_obj->distance = 0;
	n_obj->height = 0;
}

double	map(double x)
{
	if (x > 100)
		return (100.0);
	else if (x < 0)
		return (0.0);
	return (x);
}

void	stock_slice(t_object *obj, char *str)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(str, ' ');
	while (split[i])
		i++;
	if (i == 3)
	{
		obj->slice = (t_vect3){ft_atod(split[0]),\
		ft_atod(split[1]), ft_atod(split[2])};
		obj->slice_check = true;
		obj->slice = (t_vect3){map(obj->slice.x), map(obj->slice.y), \
			map(obj->slice.z)};
	}
	free_tab2(&split, i);
}

void	stock_matter(t_object *obj, char *str)
{
	if (!ft_strcmp(str, "glass"))
		obj->matter = GLASS;
	else if (!(ft_strcmp(str, "water")))
		obj->matter = WATER;
	else if (!(ft_strcmp(str, "diamond")))
		obj->matter = DIAMOND;
	else if (!(ft_strcmp(str, "mirror")))
		obj->matter = MIRROR;
}

int		cmp_with_objects(char *s, char **tab)
{
	int	i;

	i = 0;
	if (s)
		while (i < LIMIT_ELEMENTS)
		{
			if (!ft_strcmp(s, tab[i]))
				return (i);
			i++;
		}
	return (-1);
}
