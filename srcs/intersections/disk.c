/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 14:49:37 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/26 18:20:32 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double		hit_disk(t_object *disk, t_ray *r)
{
	t_vect3	tmp;
	t_vect3	p;

	r->t = (dot(disk->orientation, disk->position) -\
		dot(disk->orientation, r->origin))\
		/ dot(disk->orientation, r->direction);
	tmp = vect_add(r->origin, v_c_prod(r->direction, r->t));
	p = vect_sub(tmp, disk->position);
	if (ft_magnitude(p) >= disk->radius)
		return (-1.0);
	if (r->t > 1e-2)
		return (r->t);
	return (-1.0);
}
