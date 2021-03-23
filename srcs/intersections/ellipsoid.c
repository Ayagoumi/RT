/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:02 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/22 15:09:49 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double calc_solv(t_intersect *i, t_ray *ray)
{
	i->t1 = (-i->b + i->delta) / (2 * i->a);
	i->t2 = (-i->b - i->delta) / (2 * i->a);
	if (((i->t1 < i->t2 || i->t2 < 0.001) && i->t1 > 0.1))
	{
		ray->t = i->t1;
		return (i->t1);
	}
	else if (((i->t2 < i->t1 || i->t1 < 0.001) && i->t2 > 0.1))
	{
		ray->t = i->t2;
		return (i->t2);
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
	double t;
	double radius;

	elip->elip.oc = vect_sub(r->origin, elip->position);
	radius = elip->radius1 + elip->radius2;
	double A1 = 2 * elip->distance * dot(r->direction, elip->orientation);
	double A2 = powf(radius, 2) + 2 * elip->distance * dot(elip->elip.oc, elip->orientation) - elip->distance;
	elip->elip.a = 4 * powf(radius, 2) * dot(r->direction, r->direction) - A1 * A1;
	elip->elip.b = 2 * 4 * powf(radius, 2) * dot(r->direction, elip->elip.oc) - A1 * A2;
	elip->elip.c = 4 * powf(radius, 2) * dot(elip->elip.oc, elip->elip.oc) - A2 * A2;
	elip->elip.delta = elip->elip.b * elip->elip.b - 4 * elip->elip.a * elip->elip.c;
	if (elip->elip.delta < 0)
		return (-1);
	elip->elip.delta = sqrtf(elip->elip.delta);
	if (elip->elip.delta < 0)
		return (-1);
	t = calc_solv(&elip->elip, r);
	return (slice_obj(*elip, *r, calc_solv(&elip->elip, r)));
}
