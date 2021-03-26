/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:51:51 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/25 17:29:08 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double	hit_sphere(t_object *sph, t_ray *ray)
{
	sph->inter.oc = vect_sub(ray->origin, sph->position);
	sph->inter.a = dot(ray->direction, ray->direction);
	sph->inter.b = 2 * dot(ray->direction, sph->inter.oc);
	sph->inter.c = dot(sph->inter.oc, sph->inter.oc) \
		- sph->radius * sph->radius;
	sph->inter.delta = sph->inter.b * sph->inter.b \
		- 4.0 * sph->inter.a * sph->inter.c;
	if (sph->inter.delta < 0.0)
		return (-1.0);
	sph->inter.t1 = (-sph->inter.b - sqrtf(sph->inter.delta)) \
		/ (2 * sph->inter.a);
	sph->inter.t2 = (-sph->inter.b + sqrtf(sph->inter.delta)) \
		/ (2 * sph->inter.a);
	ray->t = equa_solu(sph->inter.a, sph->inter.b, sph->inter.delta);
	sph->inter.t = ray->t;
	return (ray->t);
}
