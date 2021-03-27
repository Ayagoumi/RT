/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ellipsoid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:02 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/26 18:20:59 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double	calc_solv(t_object *elip, t_ray *r)
{
	elip->inter.t1 = (-elip->inter.b + elip->inter.delta) \
		/ (2 * elip->inter.a);
	elip->inter.t2 = (-elip->inter.b - elip->inter.delta) \
		/ (2 * elip->inter.a);
	if (((elip->inter.t1 < elip->inter.t2 || elip->inter.t2 < 0.001) \
		&& elip->inter.t1 > 0.1))
		return (r->t = elip->inter.t1);
	else if (((elip->inter.t2 < elip->inter.t1 || elip->inter.t1 < 0.001) \
		&& elip->inter.t2 > 0.1))
		return (r->t = elip->inter.t2);
	return (-1);
}

double	hit_ellipsoid(t_object *elip, t_ray *r)
{
	double radius;
	double a1;
	double a2;

	elip->inter.oc = vect_sub(r->origin, elip->position);
	radius = elip->radius1 + elip->radius2;
	a1 = 2 * elip->distance * dot(r->direction, elip->orientation);
	a2 = powf(radius, 2) + 2 * elip->distance \
		* dot(elip->inter.oc, elip->orientation) - elip->distance;
	elip->inter.a = 4 * powf(radius, 2) \
		* dot(r->direction, r->direction) - a1 * a1;
	elip->inter.b = 2 * 4 * powf(radius, 2) \
		* dot(r->direction, elip->inter.oc) - a1 * a2;
	elip->inter.c = 4 * powf(radius, 2) \
		* dot(elip->inter.oc, elip->inter.oc) - a2 * a2;
	elip->inter.delta = elip->inter.b \
		* elip->inter.b - 4 * elip->inter.a * elip->inter.c;
	if (elip->inter.delta < 0)
		return (r->t = -1);
	elip->inter.delta = sqrtf(elip->inter.delta);
	if (elip->inter.delta < 0)
		return (r->t = -1);
	elip->inter.t = calc_solv(elip, r);
	return (r->t = calc_solv(elip, r));
}
