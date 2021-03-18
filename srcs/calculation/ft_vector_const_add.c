/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_const_add.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:27:59 by chzabakh          #+#    #+#             */
/*   Updated: 2021/03/05 18:28:11 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vect3	v_c_add(t_vect3 u, double v)
{
	t_vect3	w;

	w.x = u.x + v;
	w.y = u.y + v;
	w.z = u.z + v;
	return (w);
}
