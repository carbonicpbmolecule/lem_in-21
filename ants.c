/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 22:25:28 by jirwin            #+#    #+#             */
/*   Updated: 2020/08/11 14:09:10 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		get_hardes_path(t_lst_paths *paths)
{
	t_lst_paths	*p;
	int			max;

	p = paths;
	max = 0;
	while (p)
	{
		if ((p->path->len + p->path->ants_num) > max)
			max = p->path->len + p->path->ants_num;
		p = p->next;
	}
	return (max);
}

void	many_paths(t_path **ants, int number_of_ants, t_lst_paths *paths)
{
	t_path		*shortest_path;
	t_lst_paths	*p;
	int			min;
	int			i;

	shortest_path = 0;
	i = -1;
	while (++i < number_of_ants)
	{
		p = paths;
		min = get_hardes_path(paths);
		while (p)
		{
			if ((p->path->len + p->path->ants_num) < min)
			{
				min = p->path->len + p->path->ants_num;
				shortest_path = p->path;
			}
			p = p->next;
		}
		ants[i] = shortest_path;
		ants[i]->ants_num++;
	}
}

void	init_ants(t_path **ants, int number_of_ants, t_lst_paths *paths)
{
	int			min;
	t_lst_paths	*p;
	t_path		*shortest_path;
	int			i;

	p = paths;
	if (p->next == 0)
	{
		i = 0;
		while (i < number_of_ants)
		{
			ants[i++] = paths->path;
			paths->path->ants_num++;
		}
	}
	else
		many_paths(ants, number_of_ants, paths);
}

void	run_ants(int number_of_ants, t_lst_paths *paths)
{
	t_path	**ants;
	int		*finished;
	t_room	*end;
	int		i;

	ants = (t_path**)ft_memalloc(sizeof(t_path*) * number_of_ants);
	finished = (int*)ft_memalloc(sizeof(int) * number_of_ants);
	init_ants(ants, number_of_ants, paths);
	end = paths->path->rooms[paths->path->len - 1];
	while (end->ant != number_of_ants)
	{
		step(ants, number_of_ants, finished, end);
		ft_putchar('\n');
	}
	free(ants);
	free(finished);
}
