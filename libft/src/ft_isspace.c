/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acyrenna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 13:16:08 by acyrenna          #+#    #+#             */
/*   Updated: 2020/04/21 13:16:08 by acyrenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	unsigned char ch;

	ch = (unsigned char)c;
	if ((ch >= '\t' && ch <= '\r') || ch == ' ')
		return (1);
	return (0);
}
