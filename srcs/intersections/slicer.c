/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slicer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 16:11:10 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/28 17:13:08 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double	slice_obj(t_object *o, t_ray r, double t)
{
	t_point hit;
	t_vect3 dist;
	t_vect3 slice;
	double	dot1;
	double	tmp;

	o->slice_flag = 1;
	if (t > 0.0 && 0)
	{
		o->slice = (t_vect3){1.0, 0.0, 0.0};
		if (o->type == SPHERE || o->type == TORUS || o->type == TRIANGLE)
			o->orientation = (t_vect3){0.0, 1.0, 0.0};
		slice = vect_prod((t_vect3){90, 90, 90}, normalize(o->slice));
		hit = vect_add(r.origin, v_c_prod(r.direction, t));
		dist = normalize(vect_sub(hit, o->position));
		dot1 = dot(dist, o->slice);
		if (dot1 < -EQN_EPS)
		{
			if (o->inter.delta > 0 && o->inter.t1 > 0 && o->inter.t2 > 0)
			{
				o->slice_flag = -1;
				tmp = t == o->inter.t2 ? o->inter.t1 : o->inter.t2;
				hit = vect_add(r.origin, v_c_prod(r.direction, tmp));
				dist = normalize(vect_sub(hit, o->position));
				if (dot(dist, o->slice) >= -EQN_EPS)
					return (tmp);
			}
			return (-1.0);
		}
	}
	return (t);
}
