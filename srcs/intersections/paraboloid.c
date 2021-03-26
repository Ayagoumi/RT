/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:23 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/25 17:22:44 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double				hit_paraboloid(t_object *para, t_ray *r)
{
	para->inter.oc = vect_sub(r->origin, para->position);
	para->inter.a = dot(r->direction, r->direction) \
					- powf(dot(r->direction, para->orientation), 2);
	para->inter.b = 2 * (dot(r->direction, para->inter.oc) \
			- (dot(r->direction, para->orientation) \
			* (dot(para->inter.oc, para->orientation) + 2 * para->distance)));
	para->inter.c = dot(para->inter.oc, para->inter.oc) \
			- (dot(para->inter.oc, para->orientation) \
			* (dot(para->inter.oc, para->orientation) + 4 * para->distance));
	para->inter.delta = para->inter.b * para->inter.b \
						- (4 * para->inter.a * para->inter.c);
	if (para->inter.delta < 0)
		return (-1);
	para->inter.t1 = (-para->inter.b - sqrt(para->inter.delta)) \
					/ (2 * para->inter.a);
	para->inter.t2 = (-para->inter.b + sqrt(para->inter.delta)) \
					/ (2 * para->inter.a);
	r->t = equa_solu(para->inter.a, para->inter.b, para->inter.delta);
	para->inter.t = r->t;
	return (r->t);
}
