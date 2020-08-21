/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:02:14 by jirwin            #+#    #+#             */
/*   Updated: 2020/08/11 18:52:10 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_lst	*newlst(char *cont)
{
	t_lst *list;

	list = (t_lst *)ft_memalloc(sizeof(t_lst));
	list->cont = cont;
	return (list);
}

t_lem	*newlem(void)
{
	t_lem *lem;

	lem = (t_lem *)ft_memalloc(sizeof(t_lem));
	return (lem);
}

t_room	**newarr(int len)
{
	t_room **arr;

	arr = (t_room **)ft_memalloc(sizeof(t_room *) * len);
	return (arr);
}

t_room	*newroom(char *info)
{
	t_room *room;

	room = (t_room *)ft_memalloc(sizeof(t_room));
	parseroom(room, info);
	return (room);
}

int		**newmatrix(int size)
{
	int **matrix;
	int i;

	matrix = (int **)ft_memalloc(sizeof(int *) * size);
	i = 0;
	while (i < size)
		matrix[i++] = (int *)ft_memalloc(sizeof(int) * size);
	return (matrix);
}
