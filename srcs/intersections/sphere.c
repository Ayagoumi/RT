/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:51 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/24 14:14:45 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double	hit_sphere(t_object *sph, t_ray *ray)
{
	double		delta;
	// t_intersect		i;

	sph->inter.oc = vect_sub(ray->origin, sph->position);
	sph->inter.a = dot(ray->direction, ray->direction);
	sph->inter.b = 2 * dot(ray->direction, sph->inter.oc);
	sph->inter.c = dot(sph->inter.oc, sph->inter.oc) - sph->radius * sph->radius;
	delta = sph->inter.b * sph->inter.b - 4.0 * sph->inter.a * sph->inter.c;
	if (delta < 0.0)
		return (-1.0);
	ray->t = equa_solu(sph->inter.a, sph->inter.b, delta);
	sph->inter.t = ray->t;
	return (slice_obj(*sph, *ray, ray->t));
}
