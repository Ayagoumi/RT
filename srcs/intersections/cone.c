/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:47:25 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/22 12:40:28 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

// static void		ft_cone_init(t_cone *cone, t_object *o, t_ray *r)
// {
// 	double		a;
// 	double		b;
// 	double		c;
// 	t_vect3		x;

// 	a = pow(dot(r->direction, o->orientation), 2) -\
// 		pow(cos(o->angle), 2.0);
// 	x = vect_sub(r->origin, o->position);
// 	b = 2 * (dot(r->direction, o->orientation) *\
// 		(dot(x, o->orientation)) - dot(r->direction, x) *\
// 			pow(cos(o->angle), 2.0));
// 	c = (pow(dot(x, o->orientation), 2) -\
// 		dot(x, x) * pow(cos(o->angle), 2.0));
// 	cone->d.a = a;
// 	cone->d.b = b;
// 	cone->d.c = c;
// 	cone->d.delta = cone->d.b * cone->d.b - 4.0 * cone->d.a * cone->d.c;
// }

// double			hit_cone(t_object *c, t_ray *r)
// {
// 	t_cone		a;
// 	t_vect3		cp;
// 	float		h;
// 	t_intersect	i;

// 	ft_cone_init(&a, c, r);
// 	if (a.d.delta < 0.00001)
// 		return (-1.0);
// 	if (c->height <= 0)
// 		return (equa_solu(a.d.a, a.d.b, a.d.delta));
// 	i.t = 0.0001;
// 	i.t1 = (-a.d.b - sqrt(a.d.delta)) / (2 * a.d.a);
// 	i.t2 = (-a.d.b + sqrt(a.d.delta)) / (2 * a.d.a);
// 	if ((i.t1 <= i.t2 && i.t1 >= 0.0) || (i.t1 >= 0.0 && i.t2 < 0.0))
// 		i.t = i.t1;
// 	else if ((i.t2 <= i.t1 && i.t2 >= 0.0) || (i.t2 >= 0.0 && i.t1 < 0.0))
// 		i.t = i.t2;
// 	else
// 		return (-1);
// 	cp = vect_add(r->origin, v_c_prod(r->direction, (i.t)));
// 	h = dot(cp, c->orientation);
// 	if (h < 0 || h > c->height)
// 		return (-1.0);
// 	return (slice_obj(*c, *r, i.t));
// }

static double		ft_cone_init(t_object *cne, t_ray *r)
{
	// double		a;
	// double		b;
	// double		c;
	// t_vect3		x;

	cne->cne.a = pow(dot(r->direction, cne->orientation), 2) -\
		pow(cos(cne->angle), 2.0);
	cne->cne.oc = vect_sub(r->origin, cne->position);
	cne->cne.b = 2 * (dot(r->direction, cne->orientation) *\
		(dot(cne->cne.oc, cne->orientation)) - dot(r->direction, cne->cne.oc) *\
			pow(cos(cne->angle), 2.0));
	cne->cne.c = (pow(dot(cne->cne.oc, cne->orientation), 2) -\
		dot(cne->cne.oc, cne->cne.oc) * pow(cos(cne->angle), 2.0));
	cne->cne.delta = cne->cne.b * cne->cne.b - 4.0 * cne->cne.a * cne->cne.c;
	if (cne->cne.delta < 0.00001)
		return (-1.0);
	if (cne->height <= 0)
		return (equa_solu(cne->cne.a, cne->cne.b, cne->cne.delta));
	// cne->cne.t = 0.0001;
	cne->cne.t1 = (-cne->cne.b - sqrt(cne->cne.delta)) / (2 * cne->cne.a);
	cne->cne.t2 = (-cne->cne.b + sqrt(cne->cne.delta)) / (2 * cne->cne.a);
	if ((cne->cne.t1 <= cne->cne.t2 && cne->cne.t1 >= 0.0) \
		|| (cne->cne.t1 >= 0.0 && cne->cne.t2 < 0.0))
		return (cne->cne.t = cne->cne.t1);
	else if ((cne->cne.t2 <= cne->cne.t1 && cne->cne.t2 >= 0.0) \
		|| (cne->cne.t2 >= 0.0 && cne->cne.t1 < 0.0))
		return (cne->cne.t = cne->cne.t2);
	return (-1);
}

double			hit_cone(t_object *c, t_ray *r)
{
	// t_cone		a;
	// t_vect3		cp;
	// float		h;
	// t_intersect	i;
	double		m;
	double		t;

	t = ft_cone_init(c, r);
	// cp = vect_add(r->origin, v_c_prod(r->direction, (i.t)));
	// h = dot(cp, c->orientation);
	m = dot(r->direction, c->orientation) * t + dot(c->cne.oc, c->orientation);
	if (m < 0 || m > c->height)
		return (-1.0);
	return (slice_obj(*c, *r, t));
}
