/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_functions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:14:56 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/29 10:48:22 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_FUNCTIONS_H
# define PARS_FUNCTIONS_H

/*
** ------------------------------{Stock}-------------------------
*/
char			*load_file(char *path);
char			*get_tag(char *s, int *i);
char			*inner_text(char *s, int *j);
int				white_space(char *s, int *i);
int				stock_elements_cmp(char *s, t_tags tags, t_rt *rt, int *i);
int				parse(char *file, t_rt *rt);
int				stock_cmp(void **object, char *str, int r, int type);
int				stock_elements(char *str, t_tags tags, int *i, t_rt *rt);
int				get_point(char *s, t_point *p);
int				get_ori_vect(char *s, t_vect3 *ori);
int				get_color(char *s, t_color *color);
int				get_raduis_a(char *s, int type, double *r_a);
int				stock_cmp_objects(t_object *obj, int r, char *str);
void			stock_slice(t_object *obj, char *str);
int				cmp_with_objects(char *s, char **tab);
void			stock_matter(t_object *obj, char *str);
/*
** ------------------------------{Init}-------------------------
*/

t_rt			*init_rt(void);
t_tags			init_tab_tags(void);
void			init_ctags_follow_up(t_tags *tags);
void			init_ctags_cmp(t_tags *tags);
t_node			init_node(void);

/*
** ------------------------------{Free}-------------------------
*/

void			free_rt(t_rt **rt);
void			destroy(t_error type);

/*
** ------------------------------{Check}-------------------------
*/

int				check_openning_elem(char *s, char **tab);
int				check_closing_elem(char *s, int n, char **tab, int *i);
int				check_components_exist(t_node n, int type);
void			valid_cmp(t_node *n, int type);
void			valid_cmp_for_sphere(t_node *n, int type);
void			valid_cmp_for_plane(t_node *n, int type);
void			valid_cmp_for_cone(t_node *n, int type);
void			valid_cmp_for_cylinder(t_node *n, int type);
void			valid_cmp_for_paraboloid(t_node *n, int type);
void			valid_cmp_for_torus(t_node *n, int type);
void			valid_cmp_for_ellipsoid(t_node *n, int type);
void			valid_cmp_for_triangle(t_node *n, int type);
void			valid_cmp_for_disk(t_node *n, int type);
int				all_cmp_valid_for_paraboloid(t_node n);
int				all_cmp_valid_for_cylinder(t_node n);
int				all_cmp_valid_for_cone(t_node n);
int				all_cmp_valid_for_plane(t_node n);
int				all_cmp_valid_for_sphere(t_node n);
int				all_cmp_valid_for_torus(t_node n);
int				all_cmp_valid_for_ellipsoid(t_node n);
int				all_cmp_valid_for_torus(t_node n);
int				all_cmp_valid_for_triangle(t_node n);
int				all_cmp_valid_for_disk(t_node n);
int				check_for_sphere(int type, t_node n);
int				check_for_plane(int type, t_node n);
int				check_for_cone(int type, t_node n);
int				check_for_cylinder(int type, t_node n);
int				check_for_paraboloid(int type, t_node n);
int				check_for_ellipsoid(int type, t_node n);
int				check_for_torus(int type, t_node n);
int				check_for_torus(int type, t_node n);
int				check_for_triangle(int type, t_node n);
int				check_for_disk(int type, t_node n);
int				*convert_color(char *pixels, int w, int h, int bbp);
/*
** ------------------------------{Util}-------------------------
*/

void			add_front(t_rt **head, void *new, int type);
void			*new_object(int type);
void			new_objects2(t_object *n_obj);
int				rgb_to_int(t_color v);
int				to_rgb(t_color *co, int c);
int				read_color(t_color *c, char *data);
int				stock_rpa(double *dst, char *str, int r);
int				stock_vect3(t_vect3 *r, char *str, int type);
void			free_tab2(char ***tab, int l);
int				len_tab_2d(char **tab);
/*
**{--------------------------------------------------------------}
*/

t_vect3			rotation_xyz(t_vect3 v, t_vect3 a);

#endif
