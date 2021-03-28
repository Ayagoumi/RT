/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_all_cmp_cobjects.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 12:58:47 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/28 16:38:35 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int				all_cmp_valid_for_triangle(t_node n)
{
	if (n.cmp.color == false ||\
			n.cmp.rotation == false || n.cmp.point_a == false ||\
			n.cmp.point_b == false || n.cmp.translation == false ||\
			n.cmp.point_c == false)
		return (-1);
	return (1);
}

int				all_cmp_valid_for_torus(t_node n)
{
	if (n.cmp.color == false ||\
			n.cmp.rotation == false || n.cmp.orientation == false ||\
			n.cmp.position == false || n.cmp.translation == false ||\
			n.cmp.radius2 == false || \
			n.cmp.radius1 == false)
		return (-1);
	return (1);
}

int				all_cmp_valid_for_ellipsoid(t_node n)
{
	if (n.cmp.color == false ||\
			n.cmp.rotation == false || n.cmp.orientation == false ||\
			n.cmp.position == false || n.cmp.translation == false ||\
			n.cmp.dist == false || n.cmp.radius2 == false || \
			n.cmp.radius1 == false)
		return (-1);
	return (1);
}

int				all_cmp_valid_for_disk(t_node n)
{
	if (n.cmp.color == false ||\
			n.cmp.rotation == false ||\
			n.cmp.position == false || n.cmp.translation == false ||\
			n.cmp.orientation == false || n.cmp.radius == false)
		return (-1);
	return (1);
}
