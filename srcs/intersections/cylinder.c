/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:49:36 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/23 18:44:39 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

// static int ft_cylinder_cap(t_ray *ray, double *t, t_vect3 pos, t_vect3 n)
// {
// 	float ddn;
// 	float t1;
// 	t_vect3 dist;

// 	ray->ret = 0;
// 	ddn = dot(ray->direction, n);
// 	if (ddn <= 1.0e-6 && ddn >= -1.0e-6)
// 		return (-1.0);
// 	dist = vect_sub(pos, ray->origin);
// 	t1 = (dot(dist, n)) / ddn;
// 	if (t1 >= 0.0)
// 	{
// 		*t = t1;
// 		if (ddn >= 1e-6)
// 		{
// 			ray->ret = 2;
// 			return (2);
// 		}
// 		ray->ret = 1;
// 		return (1);
// 	}
// 	return (0);
// }

// static int ft_cylinder_cap1(t_object *cyl, t_ray *ray, double *t, float m1)
// {
// 	ray->ret = 0;
// 	if (m1 < -cyl->height)
// 		return (0);
// 	if (ft_cylinder_cap(ray, t, v_c_prod(cyl->orientation, -cyl->height), v_c_prod(cyl->orientation, -1.0)))
// 	{
// 		ray->ret = -1;
// 		return (-1);
// 	}
// 	return (0);
// }

// static void limit_calc(t_object *cyl, t_cap *ca, t_ray *ra)
// {
// 	if (cyl->cyl.t1 > cyl->cyl.t2)
// 	{
// 		ca->m0 = cyl->cyl.t1;
// 		cyl->cyl.t1 = cyl->cyl.t2;
// 		cyl->cyl.t2 = ca->m0;
// 	}
// 	ca->m0 = dot(ra->direction, cyl->orientation) * cyl->cyl.t1;
// 	ca->m0 += dot(cyl->cyl.oc, cyl->orientation);
// 	ca->m1 = dot(ra->direction, cyl->orientation) * cyl->cyl.t2;
// 	ca->m1 += dot(cyl->cyl.oc, cyl->orientation);
// 	ra->ret = 0;
// }

// double		limit_calc1(t_object *cyl, t_ray *ray, t_cap cap)
// {
// 	double	t;

// 	limit_calc(cyl, &cap, ray, cyl->cyl.oc);
// 	if (cap.m0 < -cyl->height)
// 	{
// 		if (ft_cylinder_cap1(cyl, ray, &t, cap.m1) && (ray->ret = -1))
// 			return (t);
// 		return (-1.0);
// 	}
// 	else if (cap.m0 >= -cyl->height && cap.m0 <= cyl->height)
// 		return (cyl->cyl.t1 < 1e-6 ? -1.0 : cyl->cyl.t1);
// 	else if (cap.m0 > cyl->height)
// 	{
// 		if (cap.m1 > cyl->height)
// 			return (-1.0);
// 		if (ft_cylinder_cap(ray, &t, v_c_prod(cyl->orientation,\
// 			cyl->height), cyl->orientation))
// 		{
// 			ray->ret = 2;
// 			return (t);
// 		}
// 	}
// 	return (-1.0);
// }

// double		hit_cylinder(t_object *cyl, t_ray *ray)
// {
// 	t_cap	cap;
// 	double	t;

