/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:15:58 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/29 10:56:04 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void			set_light(t_light *light, t_object *obj)
{
	if (obj->is_transp < 1)
		light->color = multip_color(light->color,\
		fraction(obj->color, obj->is_transp));
	light->intensity *= powf(obj->is_transp, 0.2);
}

int				in_shadow(t_rt *rt, t_light *light, t_object *object)
{
	t_object	*obj;
	t_object	o;
	double		t_d[2];
	t_ray		shadow;

	shadow.origin = light->position;
	shadow.direction = v_c_prod(light->direction, -1.0);
	obj = rt->objects;
	while (obj)
	{
		copy_obj(&o, obj);
		if (object->id != obj->id\
				&& (t_d[0] = rt->intersection[obj->type](&o, &shadow)) > 1e-5)
		{
			t_d[0] = slice_obj(&o, shadow, t_d[0]) + 1e-2;
			shadow.hit_point = v_c_prod(shadow.direction, t_d[0]);
			t_d[1] = sqrtf(dot(shadow.hit_point, shadow.hit_point));
			if (t_d[0] > 0.0 && t_d[1] < light->d && !obj->is_transp)
				return (0);
			else if (t_d[0] > 1e-5 && t_d[1] < light->d && obj->is_transp)
				set_light(light, obj);
		}
		obj = obj->next;
	}
	return (1);
}
