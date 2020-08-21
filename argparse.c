/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:58:33 by jirwin            #+#    #+#             */
/*   Updated: 2020/08/18 19:41:08 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_lst	*get_first_elem(void)
{
	t_lst	*head;
	char	*line;
	int		ret;

	head = 0;
	if ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
		{
			ft_strdel(&line);
			return (0);
		}
		head = newlst(0);
		head->cont = line;
	}
	else
	{
		ft_strdel(&line);
		return (0);
	}
	return (head);
}

t_lst	*preparse(void)
{
	t_lst	*list;
	t_lst	*head;
	char	*line;
	int		ret;

	if (!(head = get_first_elem()))
		return (0);
	ret = 0;
	list = head;
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
			return (0);
		list->next = newlst(line);
		list = list->next;
	}
	ft_strdel(&line);
	return (head);
}

int		get_number_of_rooms(t_lst *list)
{
	int	res;

	res = 0;
	while (list)
	{
		res += list->r;
		list = list->next;
	}
	return (res);
}

t_lem	*ret_error(t_lst *list, int flag_error)
{
	if (flag_error)
		error();
	rmlst(list);
	return (0);
}

t_lem	*parse(void)
{
	t_lst	*list;
	t_lem	*lem;

	if (!(list = preparse()) || !is_number_of_ants(list->cont))
		return (ret_error(list, 1));
	list->a = 1;
	markup(list);
	if (!postvalid(list))
		return (ret_error(list, 1));
	lem = newlem();
	lem->list = list;
	lem->number_of_ants = ft_atoi(list->cont);
	lem->number_of_rooms = get_number_of_rooms(list);
	lem->rooms = get_rooms(list, lem->number_of_rooms);
	lem->matrix = newmatrix(lem->number_of_rooms);
	if (!fill_matrix(lem, list))
		return (ret_error(list, 1));
	return (lem);
}
