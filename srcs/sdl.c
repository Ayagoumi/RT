/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <aeddaqqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:28:22 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/28 14:10:07 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_sdl	*init_sdl2(t_sdl *sdl)
{
	if (!(sdl->frame_img = IMG_Load("resources/frame.png")))
		return (NULL);
	if (!(sdl->loading = IMG_Load("resources/loading.png")))
		return (NULL);
	if (!(sdl->savemes = IMG_Load("resources/savemes.png")))
		return (NULL);
	sdl->data_frame = convert_color((char*)sdl->frame_img->pixels,\
	sdl->frame_img->w, sdl->frame_img->h,\
	sdl->frame_img->format->BytesPerPixel);
	sdl->data_loading = convert_color((char*)sdl->loading->pixels,\
	sdl->loading->w, sdl->loading->h, sdl->loading->format->BytesPerPixel);
	sdl->data_savemes = convert_color((char*)sdl->savemes->pixels,\
	sdl->savemes->w, sdl->savemes->h, sdl->savemes->format->BytesPerPixel);
	return (sdl);
}

t_sdl	*init_sdl(void)
{
	t_sdl		*sdl;

	if (!(sdl = malloc(sizeof(t_sdl))))
		return (NULL);
	SDL_Init(SDL_INIT_EVERYTHING);
	sdl->win_ptr = SDL_CreateWindow("Rt", SDL_WINDOWPOS_UNDEFINED, \
			SDL_WINDOWPOS_UNDEFINED, WID, HEI, 0);
	sdl->ren_ptr = SDL_CreateRenderer(sdl->win_ptr, -1, 0);
	sdl->tex_ptr = SDL_CreateTexture(sdl->ren_ptr, SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING, WID, HEI);
	return (init_sdl2(sdl));
}

void	render_loading_frame(t_sdl *sdl, t_rt *rt)
{
	t_ind	ind;

	ind.i = 954;
	while (ind.i - 954 < 40)
	{
		ind.j = 4;
		while (ind.j - 4 < 40)
		{
			sdl->frame[WID * ind.j + ind.i] =\
			sdl->data_loading[40 * (ind.j - 4) + (ind.i - 954)];
			ind.j++;
		}
		ind.i++;
	}
	if (rt->save_filter != 8 && rt->save_filter >= 0)
		loading_messages(sdl, rt->save_filter);
	SDL_RenderClear(sdl->ren_ptr);
	SDL_UpdateTexture(sdl->tex_ptr, NULL, sdl->frame, WID * 4);
	SDL_RenderCopy(sdl->ren_ptr, sdl->tex_ptr, NULL, NULL);
	SDL_RenderPresent(sdl->ren_ptr);
	first_render(rt);
}

void	render(t_sdl *sdl, t_rt *rt)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		if (rt->filters[i])
			break ;
		i++;
	}
	if (rt->save_filter == 3)
		sepia_effect(rt->sdl->data);
	if (rt->save_filter == 4)
		grey_effect(rt->sdl->data);
	if (rt->save_filter == 1)
		cartoon_effect(rt->sdl->data);
	if (rt->save_filter == 2)
		blur_effect(rt->sdl->data);
	SDL_RenderClear(sdl->ren_ptr);
	copy_frame(sdl, rt->save_filter);
	SDL_UpdateTexture(sdl->tex_ptr, NULL, sdl->frame, WID * 4);
	SDL_RenderCopy(sdl->ren_ptr, sdl->tex_ptr, NULL, NULL);
	SDL_RenderPresent(sdl->ren_ptr);
}

void	destroy_sdl(t_sdl **s)
{
	t_sdl *sdl;

	sdl = *s;
	SDL_DestroyRenderer(sdl->ren_ptr);
	SDL_DestroyWindow(sdl->win_ptr);
	SDL_FreeSurface(sdl->frame_img);
	SDL_FreeSurface(sdl->loading);
	SDL_FreeSurface(sdl->savemes);
	free(sdl->data_frame);
	free(sdl->data_loading);
	free(sdl->data_savemes);
	TTF_Quit();
	SDL_Quit();
	free(sdl);
	exit(0);
}
