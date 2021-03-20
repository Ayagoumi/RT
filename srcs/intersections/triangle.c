/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:25:52 by ayagoumi          #+#    #+#             */
/*   Updated: 2021/03/20 19:04:35 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

// double			hit_triangle(t_object *triangle, t_ray *ray)
// {
// 	t_tri		tr;
// 	t_intersect	i;

// 	tr.ca = vect_sub(triangle->point_c, triangle->point_a);
// 	tr.ba = vect_sub(triangle->point_b, triangle->point_a);
// 	tr.orientation = normalize(cross(tr.ca, tr.ba));
// 	tr.distance = dot(tr.orientation, triangle->point_a);
// 	tr.x = vect_sub(ray->origin, triangle->point_a);
// 	tr.a = -1.0 * dot(tr.x, tr.orientation);
// 	tr.b = dot(ray->direction, tr.orientation);
// 	tr.dist2plane = tr.a / tr.b;
// 	tr.q = vect_add(ray->origin, v_c_prod(ray->direction, tr.dist2plane));
// 	tr.ca = vect_sub(triangle->point_c, triangle->point_a);
// 	tr.qa = vect_sub(tr.q, triangle->point_a);
// 	i.t = dot(cross(tr.ca, tr.qa), tr.orientation);
// 	tr.bc = vect_sub(triangle->point_b, triangle->point_c);
// 	tr.qc = vect_sub(tr.q, triangle->point_c);
// 	i.t1 = dot(cross(tr.bc, tr.qc), tr.orientation);
// 	tr.ab = vect_sub(triangle->point_a, triangle->point_b);
// 	tr.qb = vect_sub(tr.q, triangle->point_b);
// 	i.t2 = dot(cross(tr.ab, tr.qb), tr.orientation);
// 	if (i.t >= 0.0 && i.t1 >= 0.0 && i.t2 >= 0.0)
// 		return (slice_obj(*triangle, *ray, tr.dist2plane));
// 	return (-1);
// }

double			hit_triangle(t_object *triangle, t_ray *r)
{
	t_intersect inter;
	t_vect3 origin_minus_v0, cross_raydir_edge2, cross_ori_edge1;
	double det, inv_det;
	double u;
	double v;
	t_tri		tr;

	tr.ca = vect_sub(triangle->point_c, triangle->point_a);
	tr.ba = vect_sub(triangle->point_b, triangle->point_a);
	t_vect3 surface_normal = normalize(cross(tr.ba, tr.ca));
	double i  = dot(r->direction, surface_normal);
	if (i < 0)
	{
		t_vect3 tmp;
		tmp = tr.ba;
		tr.ba = tr.ca;
		tr.ca = tmp;
	}

	cross_raydir_edge2 = cross(r->direction, tr.ba);
	det = dot(tr.ca, cross_raydir_edge2);
	if (det < 0.00001)
		return (-1);

	origin_minus_v0 = vect_sub(r->origin, triangle->point_a);
	u = dot(origin_minus_v0, cross_raydir_edge2);
	if (u < 0.0 || u > det)
		return (-1);

	cross_ori_edge1 = cross(origin_minus_v0, tr.ca);
	v = dot(r->direction, cross_ori_edge1);
	if (v < 0.0 || u + v > det)
		return (-1);

	inter.t = dot(tr.ba, cross_ori_edge1);

	inv_det = 1.0 / det;
	u *= inv_det;
	v *= inv_det;
	inter.t *= inv_det;
	return (inter.t);
}
