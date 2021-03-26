/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:49:37 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/25 17:13:12 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double		hit_disk(t_object *disk, t_ray *ray)
{
	t_vect3	tmp;
	t_vect3	p;

	ray->t = (dot(disk->orientation, disk->position) -\
		dot(disk->orientation, ray->origin))\
		/ dot(disk->orientation, ray->direction);
	tmp = vect_add(ray->origin, v_c_prod(ray->direction, ray->t));
	p = vect_sub(tmp, disk->position);
	if (ft_magnitude(p) >= disk->radius)
		return (-1.0);
	if (ray->t > 1e-2)
	{
		return (ray->t);
	}
	return (-1.0);
}
