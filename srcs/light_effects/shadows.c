/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:15:58 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/24 16:34:20 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double			in_shadow(t_rt *rt, t_light *light, t_object *object)
{
	t_object	*obj;
	t_object	o;
	double		t;
	double		distance;
	t_ray		shadow;

	shadow.origin = light->position;
	shadow.direction = v_c_prod(light->direction, -1.0);
	obj = rt->objects;
	while (obj)
	{
		copy_obj(&o, obj);
		if (object->id != obj->id\
				&& (t = rt->intersection[obj->type](&o, &shadow)) > 0.0)
		{
			if ((t = slice_obj(o, shadow, t)) > 0)
			{
				shadow.hit_point = v_c_prod(shadow.direction, t);
				distance = sqrtf(dot(shadow.hit_point, shadow.hit_point));
				if (distance < light->d && !obj->is_transp)
					return (0);
				else if (distance < light->d && obj->is_transp)
					light->intensity *= powf(obj->is_transp, 0.2);
			}
		}
		obj = obj->next;
	}
	return (1.0);
}
