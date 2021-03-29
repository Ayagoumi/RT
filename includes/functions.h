/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 12:33:01 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/29 10:53:34 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "./parser/pars_functions.h"
# include "./calculation/calc_functions.h"
# include "./normals/nor_functions.h"
# include "../srcs/intersections/includes/intersection.h"
# include "../srcs/camera/includes/cam_function.h"

/*
**				Main Functions
*/
double			ft_atod(const char *str);
void			rtrace(t_rt *rt);
int				core(t_rt **r);
t_color			int_to_rgb(int m);
void			initab(int *tab);
int				*init_tab(void);
void			copy_obj_help(t_object *n_obj, t_object *obj);
void			copy_obj(t_object *n_obj, t_object *obj);
unsigned int	pixel_color(t_rt *rt, t_ray *ray);
void			apply_antiliasing(t_rt *rt, int x, int y);
void			copy_obj(t_object *n_obj, t_object *obj);
void			copy_obj_help(t_object *n_obj, t_object *obj);
void			draw_scene(t_rt *rt, int x, int y);
void			next_cam(t_rt *rt, int dir);
void			hooks2(t_rt *rt);
void			hooks(t_rt *rt);
void			mouse_hook(t_rt **r, int *to_do);
void			copy_frame2(t_sdl *sdl, int filter);
void			copy_frame(t_sdl *sdl, int filter);
SDL_Surface		*get_filter_message(int key);
void			loading_messages(t_sdl *sdl, int key);
void			loading_savemess(t_sdl *sdl, t_rt *rt);
void			syntax_err(t_rt *rt, char *file);
void			err2(char **av, t_rt *rt, char *file, char *ex);
void			err(char **av, t_rt *rt, char *file);
int				main(int ac, char **av);
void			re_calc2(SDL_Event event, t_rt *rt);
int				re_calc(t_sdl *sdl, SDL_Event event, t_rt *rt);
void			str_v(t_stk *w, t_point *tab);
int				str_f(t_stk *w, int nb, t_point *tab);
t_object		*stock_points(int nb, char *path);
t_object		*load_fileobj(char *path);
int				parse_obj(t_rt *rt, char *path);
double			f_rand(double f_min, double f_max);
void			test_obj(t_stk *w, t_point *tab, int j);
t_sdl			*init_sdl2(t_sdl *sdl);
t_sdl			*init_sdl(void);
void			render_loading_frame(t_sdl *sdl, t_rt *rt);
void			render(t_sdl *sdl, t_rt *rt);
void			destroy_sdl(t_sdl **s);
void			first_render(t_rt *rt);
/*
**		lights
*/
t_color			ambient(t_object *obj, double amb);
t_color			diffuse(t_light *light, double n_l, t_object *object);
t_color			is_direct_light(t_rt *rt, t_ray r, double t);
int				parallel_light(t_ray r, t_light light);
t_color			shade(t_rt *rt, t_light li, t_object obj, t_ray r);
unsigned int	light_effect(t_rt *rt, t_object *o, t_ray *ray);
int				light(t_object *close_obj, t_ray *ray, t_rt *rt, double t);
t_color			inttorgb(int m);
t_color			add_color(t_color c1, t_color c2);
int				rgb(t_color color);
t_color			fraction(t_color c, double fract);
t_color			multip_color(t_color c1, t_color c2);
int				in_shadow(t_rt *rt, t_light *light, t_object *object);
t_color			specular(t_light *l, t_ray *ray, t_object *object);
void			texture2(t_object **object, t_point p);
int				texture(t_object **object, t_point hit, double tab[2]);
void			texture_wave_effect(t_object **object, t_point hit);
void			texture_wave_effect_plane(t_object **object, t_point hit);
int				texture_clr(t_object **object, t_point hit, double tab[2]);
void			apply_texture(t_object *obj, double uv[2]);
/*
**--------------------------++++++++++++++++++++++++++++++++++++
*/
void			square(t_sdl *sdl, int x, int save);
t_sdl			*init_sdl(void);
void			destroy_sdl(t_sdl **s);
void			render(t_sdl *sdl, t_rt *rt);
int				re_calc(t_sdl *sdl, SDL_Event event, t_rt *rt);
double			ft_min_ray(double t1, double t2, double *tmin);
void			ft_compute_normals(t_hit *hit, t_ray *ray);
t_ray			obj_intersect(t_object *p, t_hit *hit, t_ray ray, double t);
t_color			ft_shade_object(t_hit *hit, t_rt *rt, t_ray *ray);
t_ray			reflexion(t_ray ray, t_vect3 norm);
t_ray			refraction(t_ray ray, t_vect3 norm, double n2);
t_color			raytrace(t_rt *rt, t_hit *hit, t_ray *ray);
t_color			refract_color(t_rt *rt, t_ray ray, t_object *object,\
				t_light *light);
t_color			reflex_col(t_rt *rt, t_ray ray, t_object *object,\
				t_light *light);
t_color			ref_trsp(t_rt *rt, t_object *object, t_ray reflect, \
				t_light *light);
t_color			is_direct_light(t_rt *rt, t_ray ray, double t);
int				parallel_light(t_ray r, t_light light);
void			set_matter(t_object *o);
void			next_cam(t_rt *rt, int dir);
void			render_loading_frame(t_sdl	*sdl, t_rt *rt);
void			loading_savemess(t_sdl *sdl, t_rt *rt);
void			loading_messages(t_sdl *sdl, int key);
void			copy_frame(t_sdl *sdl, int filter);
#endif
