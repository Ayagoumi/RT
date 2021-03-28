/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objfile2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:51:27 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/28 18:31:06 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

double			f_rand(double f_min, double f_max)
{
	double	f;

	f = (double)rand() / RAND_MAX;
	return (f_min + f * (f_max - f_min));
}

void			test_obj(t_stk *w, t_point *tab, int j)
{
	if (!w->obj)
	{
		w->obj = (t_object *)new_object(TRIANGLE);
		w->obj->type = TRIANGLE;
		w->obj->point_a = tab[ft_atoi(w->split[1]) - 1];
		w->obj->point_b = tab[ft_atoi(w->split[2]) - 1];
		w->obj->point_c = tab[ft_atoi(w->split[3]) - 1];
		w->obj->color = (t_color){1.0, 1.0, 1.0};
		w->obj->next = NULL;
		w->tmp = w->obj;
	}
	else
	{
		w->tmp->next = (t_object *)new_object(TRIANGLE);
		w->tmp->next->type = TRIANGLE;
		w->tmp->next->point_a = tab[ft_atoi(w->split[1]) - 1];
		w->tmp->next->point_b = tab[ft_atoi(w->split[2]) - 1];
		w->tmp->next->point_c = tab[ft_atoi(w->split[3]) - 1];
		w->tmp->next->color = (t_color){f_rand(1.0, 0.0), \
			f_rand(1.0, 0.0), f_rand(1.0, 0.0)};
		w->tmp->next->next = NULL;
		w->tmp = w->tmp->next;
	}
	free_tab2(&w->split, j);
}
