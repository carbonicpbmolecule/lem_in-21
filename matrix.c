/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:44:00 by jirwin            #+#    #+#             */
/*   Updated: 2020/08/12 16:15:50 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

char	*get_a(char *s)
{
	char	*a;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (s[len] != '-')
		len++;
	a = (char *)ft_memalloc(sizeof(char) * len + 1);
	while (i < len)
	{
		a[i] = s[i];
		i++;
	}
	a[i] = 0;
	return (a);
}

char	*get_b(char *s)
{
	char	*b;
	int		start;
	int		len;
	int		i;

	start = 0;
	i = 0;
	while (s[start] != '-')
		start++;
	start++;
	len = 0;
	while (s[len + start])
		len++;
	b = (char *)ft_memalloc(sizeof(char) * len + 1);
	while (s[start])
		b[i++] = s[start++];
	b[i] = 0;
	return (b);
}

int		get_coord(t_lem *lem, char *s)
{
	int	k;

	k = 0;
	while (k < lem->number_of_rooms)
	{
		if (!ft_strcmp(lem->rooms[k]->name, s))
			return (k);
		k++;
	}
	return (-1);
}

void	fill(int **m, int j, int i)
{
	m[j][i] = 1;
	m[i][j] = 1;
	m[i][i] = 0;
	m[j][j] = 0;
}

int		fill_matrix(t_lem *lem, t_lst *list)
{
	char	*a;
	char	*b;
	int		j;
	int		i;

	while (list)
	{
		if (list->l)
		{
			a = get_a(list->cont);
			b = get_b(list->cont);
			if (!check_rooms(a, b, lem))
				return (0);
			j = get_coord(lem, a);
			i = get_coord(lem, b);
			ft_strdel(&a);
			ft_strdel(&b);
			fill(lem->matrix, j, i);
		}
		list = list->next;
	}
	return (1);
}
