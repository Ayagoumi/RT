/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ref_trsp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 09:29:47 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/29 13:47:35 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static t_vect3	lit_comp(t_rt *rt, t_light light, t_object *object, t_ray *ray)
{
	t_vect3 color;
	double	n_l;

	if (object->texture->type != NONE && (object->type == SPHERE ||\
	object->type == CYLINDER || object->type == CONE ||\
	object->type == PLANE))
		texture(&object, ray->hit_point, rt->hooks);
	light.direction = vect_sub(light.position, ray->hit_point);
	light.direction = normalize(light.direction);
	n_l = dot(light.direction, object->normal);
	color = (t_vect3){0.0f, 0.0f, 0.0f};
	if (n_l > 0)
		color = vect_add(color, diffuse(&light, n_l, object));
	color = add_color(color,\
	fraction(reflex_col(rt, *ray, object, &light), object->is_ref));
	color = add_color(color,\
	fraction(refract_color(rt, *ray, object, &light), object->is_transp));
	return (color);
}

static t_object	*refintrsct(t_rt *rt, t_ray *ray, t_object *node)
{
	double			x;
	t_object		*close_tmp[2];
	t_object		o;

	close_tmp[1] = rt->objects;
	close_tmp[0] = NULL;
	ray->t = -1.0;
	x = -1;
	while (close_tmp[1])
	{
		copy_obj(&o, close_tmp[1]);
		if (node->id != o.id)
		{
			rt->intersection[o.type](&o, ray);
			ray->t = slice_obj(close_tmp[1], *ray, ray->t);
			if (ray->t > 1e-5 && (x > ray->t || x == -1))
			{
				close_tmp[0] = close_tmp[1];
				x = ray->t;
			}
		}
		close_tmp[1] = close_tmp[1]->next;
	}
	ray->t = x;
	return (close_tmp[0]);
}

t_color			ref_trsp(t_rt *rt, t_object *obj, t_ray reflect, t_light *light)
{
	t_object	o;
	t_object	*close;

	if ((close = refintrsct(rt, &reflect, obj)) && reflect.t != -1)
	{
		reflect.hit_point = vect_add(reflect.origin,\
		v_c_prod(reflect.direction, reflect.t));
		copy_obj(&o, close);
		o.normal = rt->normal[o.type](&o, &reflect);
		return (lit_comp(rt, *light, &o, &reflect));
	}
	return ((t_color){0, 0, 0});
}
