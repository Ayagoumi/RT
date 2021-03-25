/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:24:33 by ayagoumi          #+#    #+#             */
/*   Updated: 2021/03/24 16:39:40 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3			cylinder_normal(t_object *object, t_ray *ray)
{
	double		m;
	t_vect3		n;
	t_vect3		p;

	m = dot(ray->direction, object->orientation) * ray->t;
	m += dot(vect_sub(ray->origin, object->position), object->orientation);
	p = vect_add(ray->origin, v_c_prod(ray->direction, ray->t));
	n = normalize(vect_sub(vect_sub(p, object->position),\
				v_c_prod(object->orientation, m)));
	return (n);
}
