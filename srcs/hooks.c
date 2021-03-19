/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 16:49:08 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/19 17:31:49 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	hooks2(t_rt **r)
{
	t_rt *rt;

	rt = *r;
	if (rt->sdl->key_table[SDL_SCANCODE_F])
	{
		if (rt->hooks[0] < 1.0)
			rt->hooks[0] += 0.1;
		first_render(rt);
		menu(rt->sdl, rt->save_filter);
	}
	if (rt->sdl->key_table[SDL_SCANCODE_G])
	{
		if (rt->hooks[0] > -1.0)
			rt->hooks[0] -= 0.1;
		first_render(rt);
		menu(rt->sdl, rt->save_filter);
	}
}

void	next_cam(t_rt **r)
{
	t_rt *rt;

	rt = *r;
	if (rt->sdl->key_table[SDL_SCANCODE_O])
	{
		if (rt->cameras->next)
		{
			rt->cameras = rt->cameras->next;
			new_camera(rt);
			first_render(rt);
			//menu(rt->sdl, rt->save_filter);
		}
	}
	if (rt->sdl->key_table[SDL_SCANCODE_P])
	{
		if (rt->cameras->prev)
		{
			rt->cameras = rt->cameras->prev;
			new_camera(rt);
			first_render(rt);
			//menu(rt->sdl, rt->save_filter);
		}
	}
	if (rt->sdl->key_table[SDL_SCANCODE_S] && rt->sdl->save == 0)
	{
		printf("key pres\n");
		image_create(rt->sdl->data);
		rt->sdl->save = 1;
	}
	if (rt->sdl->event.type == SDL_KEYUP && rt->sdl->event.key.keysym.sym == 's')
	{
		printf("%c key released\n", (char)rt->sdl->event.key.keysym.sym);
		rt->sdl->save = 0;
	}
	hooks2(r);
}

void		clear_camera(t_rt *rt)
{
	int		i;
	int		j;

	printf("set new origin\n");
	rt->cameras->o.x = (double)ft_atoi(rt->sdl->text[0]);
	rt->cameras->o.y = (double)ft_atoi(rt->sdl->text[1]);
	rt->cameras->o.z = (double)ft_atoi(rt->sdl->text[2]);
	rt->sdl->indtext = 0;
	rt->sdl->enterind = 0;
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 4)
		{
			rt->sdl->text[i][j] = '\0';
			j++;
		}
		i++;
	}
	first_render(rt);
	rt->save_filter = 6;
	//menu(rt->sdl, rt->save_filter);
}

void	enter_camera_position(t_rt *rt)
{
	if (rt->save_filter == 1)
	{
		if (rt->sdl->event.type == SDL_KEYDOWN)
		{
			if (rt->sdl->event.key.keysym.sym == SDLK_RETURN)
			{
				rt->sdl->enterind += 1;
				rt->sdl->indtext =0;
					printf("\n");
			}
			else
			{
				rt->sdl->text[rt->sdl->enterind][rt->sdl->indtext] = rt->sdl->event.key.keysym.sym;
				printf("%c", rt->sdl->event.key.keysym.sym);
				rt->sdl->indtext += 1;
			}
			if (rt->sdl->indtext > 3)
			{
				printf("\n");
				rt->sdl->indtext = 0;
				rt->sdl->enterind += 1;
			}
			if (rt->sdl->enterind > 2)
			{
				clear_camera(rt);
			}
		}
	}	
}

void	hooks(t_rt **r)
{
	t_rt *rt;

	rt = *r;
	rt->sdl->key_table = (char *)SDL_GetKeyboardState(NULL);
	if (rt->sdl->key_table[SDL_SCANCODE_ESCAPE])
	{
		if (rt->save)
			image_create(rt->sdl->data);
		rt->sdl->loop = 0;
	}
	next_cam(r);
	if (rt->sdl->key_table[SDL_SCANCODE_H])
	{
		if (rt->hooks[1] < 1.0)
			rt->hooks[1] += 0.1;
		first_render(rt);
		//menu(rt->sdl, rt->save_filter);
	}
	if (rt->sdl->key_table[SDL_SCANCODE_J])
	{
		if (rt->hooks[1] > -1)
			rt->hooks[1] -= .1;
		first_render(rt);
		//menu(rt->sdl, rt->save_filter);
	}
	
	if (rt->sdl->event.type == SDL_KEYDOWN && rt->save_filter != 1)
	{
		printf("pres\n");
		if (rt->sdl->event.key.keysym.sym == SDLK_q)
			rt->save_filter = 0;
		if (rt->sdl->event.key.keysym.sym == SDLK_w)
			rt->save_filter = 2;
		if (rt->sdl->event.key.keysym.sym == SDLK_e)
			rt->save_filter = 3;
		if (rt->sdl->event.key.keysym.sym == SDLK_r)
			rt->save_filter = 4;
		if (rt->sdl->event.key.keysym.sym == SDLK_t)
			rt->save_filter = 1;
		if (rt->sdl->event.key.keysym.sym == SDLK_y)
			rt->save_filter = 5;
		if (rt->sdl->event.key.keysym.sym == SDLK_u)
			rt->save_filter = 6;
		first_render(rt);
	}
	else 
	enter_camera_position(rt);
}	

void	mouse_hook(t_rt **r, int *to_do)
{
	t_rt *rt;

	rt = *r;
	if (SDL_GetMouseFocus() == rt->sdl->win_menu)
	{
		if ((*to_do = re_calc(rt->sdl, rt->sdl->event)) != -1)
		{
			if (rt->save_filter == *to_do)
				rt->save_filter = -1;
			else
			{
				rt->filters[*to_do] = 1;
				rt->save_filter = *to_do;
			}
		first_render(rt);
		render(rt->sdl, rt);
		menu(rt->sdl, rt->save_filter);
		}
	}
}
