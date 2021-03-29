/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:08:06 by ahkhilad          #+#    #+#             */
/*   Updated: 2021/03/29 10:10:45 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_FUNCTIONS_H
# define CALC_FUNCTIONS_H

double			dot(t_vect3 u, t_vect3 v);
double			ft_magnitude(t_vect3 v);
double			deg_to_rad(double angle);
t_vect3			ft_vector(double x, double y, double z);
t_vect3			normalize(t_vect3 v);
t_vect3			ft_negative(t_vect3 v);
t_vect3			cross(t_vect3 a, t_vect3 b);
t_vect3			vect_add(t_vect3 a, t_vect3 b);
t_vect3			vect_sub(t_vect3 a, t_vect3 b);
t_vect3			vect_div(t_vect3 u, t_vect3 v);
t_vect3			vect_prod(t_vect3 u, t_vect3 v);
t_vect3			v_c_prod(t_vect3 u, double v);
t_vect3			v_c_add(t_vect3 u, double v);
int				ft_solve_cubic(double w[4], double s[3]);
int				ft_solve_quadric(double c[3], double s[2]);
int				ft_solve_quartic(double w[5], double s[4]);
bool			is_zero(double x);
double			ft_cbrt(double x);
double			powd(double x, int n);

#endif