// 	cap.m0 = 0;
// 	cyl->cyl.oc = vect_sub(ray->origin, cyl->position);
// 	cyl->cyl.a = dot(ray->direction, ray->direction) -\
// 	pow(dot(ray->direction, cyl->orientation), 2.0);
// 	cyl->cyl.b = 2.0 * (dot(ray->direction, cyl->cyl.oc) -\
// 	(dot(ray->direction, cyl->orientation) * dot(cyl->cyl.oc, cyl->orientation)));
// 	cyl->cyl.c = dot(cyl->cyl.oc, cyl->cyl.oc) -\
// 	pow(dot(cyl->cyl.oc, cyl->orientation), 2.0) - (cyl->radius * cyl->radius);
// 	cyl->cyl.delta = (cyl->cyl.b * cyl->cyl.b) -\
// 	(4.0 * cyl->cyl.a * cyl->cyl.c);
// 	if (cyl->cyl.delta < 0)
// 		return (-1.0);
// 	cyl->cyl.delta = sqrt(cyl->cyl.delta);
// 	cyl->cyl.t1 = (-cyl->cyl.b + cyl->cyl.delta) /\
// 	(2 * cyl->cyl.a);
// 	cyl->cyl.t2 = (-cyl->cyl.b - cyl->cyl.delta) /\
// 	(2 * cyl->cyl.a);
// 	t = equa_solu(cyl->cyl.a, cyl->cyl.b, cyl->cyl.delta);
// 	if (cyl->height <= 0)
// 		return (slice_obj(*cyl, *ray, t));
// 	return (slice_obj(*cyl, *ray, limit_calc1(cyl, ray, cap)));
// }

static void limit_calc(t_object *cyl, t_cap *ca, t_ray *ra)
{
	if (cyl->cyl.t1 > cyl->cyl.t2)
	{
		ca->m0 = cyl->cyl.t1;
		cyl->cyl.t1 = cyl->cyl.t2;
		cyl->cyl.t2 = ca->m0;
	}
	ca->m0 = dot(ra->direction, cyl->orientation) * cyl->cyl.t1 + dot(cyl->cyl.oc, cyl->orientation);
	ca->m1 = dot(ra->direction, cyl->orientation) * cyl->cyl.t2 + dot(cyl->cyl.oc, cyl->orientation);
}

static double limit_cal(t_object *cyl, t_ray *ray, t_cap cap)
{
	double t;

	limit_calc(cyl, &cap, ray);
	t = cyl->cyl.t;
	if (cap.m0 < -cyl->height)
		return (-1.0);
	else if (cap.m0 >= -cyl->height && cap.m0 <= cyl->height)
		return (cyl->cyl.t1 < 1e-6 ? -1.0 : cyl->cyl.t1);
	else if (cap.m0 > cyl->height)
	{
		if (cap.m1 > cyl->height)
			return (-1.0);
		return (t);
	}
	return (-1.0);
}

double hit_cylinder(t_object *cyl, t_ray *ray)
{
	t_cap cap;

	cap.m0 = 0;
	cyl->cyl.oc = vect_sub(ray->origin, cyl->position);
	cyl->cyl.a = dot(ray->direction, ray->direction) - pow(dot(ray->direction, cyl->orientation), 2.0);
	cyl->cyl.b = 2.0 * (dot(ray->direction, cyl->cyl.oc) - (dot(ray->direction, cyl->orientation) * dot(cyl->cyl.oc, cyl->orientation)));
	cyl->cyl.c = dot(cyl->cyl.oc, cyl->cyl.oc) - pow(dot(cyl->cyl.oc, cyl->orientation), 2.0) - (cyl->radius * cyl->radius);
	cyl->cyl.delta = (cyl->cyl.b * cyl->cyl.b) - (4.0 * cyl->cyl.a * cyl->cyl.c);
	if (cyl->cyl.delta < 0)
		return (-1.0);
	cyl->cyl.delta = sqrt(cyl->cyl.delta);
	cyl->cyl.t1 = (-cyl->cyl.b + cyl->cyl.delta) / (2 * cyl->cyl.a);
	cyl->cyl.t2 = (-cyl->cyl.b - cyl->cyl.delta) / (2 * cyl->cyl.a);
	cyl->cyl.t = equa_solu(cyl->cyl.a, cyl->cyl.b, cyl->cyl.delta);
	if (cyl->height <= 0)
		return (slice_obj(*cyl, *ray, cyl->cyl.t));
	return (slice_obj(*cyl, *ray, limit_cal(cyl, ray, cap)));
}
