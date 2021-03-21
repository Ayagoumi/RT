/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoouali <yoouali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 10:28:22 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/21 11:34:39 by yoouali          ###   ########.fr       */
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
	// TTF_Init();
	// sdl->font_p = TTF_OpenFont(\
	// 		"./resources/great-vibes/GreatVibes-Regular.otf", 100);
	// if (!sdl->font_p)
	// 	return (NULL);
	// sdl->font_s = TTF_OpenFont("./resources/lato/Lato-Medium.ttf", 36);
	// if (!sdl->font_s)
	// 	return (NULL);
	// sdl->win_menu = SDL_CreateWindow("menu", 480, 320, 400, 800, 0);
	sdl->win_ptr = SDL_CreateWindow("Rt", SDL_WINDOWPOS_UNDEFINED, \
			SDL_WINDOWPOS_UNDEFINED, WID, HEI, 0);
	sdl->ren_ptr = SDL_CreateRenderer(sdl->win_ptr, -1, 0);
	//sdl->ren_menu = SDL_CreateRenderer(sdl->win_menu, -1, 0);
	sdl->tex_ptr = SDL_CreateTexture(sdl->ren_ptr, SDL_PIXELFORMAT_ARGB8888,
	SDL_TEXTUREACCESS_STREAMING, WID, HEI);
	if (!(sdl->bstila = IMG_Load("bstila.png")))
	{
		printf("dfdf\n");
		exit(0);
	}
	sdl->data_bstila = convert_color((char*)sdl->bstila->pixels, sdl->bstila->w, sdl->bstila->h, sdl->bstila->format->BytesPerPixel);
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

int				re_calc(t_sdl *sdl, SDL_Event event)
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
	printf("filter number: %d \n", filter);
	if (filter >= 0 && filter <= 5)
	{
	printf("chenge frame\n");
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
	//SDL_DestroyRenderer(sdl->ren_menu);
	SDL_DestroyWindow(sdl->win_ptr);
	//SDL_DestroyWindow(sdl->win_menu);
	//TTF_CloseFont(sdl->font_p);
	//TTF_CloseFont(sdl->font_s);
	TTF_Quit();
	SDL_Quit();
	free(sdl);
}
