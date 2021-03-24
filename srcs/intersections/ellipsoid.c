/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:02 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/24 14:14:00 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double calc_solv(t_object *elip, t_ray *ray)
{
	elip->inter.t1 = (-elip->inter.b + elip->inter.delta) / (2 * elip->inter.a);
	elip->inter.t2 = (-elip->inter.b - elip->inter.delta) / (2 * elip->inter.a);
	if (((elip->inter.t1 < elip->inter.t2 || elip->inter.t2 < 0.001) && elip->inter.t1 > 0.1))
	{
		ray->t = elip->inter.t1;
		return (elip->inter.t1);
	}
	else if (((elip->inter.t2 < elip->inter.t1 || elip->inter.t1 < 0.001) && elip->inter.t2 > 0.1))
	{
		ray->t = elip->inter.t2;
		return (elip->inter.t2);
	}
	return (-1);
}

// double			hit_ellipsoid(t_object *elip, t_ray *ray)
// {
// 	t_vect3		x;
// 	t_intersect	i;
// 	double		r;
// 	double		a1;
// 	double		a2;

// 	x = vect_sub(ray->origin, elip->position);
// 	r = elip->radius1 + elip->radius2;
// 	a1 = 2.0 * elip->distance * dot(ray->direction, elip->orientation);
// 	a2 = (r * r) + (2.0 * elip->distance *\
// 		dot(x, elip->orientation)) - elip->distance;
// 	i.a = (4.0 * r * r * dot(ray->direction, ray->direction)) - a1 * a1;
// 	i.b = 2.0 * (4.0 * r * r * dot(ray->direction, x)) - (a1 * a2);
// 	i.c = (4.0 * r * r * dot(x, x)) - a2 * a2;
// 	i.delta = (i.b * i.b) - (4.0 * i.a * i.c);
// 	if (i.delta < 0)
// 		return (-1);
// 	i.delta = sqrtf(i.delta);
// 	if (i.delta < 0)
// 		return (-1);
// 	return (slice_obj(*elip, *ray, calc_solv(&i, ray)));
// }

double hit_ellipsoid(t_object *elip, t_ray *r)
{
	// double t;
	double radius;
	double a1;
	double a2;

	elip->inter.oc = vect_sub(r->origin, elip->position);
	radius = elip->radius1 + elip->radius2;
	a1 = 2 * elip->distance * dot(r->direction, elip->orientation);
	a2 = powf(radius, 2) + 2 * elip->distance * dot(elip->inter.oc, elip->orientation) - elip->distance;
	elip->inter.a = 4 * powf(radius, 2) * dot(r->direction, r->direction) - a1 * a1;
	elip->inter.b = 2 * 4 * powf(radius, 2) * dot(r->direction, elip->inter.oc) - a1 * a2;
	elip->inter.c = 4 * powf(radius, 2) * dot(elip->inter.oc, elip->inter.oc) - a2 * a2;
	elip->inter.delta = elip->inter.b * elip->inter.b - 4 * elip->inter.a * elip->inter.c;
	if (elip->inter.delta < 0)
		return (-1);
	elip->inter.delta = sqrtf(elip->inter.delta);
	if (elip->inter.delta < 0)
		return (-1);
	elip->inter.t = calc_solv(elip, r);
	return (slice_obj(*elip, *r, calc_solv(elip, r)));
}
