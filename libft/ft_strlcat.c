/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:14:38 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/06 18:43:20 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	size_t			src_length;
	size_t			dest_length;

	src_length = ft_strlen(src);
	dest_length = ft_strlen(dst);
	i = 0;
	j = dest_length;
	if (dstsize == 0 || dstsize <= dest_length)
	{
		return (dstsize + src_length);
	}
	while (src[i] != '\0' && i < dstsize - dest_length - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (src_length + dest_length);
}
