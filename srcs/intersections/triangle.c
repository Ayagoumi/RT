/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:25:52 by ayagoumi          #+#    #+#             */
/*   Updated: 2021/03/26 18:21:57 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void		swap_vect(t_object *triangle, t_ray *r)
{
	t_vect3	tmp;

	triangle->tri.surface_normal = \
		normalize(cross(triangle->tri.ba, triangle->tri.ca));
	triangle->tri.distance = dot(r->direction, triangle->tri.surface_normal);
	if (triangle->tri.distance < 0)
	{
		tmp = triangle->tri.ba;
		triangle->tri.ba = triangle->tri.ca;
		triangle->tri.ca = tmp;
	}
}

double			hit_triangle(t_object *triangle, t_ray *r)
{
	double		u;
	double		v;

	triangle->tri.ca = vect_sub(triangle->point_c, triangle->point_a);
	triangle->tri.ba = vect_sub(triangle->point_b, triangle->point_a);
	swap_vect(triangle, r);
	triangle->tri.pvec = cross(r->direction, triangle->tri.ba);
	triangle->tri.det = dot(triangle->tri.ca, triangle->tri.pvec);
	if (triangle->tri.det < EPSILLON)
		return (-1);
	triangle->tri.tvec = vect_sub(r->origin, triangle->point_a);
	u = dot(triangle->tri.tvec, triangle->tri.pvec);
	if (u < 0.0 || u > triangle->tri.det)
		return (-1);
	triangle->tri.qvec = cross(triangle->tri.tvec, triangle->tri.ca);
	v = dot(r->direction, triangle->tri.qvec);
	if (v < 0.0 || u + v > triangle->tri.det)
		return (-1);
	triangle->inter.t = dot(triangle->tri.ba, triangle->tri.qvec);
	triangle->tri.inv_det = 1.0 / triangle->tri.det;
	u *= triangle->tri.inv_det;
	v *= triangle->tri.inv_det;
	triangle->inter.t *= triangle->tri.inv_det;
	return (r->t = triangle->inter.t);
}
