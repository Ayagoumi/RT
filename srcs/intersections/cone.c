/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:47:25 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/26 18:19:23 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static double		ft_cone_init(t_object *cne, t_ray *r)
{
	cne->inter.a = pow(dot(r->direction, cne->orientation), 2) -\
		pow(cos(cne->angle), 2.0);
	cne->inter.oc = vect_sub(r->origin, cne->position);
	cne->inter.b = 2 * (dot(r->direction, cne->orientation) *\
	(dot(cne->inter.oc, cne->orientation)) - dot(r->direction, cne->inter.oc) *\
			pow(cos(cne->angle), 2.0));
	cne->inter.c = (pow(dot(cne->inter.oc, cne->orientation), 2) -\
		dot(cne->inter.oc, cne->inter.oc) * pow(cos(cne->angle), 2.0));
	cne->inter.delta = cne->inter.b * cne->inter.b \
		- 4.0 * cne->inter.a * cne->inter.c;
	if (cne->inter.delta < 0.00001)
		return (-1.0);
	if (cne->height <= 0)
		return (equa_solu(cne->inter.a, cne->inter.b, cne->inter.delta));
	cne->inter.t1 = (-cne->inter.b - sqrt(cne->inter.delta)) \
		/ (2 * cne->inter.a);
	cne->inter.t2 = (-cne->inter.b + sqrt(cne->inter.delta)) \
		/ (2 * cne->inter.a);
	if ((cne->inter.t1 <= cne->inter.t2 && cne->inter.t1 >= 0.0) \
		|| (cne->inter.t1 >= 0.0 && cne->inter.t2 < 0.0))
		return (cne->inter.t = cne->inter.t1);
	else if ((cne->inter.t2 <= cne->inter.t1 && cne->inter.t2 >= 0.0) \
		|| (cne->inter.t2 >= 0.0 && cne->inter.t1 < 0.0))
		return (cne->inter.t = cne->inter.t2);
	return (-1);
}

double				hit_cone(t_object *c, t_ray *r)
{
	double		m;
	double		t;

	t = ft_cone_init(c, r);
	m = dot(r->direction, c->orientation) * t \
		+ dot(c->inter.oc, c->orientation);
	if (m < 0 || m > c->height)
		return (r->t = -1.0);
	return (r->t = t);
}
