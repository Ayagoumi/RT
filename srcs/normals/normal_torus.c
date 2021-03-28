/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_torus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 08:48:56 by ayagoumi          #+#    #+#             */
/*   Updated: 2021/03/28 18:25:54 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3			torus_normal(t_object *obj, t_ray *ray)
{
	t_vect3 h;
	t_vect3 n;
	double	m;
	t_vect3	a_vect;
	double	k;

	ray->t = obj->inter.t;
	h = vect_add(ray->origin, v_c_prod(ray->direction, obj->inter.t));
	k = dot(h, obj->orientation);
	a_vect = vect_sub(h, v_c_prod(obj->orientation, k));
	m = sqrt(powf(obj->radius2, 2) - powf(k, 2));
	n = normalize(vect_sub(h, vect_sub(a_vect, \
		v_c_prod(vect_sub(ray->origin, a_vect), m / (obj->radius1 + m)))));
	return (n);
}
