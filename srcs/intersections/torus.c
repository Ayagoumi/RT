/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 09:28:02 by ayagoumi          #+#    #+#             */
/*   Updated: 2021/03/24 14:14:58 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static double	min(double s[4],  int n)
{
	double	min;
	int		i;

	i = -1;
	while (++i < n)
	{
		if (s[i] > 0.0001)
		{
			min = s[i];
			break ;
		}
	}
	if (i == n)
		return (0);
	while (++i < n)
	{
		if (s[i] > 0.0001 && s[i] < min)
			min = s[i];
	}
	if (min > 0.0001)
	{
		return (min);
	}
	return (-1);
}

// float rad = 1.2;
// float Rad = 5;

double hit_torus(t_object *torus, t_ray *r)
{
	double		c[5];
	double		s[4];
	int			num;
	// t_intersect	i;

	torus->inter.oc = vect_sub(r->origin, torus->position);
	c[4] = powf(dot(r->direction, r->direction), 2);
	c[3] = 4.0 * dot(r->direction, r->direction) * dot(torus->inter.oc, r->direction);
	c[2] = 2 * (dot(r->direction, r->direction) * (dot(torus->inter.oc, torus->inter.oc) - (torus->radius2 * torus->radius2 + torus->radius1 * torus->radius1 ))) + 4 * powf(dot(r->direction, torus->inter.oc), 2) + 4 * torus->radius1 * torus->radius1 * r->direction.y * r->direction.y;
	c[1] = 4 * (dot(torus->inter.oc, torus->inter.oc) - (torus->radius2 * torus->radius2 + torus->radius1 * torus->radius1)) * (dot(torus->inter.oc, r->direction)) + 8 * torus->radius1 * torus->radius1 * torus->inter.oc.y * r->direction.y;
	c[0] = powf(dot(torus->inter.oc, torus->inter.oc) - (torus->radius2 * torus->radius2 + torus->radius1 * torus->radius1) , 2) - 4 * torus->radius1 * torus->radius1 * (torus->radius2 * torus->radius2 - torus->inter.oc.y * torus->inter.oc.y);

	num = ft_solve_quartic(c, s);
	if (num == 0)
		return (-1);
	r->t = min(s, num);
	torus->inter.t = r->t;
	return (r->t);
}
