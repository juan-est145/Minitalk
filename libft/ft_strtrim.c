/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:16:55 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/04 16:55:53 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	search_start(char const *set, int start, char const *s1,
		int s1_length)
{
	while (ft_strchr(set, s1[start]) != NULL && start < s1_length)
	{
		start++;
	}
	return (start);
}

static int	search_end(char const *set, int end, char const *s1)
{
	while (ft_strchr(set, s1[end]) != NULL && end >= 0)
	{
		end--;
	}
	return (end);
}

static char	*ft_completly_trimed(char *result)
{
	result = (char *)malloc(1 * sizeof(char));
	if (result == NULL)
	{
		return (NULL);
	}
	*result = '\0';
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s1_length;
	int		start;
	int		end;
	char	*result;

	s1_length = ft_strlen(s1);
	start = 0;
	end = s1_length - 1;
	result = NULL;
	if (s1 == NULL)
	{
		return (NULL);
	}
	start = search_start(set, start, s1, s1_length);
	if (start == s1_length)
	{
		return (ft_completly_trimed(result));
	}
	end = search_end(set, end, s1);
	result = ft_substr(s1, start, (end - start) + 1);
	return (result);
}
