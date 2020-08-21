/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:21:05 by jirwin            #+#    #+#             */
/*   Updated: 2020/08/11 14:10:38 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		get_cur(t_lem *lem, t_room **queue)
{
	int cur;
	int i;

	cur = 0;
	i = 0;
	while (i < lem->number_of_rooms)
	{
		if (lem->rooms[i]->name == queue[0]->name)
			cur = i;
		i++;
	}
	return (cur);
}

int		uzero(int *used, int size)
{
	int i;

	i = 0;
	while (i < size)
		used[i++] = 0;
	return (0);
}

int		bfs(t_lem *lem)
{
	t_room	**queue;
	int		used[lem->number_of_rooms];
	int		cur;
	int		flag;
	int		i;

	queue = newqueue(lem->number_of_rooms);
	flag = uzero(used, lem->number_of_rooms);
	used[0] = qin(queue, lem->number_of_rooms, lem->rooms[0]);
	while (queue[0])
	{
		cur = get_cur(lem, queue);
		flag += (queue[0] == lem->rooms[lem->number_of_rooms - 1]);
		qrm(queue, lem->number_of_rooms);
		i = -1;
		while (++i < lem->number_of_rooms)
			if (lem->matrix[cur][i] && !used[i])
			{
				qin(queue, lem->number_of_rooms, lem->rooms[i]);
				lem->rooms[i]->steps = lem->rooms[cur]->steps + 1;
				used[i] = 1;
			}
	}
	qfree(queue, lem->number_of_rooms);
	return (flag);
}
