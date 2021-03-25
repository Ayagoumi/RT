/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:49:08 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/25 09:53:06 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"


void	next_cam(t_rt *rt, int dir)
{
	if (rt->cameras->next && dir == 0)
	{
		rt->cameras = rt->cameras->next;
		new_camera(rt);
		render_loading_frame(rt->sdl, rt);
		first_render(rt);
	}
	if (rt->cameras->prev && dir == 1)
	{
		rt->cameras = rt->cameras->prev;
		new_camera(rt);
		render_loading_frame(rt->sdl, rt);
		first_render(rt);
	}
}

void	hooks(t_rt **r)
{
	t_rt *rt;

	rt = *r;
	if (rt->sdl->event.type == SDL_KEYDOWN)
	{
	if (rt->sdl->event.key.keysym.sym == SDLK_h)
	{
		if (rt->hooks[1] < 1.0)
			rt->hooks[1] += 0.1;
		printf("hhh\n");
		render_loading_frame(rt->sdl, rt);
		first_render(rt);
	}
	if (rt->sdl->event.key.keysym.sym == SDLK_j)
	{
		if (rt->hooks[1] > -1)
			rt->hooks[1] -= .1;
		printf("hhh\n");
		render_loading_frame(rt->sdl, rt);
		first_render(rt);
	}
	if (rt->sdl->event.key.keysym.sym == SDLK_f)
	{
		if (rt->hooks[0] < 1.0)
			rt->hooks[0] += 0.1;
		printf("hhh\n");
		render_loading_frame(rt->sdl, rt);
		first_render(rt);
	}
	if (rt->sdl->event.key.keysym.sym == SDLK_g)
	{
		if (rt->hooks[0] > -1.0)
			rt->hooks[0] -= 0.1;
		printf("hhh\n");
		render_loading_frame(rt->sdl, rt);
		first_render(rt);
	}

		if (rt->sdl->event.key.keysym.sym == SDLK_ESCAPE)
		{
			destroy_sdl(&rt->sdl);
			exit(0);
		}
	}
}	

void	mouse_hook(t_rt **r, int *to_do)
{
	t_rt *rt;

	rt = *r;
	if (SDL_GetMouseFocus() == rt->sdl->win_ptr)
	 {
	 	if ((*to_do = re_calc(rt->sdl, rt->sdl->event, rt)) != -1)
		{
		if (rt->save_filter == *to_do)
			rt->save_filter = 8;
		else
	 		rt->save_filter = *to_do;
	 	}
		 if (*to_do != -1)
		 {
			printf("her\n");
			render_loading_frame(rt->sdl, rt);
			first_render(rt);
		 }
	 }
}
