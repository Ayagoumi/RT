/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:48:59 by yoouali           #+#    #+#             */
/*   Updated: 2021/03/26 08:14:08 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void			copy_frame2(t_sdl *sdl, int filter)
{
	t_ind		ind;

	if (filter >= 0 && filter <= 5)
	{
		ind.i = 11;
		while (ind.i < 11 + 180)
		{
			ind.j = 456 + (filter * 65);
			while (ind.j < 456 + (filter * 65) + 60)
			{
				if (compare_color(sdl->frame[WID * ind.j + ind.i], 0x46484C))
					sdl->frame[WID * ind.j + ind.i] = 0xffffffff;
				ind.j++;
			}
			ind.i++;
		}
	}
}

void			copy_frame(t_sdl *sdl, int filter)
{
	t_ind		ind;

	ind.i = -1;
	while (++ind.i < WID && sdl->data_frame)
	{
		ind.j = -1;
		while (++ind.j < HEI)
		{
			sdl->frame[WID * ind.j + ind.i] =
				sdl->data_frame[WID * ind.j + ind.i];
		}
	}
	ind.i = 200;
	while (ind.i < WID)
	{
		ind.j = 50;
		while (ind.j < HEI)
		{
			sdl->frame[WID * ind.j + ind.i] =\
			sdl->data[W * (ind.j - 50) + (ind.i - 200)];
			ind.j++;
		}
		ind.i++;
	}
	copy_frame2(sdl, filter);
}

SDL_Surface		*get_filter_message(int key)
{
	char		*str;
	SDL_Surface	*surface;

	if (key == 0)
		str = "resources/antialiasing.png";
	else if (key == 1)
		str = "resources/cartoon.png";
	else if (key == 2)
		str = "resources/blur.png";
	else if (key == 3)
		str = "resources/sepia.png";
	else if (key == 4)
		str = "resources/grey.png";
	else if (key == 5)
		str = "resources/stereoscopy.png";
	surface = NULL;
	if (!(surface = IMG_Load(str)))
		return (NULL);
	return (surface);
}

void			loading_messages(t_sdl *sdl, int key)
{
	SDL_Surface	*surface;
	int			*tab;
	t_ind		ind;

	surface = get_filter_message(key);
	tab = convert_color((char*)surface->pixels,\
	surface->w, surface->h, surface->format->BytesPerPixel);
	ind.i = 725;
	while (ind.i - 725 < 220 && tab)
	{
		ind.j = 4;
		while (ind.j - 4 < 40)
		{
			sdl->frame[WID * ind.j + ind.i] =\
			tab[220 * (ind.j - 4) + (ind.i - 725)];
			ind.j++;
		}
		ind.i++;
	}
	free(tab);
	SDL_FreeSurface(surface);
}

void			loading_savemess(t_sdl *sdl, t_rt *rt)
{
	t_ind		ind;
	t_col		col1;
	t_col		col2;

	ind.i = 500;
	image_create(sdl->data);
	while (ind.i - 500 < 287 && sdl->data_frame && sdl->data_savemes)
	{
		ind.j = 730;
		while (ind.j - 730 < 63)
		{
			col1 = int_to_rgb_yatak(sdl->frame[WID * ind.j + ind.i]);
			col2 = int_to_rgb_yatak(sdl->data_savemes[287 *\
					(ind.j - 730) + (ind.i - 500)]);
			col1 = alpha_compositing(col1, col2, 1, 0.5);
			sdl->frame[WID * ind.j + ind.i] = rgb_to_int_yatak(col1);
			ind.j++;
		}
		ind.i++;
	}
	render_loading_frame(sdl, rt);
}
