/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:59:27 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/29 09:17:03 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void	init_normal(t_rt *new)
{
	new->normal[0] = plane_normal;
	new->normal[1] = sphere_normal;
	new->normal[2] = cylinder_normal;
	new->normal[3] = cone_normal;
	new->normal[4] = NULL;
	new->normal[5] = NULL;
	new->normal[6] = ellipsoid_normal;
	new->normal[7] = paraboloid_normal;
	new->normal[8] = triangle_normal;
	new->normal[9] = torus_normal;
	new->normal[10] = normal_disk;
	new->normal[11] = NULL;
}

static void	init_intersections(t_rt *new)
{
	new->intersection[0] = hit_plane;
	new->intersection[1] = hit_sphere;
	new->intersection[2] = hit_cylinder;
	new->intersection[3] = hit_cone;
	new->intersection[4] = NULL;
	new->intersection[5] = NULL;
	new->intersection[6] = hit_ellipsoid;
	new->intersection[7] = hit_paraboloid;
	new->intersection[8] = hit_triangle;
	new->intersection[9] = hit_torus;
	new->intersection[10] = hit_disk;
	new->intersection[11] = NULL;
}

t_rt		*init_rt(void)
{
	t_rt	*new;

	if (!(new = malloc(sizeof(t_rt))))
		return (NULL);
	new->cameras = NULL;
	new->lights = NULL;
	new->objects = NULL;
	new->ambient = 0;
	new->hooks[0] = 0;
	new->hooks[1] = 0;
	new->nbr_lights = 0;
	new->number_id = 0;
	new->ambient_exist = false;
	new->intersection = malloc(sizeof(double *) * 13);
	new->normal = malloc(sizeof(t_vect3 *) * 13);
	init_intersections(new);
	init_normal(new);
	return (new);
}
