/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:51:21 by jirwin            #+#    #+#             */
/*   Updated: 2020/08/19 15:37:26 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int	main(void)
{
	t_lem		*lem;
	t_lst_paths	*paths;

	if (!(lem = parse()))
		return (1);
	if (bfs(lem))
		print_info(lem->list);
	else
	{
		error();
		rmlst(lem->list);
		rmlem(lem);
		return (1);
	}
	rmlst(lem->list);
	paths = get_paths(lem);
	lem->rooms[0]->ant = lem->number_of_ants;
	run_ants(lem->number_of_ants, paths);
	rmpaths(paths);
	rmlem(lem);
	return (0);
}
