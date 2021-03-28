/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:36:43 by ayagoumi          #+#    #+#             */
/*   Updated: 2021/03/28 16:50:27 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void			cal_end_cap(t_object *cyl, t_cap *ca, t_ray *r)
{
	double tmp;

	if (cyl->inter.t1 > cyl->inter.t2)
	{
		tmp = cyl->inter.t1;
		cyl->inter.t1 = cyl->inter.t2;
		cyl->inter.t2 = tmp;
	}
	ca->m0 = dot(r->direction, cyl->orientation) * cyl->inter.t1 \
		+ dot(cyl->inter.oc, cyl->orientation);
	ca->m1 = dot(r->direction, cyl->orientation) * cyl->inter.t2 \
		+ dot(cyl->inter.oc, cyl->orientation);
}

static double		calculate_height(t_object *cyl, t_ray *r, t_cap cap)
{
	r->ret = 0;
	if (cyl->height <= 0)
	{
		r->t = cyl->inter.t;
		return (r->t);
	}
	cal_end_cap(cyl, &cap, r);
	if (cap.m0 >= -cyl->height / 2 && cap.m0 <= cyl->height / 2)
	{
		r->ret = 1;
		return (cyl->inter.t1 < 1e-6 ? -1.0 : cyl->inter.t1);
	}
	else if (cap.m1 >= -cyl->height / 2 && cap.m1 <= cyl->height / 2)
	{
		r->ret = 2;
		return (cyl->inter.t2 < 1e-6 ? -1.0 : cyl->inter.t2);
	}
	return (-1);
}

double				hit_cylinder(t_object *cyl, t_ray *r)
{
	t_cap cap;

	cap.m0 = 0;
	cyl->inter.oc = vect_sub(r->origin, cyl->position);
	cyl->inter.a = dot(r->direction, r->direction) \
		- pow(dot(r->direction, cyl->orientation), 2.0);
	cyl->inter.b = 2.0 * (dot(r->direction, cyl->inter.oc) \
		- (dot(r->direction, cyl->orientation) \
			* dot(cyl->inter.oc, cyl->orientation)));
	cyl->inter.c = dot(cyl->inter.oc, cyl->inter.oc) \
		- pow(dot(cyl->inter.oc, cyl->orientation), 2.0) \
			- (cyl->radius * cyl->radius);
	cyl->inter.delta = (cyl->inter.b * cyl->inter.b) \
		- (4.0 * cyl->inter.a * cyl->inter.c);
	if (cyl->inter.delta < 0)
		return (-1.0);
	cyl->inter.delta = sqrt(cyl->inter.delta);
	cyl->inter.t1 = (-cyl->inter.b + cyl->inter.delta) / (2 * cyl->inter.a);
	cyl->inter.t2 = (-cyl->inter.b - cyl->inter.delta) / (2 * cyl->inter.a);
	cyl->inter.t = equa_solu(cyl->inter.a, cyl->inter.b, cyl->inter.delta);
	r->t = calculate_height(cyl, r, cap);
	return (r->t);
}
