/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:50:23 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/23 18:51:31 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double		hit_plane(t_object *plane, t_ray *ray)
{
	plane->orientation = normalize(plane->orientation);
	plane->pln.oc = vect_sub(ray->origin, plane->position);
	plane->pln.a = dot(plane->pln.oc, plane->orientation);
	plane->pln.b = dot(ray->direction, plane->orientation);
	if (plane->pln.b == 0 || plane->pln.a * plane->pln.b >= 0)
		return (-1.0);
	ray->t = -plane->pln.a / plane->pln.b;
	plane->pln.t = ray->t;
	return (slice_obj(*plane, *ray, plane->pln.t));
}
