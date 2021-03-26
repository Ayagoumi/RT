/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:36:43 by ayagoumi          #+#    #+#             */
/*   Updated: 2021/03/26 13:12:39 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void limit_calc(t_object *cyl, t_cap *ca, t_ray *ra)
{
	if (cyl->inter.t1 > cyl->inter.t2)
	{
		ca->m0 = cyl->inter.t1;
		cyl->inter.t1 = cyl->inter.t2;
		cyl->inter.t2 = ca->m0;
	}
	ca->m0 = dot(ra->direction, cyl->orientation) * cyl->inter.t1 + dot(cyl->inter.oc, cyl->orientation);
	ca->m1 = dot(ra->direction, cyl->orientation) * cyl->inter.t2 + dot(cyl->inter.oc, cyl->orientation);
}

static double limit_cal(t_object *cyl, t_ray *ray, t_cap cap)
{
	double t;

	limit_calc(cyl, &cap, ray);
	t = cyl->inter.t;
	if (cap.m0 < -cyl->height)
		return (-1.0);
	else if (cap.m0 >= -cyl->height && cap.m0 <= cyl->height)
		return (cyl->inter.t1 < 1e-6 ? -1.0 : cyl->inter.t1);
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
	cyl->inter.oc = vect_sub(ray->origin, cyl->position);
	cyl->inter.a = dot(ray->direction, ray->direction) - pow(dot(ray->direction, cyl->orientation), 2.0);
	cyl->inter.b = 2.0 * (dot(ray->direction, cyl->inter.oc) - (dot(ray->direction, cyl->orientation) * dot(cyl->inter.oc, cyl->orientation)));
	cyl->inter.c = dot(cyl->inter.oc, cyl->inter.oc) - pow(dot(cyl->inter.oc, cyl->orientation), 2.0) - (cyl->radius * cyl->radius);
	cyl->inter.delta = (cyl->inter.b * cyl->inter.b) - (4.0 * cyl->inter.a * cyl->inter.c);
	if (cyl->inter.delta < 0)
		return (-1.0);
	cyl->inter.delta = sqrt(cyl->inter.delta);
	cyl->inter.t1 = (-cyl->inter.b + cyl->inter.delta) / (2 * cyl->inter.a);
	cyl->inter.t2 = (-cyl->inter.b - cyl->inter.delta) / (2 * cyl->inter.a);
	cyl->inter.t = equa_solu(cyl->inter.a, cyl->inter.b, cyl->inter.delta);
	if (cyl->height <= 0)
		return (cyl->inter.t);
	return (limit_cal(cyl, ray, cap));
}
