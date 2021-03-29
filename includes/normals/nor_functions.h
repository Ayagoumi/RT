/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nor_functions.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 18:39:48 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/29 10:14:49 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NOR_FUNCTIONS_H
# define NOR_FUNCTIONS_H

t_vect3			cone_normal(t_object *cone, t_ray *ray);
t_vect3			cylinder_normal(t_object *object, t_ray *ray);
t_vect3			normal_disk(t_object *disk, t_ray *ray);
t_vect3			ellipsoid_normal(t_object *object, t_ray *ray);
t_vect3			paraboloid_normal(t_object *object, t_ray *ray);
t_vect3			plane_normal(t_object *object, t_ray *ray);
t_vect3			sphere_normal(t_object *obj, t_ray *ray);
t_vect3			torus_normal(t_object *obj, t_ray *ray);
t_vect3			triangle_normal(t_object *object, t_ray *ray);

#endif
