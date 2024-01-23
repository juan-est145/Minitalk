/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:10:14 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/05 13:22:37 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ptr_c;
	size_t	length;

	i = 0;
	ptr_c = NULL;
	length = ft_strlen(s);
	while (i <= length)
	{
		if (s[i] == (char)c)
		{
			ptr_c = (char *)&s[i];
			return (ptr_c);
		}
		i++;
	}
	return (ptr_c);
}
