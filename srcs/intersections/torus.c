/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 09:28:02 by ayagoumi          #+#    #+#             */
/*   Updated: 2021/03/28 16:54:18 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static double	min(double s[4], int n)
{
	double	min;
	int		i;

	i = -1;
	while (++i < n)
	{
		if (s[i] > EPSILLON)
		{
			min = s[i];
			break ;
		}
	}
	if (i == n)
		return (-1);
	while (++i < n)
	{
		if (s[i] > EPSILLON && s[i] < min)
			min = s[i];
	}
	if (min)
		return (min);
	return (-1);
}

double			hit_torus(t_object *to, t_ray *r)
{
	double		c[5];
	double		s[4];
	int			num;

	to->inter.oc = vect_sub(r->origin, to->position);
	c[4] = powd(dot(r->direction, r->direction), 2);
	c[3] = 4.0 * dot(r->direction, r->direction) * \
		dot(to->inter.oc, r->direction);
	c[2] = 2.0 * (dot(r->direction, r->direction) * \
		(dot(to->inter.oc, to->inter.oc)
		- (powd(to->radius1, 2) + powd(to->radius2, 2)))) + 4 * \
		powd(dot(r->direction, to->inter.oc), 2) + 4 * powd(to->radius2, 2) * \
		dot(r->direction, to->orientation) * dot(r->direction, to->orientation);
	c[1] = 4.0 * (dot(to->inter.oc, to->inter.oc) - \
		(powd(to->radius1, 2) + powd(to->radius2, 2))) \
		* (dot(to->inter.oc, r->direction)) + 8 * powd(to->radius2, 2) \
	* dot(to->inter.oc, to->orientation) * dot(r->direction, to->orientation);
	c[0] = powd(dot(to->inter.oc, to->inter.oc) - (powd(to->radius1, 2) \
		+ powd(to->radius2, 2)), 2) - 4 * powd(to->radius2, 2) * \
		(powd(to->radius1, 2) - dot(to->inter.oc, to->orientation) \
		* dot(to->inter.oc, to->orientation));
	if ((num = ft_solve_quartic(c, s)) == 0)
		return (-1);
	r->t = min(s, num);
	return (to->inter.t = r->t);
}
