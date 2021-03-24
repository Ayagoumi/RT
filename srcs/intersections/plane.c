/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:50:23 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/24 14:14:30 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double		hit_plane(t_object *plane, t_ray *ray)
{
	plane->orientation = normalize(plane->orientation);
	plane->inter.oc = vect_sub(ray->origin, plane->position);
	plane->inter.a = dot(plane->inter.oc, plane->orientation);
	plane->inter.b = dot(ray->direction, plane->orientation);
	if (plane->inter.b == 0 || plane->inter.a * plane->inter.b >= 0)
		return (-1.0);
	ray->t = -plane->inter.a / plane->inter.b;
	plane->inter.t = ray->t;
	return (slice_obj(*plane, *ray, plane->inter.t));
}
