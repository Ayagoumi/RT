/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:49:37 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/24 14:28:50 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double		hit_disk(t_object *disk, t_ray *ray)
{
	t_vect3	tmp;
	t_vect3	p;
	// double	t;

	ray->t = (dot(disk->orientation, disk->position) -\
		dot(disk->orientation, ray->origin))\
		/ dot(disk->orientation, ray->direction);
	tmp = vect_add(ray->origin, v_c_prod(ray->direction, ray->t));
	p = vect_sub(tmp, disk->position);
	if (ft_magnitude(p) >= disk->radius)
		return (-1.0);
	if (ray->t > 1e-2)
	{
		// ray->t = t;
		return (ray->t);
	}
	return (-1.0);
}

// double		hit_disk(t_object *disk, t_ray *ray)
// {
// 	t_vect3	tmp;
// 	t_vect3	p;
// 	// double	t;

// 	disk->dsk.t = (dot(disk->orientation, disk->position) -\
// 		dot(disk->orientation, ray->origin))\
// 		/ dot(disk->orientation, ray->direction);
// 	tmp = vect_add(ray->origin, v_c_prod(ray->direction, ray->t));
// 	p = vect_sub(tmp, disk->position);
// 	if (ft_magnitude(p) >= disk->radius)
// 		return (-1.0);
// 	if (ray->t > 1e-2)
// 	{
// 		ray->t = disk->dsk.t;
// 		return (slice_obj(*disk, *ray, ray->t));
// 	}
// 	return (-1.0);
// }
