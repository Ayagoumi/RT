/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paraboloid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:23 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/23 18:53:01 by ayagoumi         ###   ########.fr       */
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

double				hit_paraboloid(t_object *para, t_ray *r)
{
	// t_intersect	i;

    para->par.oc = vect_sub(r->origin, para->position);
    para->par.a = dot(r->direction, r->direction) - powf(dot(r->direction, para->orientation), 2);
    para->par.b = 2 * (dot(r->direction, para->par.oc) - (dot(r->direction,para->orientation) * (dot(para->par.oc, para->orientation) + 2 * para->distance)));
    para->par.c = dot(para->par.oc, para->par.oc) - (dot(para->par.oc, para->orientation) * (dot(para->par.oc, para->orientation) + 4 * para->distance));
    para->par.delta = para->par.b * para->par.b - (4 * para->par.a * para->par.c);
    if (para->par.delta < 0)
        return (-1);
    else
    {
        para->par.t1 = (-para->par.b - sqrt(para->par.delta)) / (2 * para->par.a);
        para->par.t2 = (-para->par.b + sqrt(para->par.delta)) / (2 * para->par.a);
		if ((para->par.t1 <= para->par.t2 && para->par.t1 >= 0.0) || (para->par.t1 >= 0.0 && para->par.t2 < 0.0))
			return (slice_obj(*para, *r, (r->t = para->par.t1)));
		if ((para->par.t2 <= para->par.t1 && para->par.t2 >= 0.0) || (para->par.t2 >= 0.0 && para->par.t1 < 0.0))
			return (slice_obj(*para, *r, (r->t = para->par.t2)));
		return (-1);
    }
}
