/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 23:16:14 by aeddaqqa          #+#    #+#             */
/*   Updated: 2021/03/29 12:54:41 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	syntax_err(t_rt *rt, char *file)
{
	destroy(SYNTAX_ERROR);
	free_rt(&rt);
	free(file);
	exit(0);
}

void	err2(char **av, t_rt *rt, char *file, char *ex)
{
	if (!ft_strcmp(ex, ".xml"))
	{
		if (!(file = load_file(av[1])))
		{
			free_rt(&rt);
			exit(0);
		}
		if (!(parse(file, rt)))
			syntax_err(rt, file);
		free(file);
	}
	else if (!ft_strcmp(".obj", ex))
	{
		if (!(parse_obj(rt, av[1])))
		{
			free_rt(&rt);
			exit(0);
		}
	}
	else
	{
		free_rt(&rt);
		exit(0);
	}
}

void	err(char **av, t_rt *rt, char *file)
{
	char *ex;

	ex = ft_strrchr(av[1], '.');
	if (!ex)
		exit(0);
	if (!(rt = init_rt()))
		destroy(MALLOC_ERROR);
	err2(av, rt, file, ex);
	new_camera(rt);
	rt->sdl = init_sdl();
	rt->save_filter = 7;
	rtrace(rt);
	free_rt(&rt);
}

int		main(int ac, char **av)
{
	char *file;
	t_rt *rt;

	file = NULL;
	rt = NULL;
	if (ac == 2)
		err(av, rt, file);
	else
		ft_putendl("./rt [fileName]");
	return (EXIT_SUCCESS);
}
