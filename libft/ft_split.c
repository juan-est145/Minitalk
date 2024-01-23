/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:52:59 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/07 13:45:38 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i] != '\0' && s[i])
	{
		if (i != 0)
		{
			if (s[i] == c && s[i - 1] != c && i > 0)
			{
				word_count++;
			}
		}
		i++;
	}
	if (s[0] != '\0' && s[0] && s[i - 1] != c)
	{
		word_count++;
	}
	return (word_count);
}

static char	*ft_substr_custom(char const *s, unsigned int start, size_t len)
{
	char	*substring;

	substring = NULL;
	if (substring != NULL)
	{
		free(substring);
	}
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (substring == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(substring, &s[start], len + 1);
	return (substring);
}

static void	ft_fill_strings(char **result, char const *s, char c)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (s[i] != '\0' && s[i])
	{
		if ((i == 0 && s[i] == c) || (s[i] == c && s[i - 1] != c))
		{
			if (i - start != 0)
			{
				*result = ft_substr_custom(s, start, (i - start));
				result += 1;
			}
			start = i + 1;
		}
		else if (s[i] == c && s[i - 1] == c)
			start++;
		i++;
	}
	if (s[i - 1] != c)
		*result = ft_substr_custom(s, start, (i - start));
	if (s[i - 1] != c)
		result += 1;
	*result = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**result;

	if (s == NULL)
	{
		return (NULL);
	}
	word_count = ft_word_count(s, c);
	if (word_count == 0)
	{
		result = (char **)malloc(1 * (sizeof(char *)));
		if (result == NULL)
			return (NULL);
		*result = NULL;
		return (result);
	}
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	ft_fill_strings(result, s, c);
	return (result);
}
