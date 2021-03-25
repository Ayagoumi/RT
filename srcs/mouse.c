/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:37:44 by yoouali           #+#    #+#             */
/*   Updated: 2021/03/25 11:38:02 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	re_calc2(SDL_Event event, t_rt *rt)
{
	t_ind		ind;
	t_rect		z;

	SDL_GetMouseState(&ind.i, &ind.j);
	z.a = (SDL_Rect){ind.i, ind.j, 1, 1};
	z.b = (SDL_Rect){30, 45, 50, 26};
	if (SDL_IntersectRect(&z.a, &z.b, &z.c) == SDL_TRUE && event.type\
			== SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
		next_cam(rt, 1);
	z.b = (SDL_Rect){120, 45, 50, 26};
	if (SDL_IntersectRect(&z.a, &z.b, &z.c) == SDL_TRUE && event.type\
			== SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
		next_cam(rt, 0);
}

int		re_calc(t_sdl *sdl, SDL_Event event, t_rt *rt)
{
	t_ind		ind;
	t_rect		z;
	int			i;

	SDL_GetMouseState(&ind.i, &ind.j);
	z.a = (SDL_Rect){ind.i, ind.j, 1, 1};
	i = 0;
	while (i < 6)
	{
		z.b = (SDL_Rect){11, 456 + (i * (65)), 180, 60};
		if (SDL_IntersectRect(&z.a, &z.b, &z.c) == SDL_TRUE)
			break ;
		i++;
	}
	if (i < 6 && event.type == SDL_MOUSEBUTTONDOWN && event.button.button \
			== SDL_BUTTON_LEFT)
		return (i);
	z.b = (SDL_Rect){206, 4, 40, 40};
	if (SDL_IntersectRect(&z.a, &z.b, &z.c) == SDL_TRUE && event.type\
			== SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
		loading_savemess(sdl, rt);
	re_calc2(event, rt);
	return (-1);
}
