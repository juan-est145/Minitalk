/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:44:48 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/01 12:37:19 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	str_length;
	char	*str_copy;

	str_length = ft_strlen(s1);
	str_copy = (char *)malloc((str_length + 1) * sizeof(char));
	if (str_copy == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(str_copy, s1, str_length + 1);
	return (str_copy);
}
