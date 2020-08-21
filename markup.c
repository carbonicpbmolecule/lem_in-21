/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:22:35 by jirwin            #+#    #+#             */
/*   Updated: 2020/08/12 16:23:13 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	markup(t_lst *list)
{
	while (list)
	{
		if (is_room(list->cont))
			list->r = 1;
		else if (is_link(list->cont))
			list->l = 1;
		else if (list->cont[0] == '#' && list->cont[1] != '#')
			list->c = 1;
		else if (!ft_strcmp("##start", list->cont))
		{
			list->s = 1;
			if (list->next && is_room(list->next->cont))
				list->next->s = 1;
		}
		else if (!ft_strcmp("##end", list->cont))
		{
			list->e = 1;
			if (list->next && is_room(list->next->cont))
				list->next->e = 1;
		}
		else if (list->cont[0] == '#' && list->cont[1] == '#')
			list->o = 1;
		list = list->next;
	}
}
