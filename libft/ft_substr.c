/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:19:31 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/07 13:13:39 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlcpy_custom(char *dst, char const *src, size_t dstsize)
{
	unsigned int	i;
	size_t			j;

	i = 0;
	j = ft_strlen(src);
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i <= dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}

static char	*ft_fill_substring(char const *s, unsigned int start, size_t len,
		char *substring)
{
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (substring == NULL)
	{
		return (NULL);
	}
	*substring = '\0';
	ft_strlcpy_custom(substring, &s[start], len);
	return (substring);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	str_len;

	substring = NULL;
	str_len = ft_strlen(s);
	if (start >= str_len)
	{
		substring = (char *)malloc(1 * sizeof(char));
		if (substring == NULL)
		{
			return (NULL);
		}
		substring[0] = '\0';
		return (substring);
	}
	else if (len > str_len)
	{
		return (ft_fill_substring(s, start, str_len, substring));
	}
	else
	{
		return (ft_fill_substring(s, start, len, substring));
	}
}
