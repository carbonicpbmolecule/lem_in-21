/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:15:56 by jirwin            #+#    #+#             */
/*   Updated: 2020/08/12 18:14:32 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		find_this_room(char *name, t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->number_of_rooms)
	{
		if (ft_strcmp(lem->rooms[i]->name, name) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		check_rooms(char *a, char *b, t_lem *lem)
{
	if (!find_this_room(a, lem) || !find_this_room(b, lem))
	{
		ft_strdel(&a);
		ft_strdel(&b);
		rmlem(lem);
		return (0);
	}
	return (1);
}
