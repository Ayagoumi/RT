/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:43:59 by ayagoumi          #+#    #+#             */
/*   Updated: 2021/03/28 18:22:35 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

bool	is_zero(double x)
{
	if (x > -EQN_EPS && x < EQN_EPS)
		return (true);
	return (false);
}
