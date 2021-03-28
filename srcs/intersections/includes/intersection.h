/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:50:53 by nabouzah          #+#    #+#             */
/*   Updated: 2021/03/28 16:55:00 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

double	hit_cone(t_object *c, t_ray *r);
double	hit_cylinder(t_object *cyl, t_ray *r);
double	hit_disk(t_object *disk, t_ray *r);
double	hit_ellipsoid(t_object *elip, t_ray *r);
double	hit_paraboloid(t_object *para, t_ray *r);
double	hit_plane(t_object *plane, t_ray *ray);
double	hit_sphere(t_object *sph, t_ray *ray);
double	hit_torus(t_object *to, t_ray *r);
double	hit_triangle(t_object *triangle, t_ray *r);
double	equa_solu(double a, double b, double delta);
double	slice_obj(t_object *o, t_ray r, double t);

#endif
