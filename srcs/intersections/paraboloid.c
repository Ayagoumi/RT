/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:23 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/19 16:08:47 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

// double				calc_the_t(t_intersect *i, t_ray *ray)
// {
// 	i->t1 = (-i->b + i->delta) / (2 * i->a);
// 	i->t2 = (-i->b - i->delta) / (2 * i->a);
// 	if (((i->t1 < i->t2 || i->t2 < 0.001) && i->t1 > 0.1))
// 	{
// 		ray->t = i->t1;
// 		return (i->t1);
// 	}
// 	else if (((i->t2 < i->t1 || i->t1 < 0.001) && i->t2 > 0.1))
// 	{
// 		ray->t = i->t2;
// 		return (i->t2);
// 	}
// 	return (-1.0);
// }

// double				hit_paraboloid(t_object *pa, t_ray *ray)
// {
// 	t_vect3		x;
// 	t_intersect	i;

// 	x = vect_sub(ray->origin, pa->position);
// 	i.a = dot(ray->direction, ray->direction) -\
// 		powf(dot(ray->direction, pa->orientation), 2.0);
// 	i.b = 2.0 * (dot(ray->direction, x) -\
// 		dot(ray->direction, v_c_prod(pa->orientation,\
// 		(dot(x, pa->orientation) + (2.0 * pa->distance)))));
// 	i.c = dot(x, x) - dot(x,\
// 		v_c_prod(pa->orientation, (dot(x, pa->orientation) +\
// 		(4.0 * pa->distance))));
// 	i.delta = (i.b * i.b) - (4.0 * i.a * i.c);
// 	if (i.delta < 0)
// 		return (-1.0);
// 	i.delta = sqrtf(i.delta);
// 	return (slice_obj(*pa, *ray, calc_the_t(&i, ray)));
// }

double				hit_paraboloid(t_object *pa, t_ray *r)
{
	t_intersect	i;

    i.oc = vect_sub(r->origin, pa->position);
    i.a = dot(r->direction, r->direction) - powf(dot(r->direction, pa->orientation), 2);
    i.b = 2 * (dot(r->direction, i.oc) - (dot(r->direction,pa->orientation) * (dot(i.oc, pa->orientation) + 2 * pa->distance)));
    i.c = dot(i.oc, i.oc) - (dot(i.oc, pa->orientation) * (dot(i.oc, pa->orientation) + 4 * pa->distance));
    i.delta = i.b * i.b - (4 * i.a * i.c);
    if (i.delta < 0)
        return (-1);
    else
    {
        i.t1 = (-i.b - sqrt(i.delta)) / (2 * i.a);
        i.t2 = (-i.b + sqrt(i.delta)) / (2 * i.a);
		if ((i.t1 <= i.t2 && i.t1 >= 0.0) || (i.t1 >= 0.0 && i.t2 < 0.0))
			return (slice_obj(*pa, *r, (r->t = i.t1)));
		if ((i.t2 <= i.t1 && i.t2 >= 0.0) || (i.t2 >= 0.0 && i.t1 < 0.0))
			return (slice_obj(*pa, *r, (r->t = i.t2)));
		return (-1);
    }
}
