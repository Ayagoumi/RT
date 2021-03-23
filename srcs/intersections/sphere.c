/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:51 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/23 18:48:00 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double	hit_sphere(t_object *sph, t_ray *ray)
{
	double		delta;
	// t_intersect		i;

	sph->sph.oc = vect_sub(ray->origin, sph->position);
	sph->sph.a = dot(ray->direction, ray->direction);
	sph->sph.b = 2 * dot(ray->direction, sph->sph.oc);
	sph->sph.c = dot(sph->sph.oc, sph->sph.oc) - sph->radius * sph->radius;
	delta = sph->sph.b * sph->sph.b - 4.0 * sph->sph.a * sph->sph.c;
	if (delta < 0.0)
		return (-1.0);
	ray->t = equa_solu(sph->sph.a, sph->sph.b, delta);
	sph->sph.t = ray->t;
	return (slice_obj(*sph, *ray, ray->t));
}
