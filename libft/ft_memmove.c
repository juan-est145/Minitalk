/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:46:23 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/05 13:02:15 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_front_to_back(size_t len, char const *source, char *destiny)
{
	size_t		i;
	char		temp;

	i = 0;
	while (i < len)
	{
		temp = source[i];
		destiny[i] = temp;
		i++;
	}
}

static void	ft_back_to_front(size_t len, char const *source, char *destiny)
{
	size_t		i;
	char		temp;

	i = len;
	while (i > 0)
	{
		temp = source[i - 1];
		destiny[i - 1] = temp;
		i--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char const	*source;
	char		*destiny;

	source = src;
	destiny = dst;
	if (dst == src)
	{
		return (dst);
	}
	else if (destiny < source)
	{
		ft_front_to_back(len, source, destiny);
	}
	else if (destiny > source)
	{
		ft_back_to_front(len, source, destiny);
	}
	return (dst);
}
