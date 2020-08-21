/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:35:55 by jirwin            #+#    #+#             */
/*   Updated: 2020/08/11 02:51:42 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_room	**newqueue(int size)
{
	t_room	**queue;

	queue = (t_room **)ft_memalloc(sizeof(t_room *) * size);
	return (queue);
}

int		qin(t_room **queue, int size, t_room *room)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (!queue[i])
		{
			queue[i] = room;
			return (1);
		}
		i++;
	}
	return (0);
}

void	qrm(t_room **queue, int size)
{
	int i;

	i = 1;
	while (i < size)
	{
		queue[i - 1] = queue[i];
		i++;
	}
	queue[size - 1] = 0;
}

void	qfree(t_room **queue, int size)
{
	int i;

	i = 0;
	while (i < size)
		free(queue[i++]);
	free(queue);
}
