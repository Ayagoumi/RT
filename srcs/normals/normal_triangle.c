/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 10:33:30 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/20 19:00:04 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3			triangle_normal(t_object *object, t_ray *ray)
{
	t_vect3		ca;
	t_vect3		ba;
	t_vect3		normal;

	(void)ray;
	ca = vect_sub(object->point_c, object->point_a);
	ba = vect_sub(object->point_b, object->point_a);
	normal = normalize(cross(ba, ca));
	if (dot(ray->direction, normal) > 0)
		normal = v_c_prod(normal, -1.0);
	return (normal);
}
