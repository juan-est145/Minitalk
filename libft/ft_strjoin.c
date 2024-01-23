/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:45:58 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/01 12:40:54 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_s1;
	int		size_s2;
	char	*str_joined;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	str_joined = (char *)malloc((size_s1 + size_s2 + 1) * sizeof(char));
	if (str_joined == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(str_joined, s1, size_s1 + 1);
	ft_strlcat(str_joined, s2, size_s1 + size_s2 + 1);
	return (str_joined);
}
