/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:47:47 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/29 09:58:25 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./parser/pars_struct.h"

typedef struct	s_cubic
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	sq_a;
	double	p;
	double	q;
	double	cb_p;
}				t_cubic;

typedef struct	s_quartic
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	z;
	double	u;
	double	v;
	double	sub;
	double	sq_a;
	double	p;
	double	q;
	double	r;
}				t_quartic;

typedef struct	s_vect3
{
	double	x;
	double	y;
	double	z;
}				t_vect3;

typedef struct	s_rr
{
	double	r1;
	double	r2;
}				t_rr;

typedef struct	s_rect
{
	SDL_Rect	a;
	SDL_Rect	b;
	SDL_Rect	c;
}				t_rect;

typedef struct	s_rts
{
	SDL_Rect	dstrect;
	SDL_Texture	*tex;
	SDL_Surface	*sur;
}				t_rts;

typedef struct	s_tx
{
	int		i;
	int		tex_x;
	int		tex_y;
}				t_tx;

typedef t_vect3	t_point;
typedef t_vect3	t_color;

typedef struct	s_discr
{
	double	a;
	double	b;
	double	c;
	double	val;
}				t_discr;

typedef struct	s_light
{
	t_vect3			direction;
	t_vect3			look_at;
	t_light_type	type;
	t_point			position;
	double			intensity;
	double			distance;
	t_color			color;
	double			d;
	t_vect3			light_reflected;
	struct s_light	*next;
}				t_light;

typedef struct	s_cords
{
	t_vect3	u;
	t_vect3	v;
	t_vect3	w;
}				t_cords;

typedef struct	s_cam
{
	t_point			o;
	t_vect3			l;
	t_vect3			up;
	t_cords			cords;
	double			fov;
	double			ratio;
	double			plan_h;
	double			plan_w;
	struct s_cam	*next;
	struct s_cam	*prev;
}				t_cam;

typedef struct	s_cap
{
	double	m0;
	double	m1;
}				t_cap;

typedef struct	s_intersect
{
	double	k;
	double	a;
	double	b;
	double	c;
	double	delta;
	double	t;
	double	t1;
	double	t2;
	t_vect3	oc;
}				t_intersect;

typedef struct	s_tri
{
	t_vect3	ca;
	t_vect3	ba;
	t_vect3	pvec;
	t_vect3	qvec;
	t_vect3	tvec;
	t_vect3	surface_normal;
	double	distance;
	double	det;
	double	inv_det;
}				t_tri;

typedef struct	s_tex
{
	int			w;
	int			h;
	int			*data_pixels;
	t_type_tex	type;
	bool		slice;
}				t_tex;

typedef struct	s_object
{
	t_type			type;
	t_vect3			position;
	t_vect3			translation;
	t_vect3			rotation;
	t_color			color;
	t_point			point_a;
	t_point			point_b;
	t_point			point_c;
	t_point			point_d;
	t_point			corner[2];
	t_vect3			orientation;
	t_vect3			normal;
	double			height;
	double			radius;
	double			radius1;
	double			radius2;
	double			distance;
	double			angle;
	double			refraction_index;
	double			is_ref;
	double			is_transp;
	t_intersect		inter;
	t_intersect		cyl;
	t_tri			tri;
	int				id;
	int				slice_flag;
	t_matter		matter;
	t_tex			*texture;
	t_vect3			slice;
	bool			slice_check;
	struct s_object	*next;
}				t_object;

typedef	struct	s_stk
{
	int			i;
	int			z;
	int			indice;
	t_object	*obj;
	t_object	*tmp;
	char		**split;

}				t_stk;

typedef struct	s_hit
{
	t_vect3		n;
	t_vect3		p;
	t_object	*object;
	double		t;
}				t_hit;

typedef struct	s_ray
{
	t_vect3	origin;
	t_vect3	direction;
	t_point	hit_point;
	int		reflect_nb;
	double	refraction_index;
	double	t;
	int		ret;
}				t_ray;

typedef struct	s_sdl
{
	SDL_Window		*win_ptr;
	SDL_Renderer	*ren_ptr;
	SDL_Texture		*tex_ptr;
	SDL_Surface		*frame_img;
	int				*data_frame;
	SDL_Surface		*loading;
	int				*data_loading;
	SDL_Surface		*savemes;
	int				*data_savemes;
	int				frame[WID * HEI];
	int				loop;
	SDL_Event		event;
	int				*tex;
	int				data[W * H];
}				t_sdl;

typedef struct	s_rt
{
	int				number_id;
	t_sdl			*sdl;
	t_object		*objects;
	t_object		*obj;
	t_node			node;
	t_cam			*cameras;
	t_light			*lights;
	double			ambient;
	bool			ambient_exist;
	unsigned int	nbr_lights;
	int				*filters;
	int				save_filter;
	double			hooks[2];
	double			(**intersection)(t_object *obj, t_ray *r);
	t_vect3			(**normal)(t_object *obj, t_ray *r);
}				t_rt;

#endif
