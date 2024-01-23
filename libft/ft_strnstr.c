/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan_est145 <juan_est145@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:43:51 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/22 11:35:53 by juan_est145      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strncmp_custom(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' && s2[i] != '\0') && i < n)
	{
		if ((unsigned char)s1[i] > (unsigned char)s2[i])
		{
			return (1);
		}
		else if ((unsigned char)s1[i] < (unsigned char)s2[i])
		{
			return (-1);
		}
		i++;
	}
	if (i != ft_strlen(s2))
	{
		return (-1);
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	counter;

	counter = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (*haystack != '\0' && counter < len)
	{
		if ((*haystack == *needle) && (ft_strncmp_custom(haystack, needle, len
					- counter) == 0))
		{
			return ((char *)haystack);
		}
		else
		{
			haystack++;
			counter++;
		}
	}
	return (NULL);
}
