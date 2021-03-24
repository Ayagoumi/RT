/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:28:22 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/24 15:08:11 by yoouali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_sdl			*init_sdl(void)
{
	t_sdl		*sdl;
	SDL_Surface	*s;

	if (!(s = IMG_Load("./resources/earthmap.jpg")))
		return (NULL);
	if (!(sdl = malloc(sizeof(t_sdl))))
		return (NULL);
	SDL_Init(SDL_INIT_EVERYTHING);
	sdl->win_ptr = SDL_CreateWindow("Rt", SDL_WINDOWPOS_UNDEFINED, \
			SDL_WINDOWPOS_UNDEFINED, WID, HEI, 0);
	sdl->ren_ptr = SDL_CreateRenderer(sdl->win_ptr, -1, 0);
	sdl->tex_ptr = SDL_CreateTexture(sdl->ren_ptr, SDL_PIXELFORMAT_ARGB8888,
	SDL_TEXTUREACCESS_STREAMING, WID, HEI);
	if (!(sdl->bstila = IMG_Load("bstila.png")))
	{
		printf("dfdf\n");
		exit(0);
	}
	if (!(sdl->magana = IMG_Load("magana.png")))
	{
		printf("magana\n");
		exit(0);
	}
	if (!(sdl->savemes = IMG_Load("savemes.png")))
	{
		printf("magana\n");
		exit(0);
	}
	sdl->data_bstila = convert_color((char*)sdl->bstila->pixels, sdl->bstila->w, sdl->bstila->h, sdl->bstila->format->BytesPerPixel);
	sdl->data_magana = convert_color((char*)sdl->magana->pixels, sdl->magana->w, sdl->magana->h, sdl->magana->format->BytesPerPixel);
	sdl->data_savemes = convert_color((char*)sdl->savemes->pixels, sdl->savemes->w, sdl->savemes->h, sdl->savemes->format->BytesPerPixel);
	sdl->save = 0;
	sdl->text[0] = malloc(sizeof(char) * 5);
	sdl->text[1] = malloc(sizeof(char) * 5);
	sdl->text[2] = malloc(sizeof(char) * 5);
	sdl->text[0][4] = '\0';
	sdl->text[0][4] = '\0';
	sdl->text[0][4] = '\0';
	sdl->enterind = 0;
	sdl->indtext = 0;
	return (sdl);
}

