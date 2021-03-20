/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:51 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/19 15:48:26 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double	hit_sphere(t_object *object, t_ray *ray)
{
	double		delta;
	t_intersect		i;

	i.oc = vect_sub(ray->origin, object->position);
	i.a = dot(ray->direction, ray->direction);
	i.b = 2 * dot(ray->direction, i.oc);
	i.c = dot(i.oc, i.oc) - object->radius * object->radius;
	delta = i.b * i.b - 4.0 * i.a * i.c;
	if (delta < 0.0)
		return (-1.0);
	return (slice_obj(*object, *ray, equa_solu(i.a, i.b, delta)));
}
