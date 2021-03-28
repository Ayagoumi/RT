/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slicer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:11:10 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/28 19:10:38 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double	slice_xyz(t_object *o, t_ray r, t_vect3 slice, t_point c)
{
	t_point	hit;
	t_vect3	dist;
	double	dot1;
	double	tmp;

	hit = vect_add(r.origin, v_c_prod(r.direction, r.t));
	dist = normalize(vect_sub(hit, c));
	dot1 = dot(dist, slice);
	if (r.t > 0 && dot1 < -EQN_EPS)
	{
		if (o->type != PLANE && o->type != TRIANGLE &&\
		o->inter.delta > 0 && o->inter.t1 > 0 && o->inter.t2 > 0)
		{
			o->slice_flag = -1;
			tmp = r.t == o->inter.t2 ? o->inter.t1 : o->inter.t2;
			hit = vect_add(r.origin, v_c_prod(r.direction, tmp));
			dist = normalize(vect_sub(hit, c));
			if (dot(dist, slice) >= -EQN_EPS)
				return (tmp);
		}
		return (-1.0);
	}
	return (r.t);
}

double	slice_obj(t_object *o, t_ray r, double t)
{
	t_point sl_point;

	sl_point = vect_add(o->position, o->slice);
	o->slice_flag = 1;
	if (t > 0.0 && o->type != TORUS && o->slice_check)
	{
		r.t = t;
		if (o->slice.x > 0 && !(o->radius > 0 && o->slice.x > o->radius))
			r.t = slice_xyz(o, r, (t_vect3){1, 0, 0}, sl_point);
		if (o->slice.y > 0)
			r.t = slice_xyz(o, r, (t_vect3){0, 1, 0}, sl_point);
		if (o->slice.z > 0)
			r.t = slice_xyz(o, r, (t_vect3){0, 0, 1}, sl_point);
		if (o->slice.x < 0 && !(o->radius > 0 && -o->slice.x > o->radius))
			r.t = slice_xyz(o, r, (t_vect3){-1, 0, 0}, sl_point);
		if (o->slice.y < 0)
			r.t = slice_xyz(o, r, (t_vect3){0, -1, 0}, sl_point);
		if (o->slice.z < 0)
			r.t = slice_xyz(o, r, (t_vect3){0, 0, -1}, sl_point);
		return (r.t);
	}
	return (t);
}