int				re_calc(t_sdl *sdl, SDL_Event event, t_rt *rt)
{
	int			x;
	int			y;
	t_rect		z;
	int			i;

	SDL_GetMouseState(&x, &y);
	z.a = (SDL_Rect){x, y, 1, 1};
	i = 0;
	 if (SDL_GetMouseFocus() == sdl->win_ptr)
	{
		i = 0;
		while (i < 6)
		{
			z.b = (SDL_Rect){11,  456 + (i * (65)), 180, 60};
			if (SDL_IntersectRect(&z.a, &z.b, &z.c) == SDL_TRUE)
				break ;
			i++;
		}
		z.b = (SDL_Rect){206, 4, 40, 40};
		if (SDL_IntersectRect(&z.a, &z.b, &z.c) == SDL_TRUE && event.type\
		== SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
				loading_savemess(sdl, rt);
		z.b = (SDL_Rect){30, 45, 50, 26};
		if (SDL_IntersectRect(&z.a, &z.b, &z.c) == SDL_TRUE && event.type\
		== SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
			next_cam(rt, 1);
		z.b = (SDL_Rect){120, 45, 50, 26};
		if (SDL_IntersectRect(&z.a, &z.b, &z.c) == SDL_TRUE && event.type\
		== SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
			next_cam(rt, 0);
	 }
	if (i < 6 && event.type == SDL_MOUSEBUTTONDOWN && event.button.button \
			== SDL_BUTTON_LEFT)
		return (i);
	return (-1);
}

void			copy_bstila(t_sdl *sdl, int filter)
{
	t_ind	ind;

	ind.i = 0;
	while (ind.i < WID)
	{
		ind.j = 0;
		while (ind.j < HEI)
		{
			sdl->frame[WID * ind.j + ind.i] = sdl->data_bstila[WID * ind.j+ ind.i];
			ind.j++;
		}
		ind.i++;
	}
	ind.i = 200;
	while (ind.i < WID)
	{
		ind.j = 50;
		while (ind.j < HEI)
		{
			sdl->frame[WID * ind.j + ind.i] = sdl->data[W * (ind.j - 50) + (ind.i - 200)];
			ind.j++;
		}
		ind.i++;
	}
	if (filter >= 0 && filter <= 5)
	{
	ind.i = 11;
	while (ind.i < 11 + 180)
	{
		ind.j = 456 + (filter * 65);
		while (ind.j < 456 + (filter * 65) + 60)
		{
			if (compare_color(sdl->frame[WID * ind.j + ind.i], 0xc4c4c4))
				sdl->frame[WID * ind.j + ind.i] = 0xffffffff;
			ind.j++;
		}
		ind.i++;
	}
	}
}

void			render_loading_frame(t_sdl	*sdl, t_rt *rt)
{
	t_ind	ind;

	ind.i = 954;
	while (ind.i - 954 < 40)
	{
		ind.j = 4;
		while (ind.j - 4 < 40)
		{
			sdl->frame[WID * ind.j + ind.i] = sdl->data_magana[40 * (ind.j - 4) + (ind.i - 954)];
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
}

void			loading_messages(t_sdl *sdl, int  key)
{
	SDL_Surface		*surface;
	int				*tab;
	char			*str;
	t_ind			ind;

	printf("lhtba 2\n");
	if (key == 0)
		str = "antialiasing.png";
	else if (key == 1)
		str = "cartoon.png";
	else if (key == 2)
		str = "blur.png";
	else if (key == 3)
		str = "sepia.png";
	else if (key == 4)
		str = "grey.png";
	else if (key == 5)
		str = "stereoscopy.png";
	surface = NULL;
	if (!(surface = IMG_Load(str)))
	{
		exit(0);
	}
	tab = convert_color((char*)surface->pixels, surface->w, surface->h, surface->format->BytesPerPixel);
	ind.i = 725;
	while (ind.i - 725 < 220)
	{
		ind.j = 4;
		while (ind.j - 4 < 40)
		{
			sdl->frame[WID * ind.j + ind.i] = tab[220 * (ind.j - 4) + (ind.i - 725)];
			ind.j++;
		}
		ind.i++;
	}
}

void			loading_savemess(t_sdl *sdl, t_rt *rt)
{
	t_ind	ind;
	t_col	col1;
	t_col	col2;

	ind.i = 500;
	image_create(sdl->data);
	while (ind.i - 500 < 287)
	{
		ind.j = 730;
		while (ind.j - 730 < 63)
		{
			col1 = int_to_rgb_yatak(sdl->frame[WID * ind.j + ind.i]);
			col2 = int_to_rgb_yatak(sdl->data_savemes[287 * (ind.j - 730) + (ind.i - 500)]);
			col1 = alpha_compositing(col1, col2, 1, 0.5);
			sdl->frame[WID * ind.j + ind.i] = rgb_to_int_yatak(col1);
			ind.j++;
		}
		ind.i++;
	}
	SDL_RenderClear(sdl->ren_ptr);
	SDL_UpdateTexture(sdl->tex_ptr, NULL, sdl->frame, WID * 4);
	SDL_RenderCopy(sdl->ren_ptr, sdl->tex_ptr, NULL, NULL);
	SDL_RenderPresent(sdl->ren_ptr);
	SDL_Delay(100);
	render_loading_frame(sdl, rt);
	first_render(rt);
}

void			render(t_sdl *sdl, t_rt *rt)
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
	copy_bstila(sdl, rt->save_filter);
	SDL_UpdateTexture(sdl->tex_ptr, NULL, sdl->frame, WID * 4);
	SDL_RenderCopy(sdl->ren_ptr, sdl->tex_ptr, NULL, NULL);
	SDL_RenderPresent(sdl->ren_ptr);
}

void			destroy_sdl(t_sdl **s)
{
	t_sdl *sdl;

	sdl = *s;
	SDL_DestroyRenderer(sdl->ren_ptr);
	SDL_DestroyWindow(sdl->win_ptr);
	TTF_Quit();
	SDL_Quit();
	free(sdl);
}
