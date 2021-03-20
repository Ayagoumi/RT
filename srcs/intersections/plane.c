/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:50:23 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/19 16:11:43 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double		hit_plane(t_object *object, t_ray *ray)
{
	t_intersect		i;

	object->orientation = normalize(object->orientation);
	i.oc = vect_sub(ray->origin, object->position);
	i.a = dot(i.oc, object->orientation);
	i.b = dot(ray->direction, object->orientation);
	if (i.b == 0 || i.a * i.b >= 0)
		return (-1.0);
	i.t = -i.a / i.b;
	return (slice_obj(*object, *ray, i.t));
}
