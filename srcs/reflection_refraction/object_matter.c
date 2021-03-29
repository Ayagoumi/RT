/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_matter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabouzah <nabouzah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:50:31 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/29 11:58:48 by nabouzah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void	set_matter1(t_object *o)
{
	if (o->matter == DIAMOND)
	{
		o->refraction_index = 1.8;
		o->is_transp = 0.9;
		o->is_ref = 0.4;
		o->color = (t_color){185.0 * 0.5 / 255, 242.0 * 0.5 / 255, 0.5};
	}
	if (o->matter == MIRROR)
	{
		o->refraction_index = 0;
		o->is_transp = 0;
		o->is_ref = 1;
		o->color = (t_color){0.0 / 255, 0.0 / 255, 0.0};
	}
}

void		set_matter(t_object *o)
{
	set_matter1(o);
	if (o->matter == GLASS)
	{
		o->refraction_index = 1.5;
		o->is_transp = 0.9;
		o->is_ref = 0.1;
		o->color = (t_color){246.0 * 0.5 / 255, 254.0 * 0.5 / 255, 0.5};
	}
	if (o->matter == WATER)
	{
		o->refraction_index = 1.3;
		o->is_transp = 0.6;
		o->is_ref = 0.2;
		o->color =\
		(t_color){212.0 * 0.5 / 255, 241.0 * 0.5 / 255, 249.0 * 0.5 / 255};
	}
}
