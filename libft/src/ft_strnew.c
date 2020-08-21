/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jirwin <jirwin@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:16:50 by acyrenna          #+#    #+#             */
/*   Updated: 2020/07/22 18:18:06 by jirwin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size + 1 == 0)
		return (0);
	if ((str = (char *)malloc(size + 1)))
	{
		ft_bzero(str, size + 1);
		return (str);
	}
	else
		return (NULL);
}
