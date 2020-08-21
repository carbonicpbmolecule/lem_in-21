/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 21:57:58 by jirwin            #+#    #+#             */
/*   Updated: 2020/08/11 14:36:20 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	print_step(int id, char *name)
{
	ft_putchar('L');
	ft_putnbr(id);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

void	print_room(char *name, int x, int y)
{
	ft_putstr(name);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

void	print_link(char *name1, char *name2)
{
	ft_putstr(name1);
	ft_putchar('-');
	ft_putstr(name2);
	ft_putchar('\n');
}

void	print_info(t_lst *list)
{
	while (list)
	{
		if (!list->o)
		{
			ft_putstr(list->cont);
			ft_putchar('\n');
		}
		list = list->next;
	}
	ft_putchar('\n');
}

void	error(void)
{
	ft_putstr("ERROR\n");
}
