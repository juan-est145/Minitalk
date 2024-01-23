/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:50:59 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/05 13:24:29 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ptr_c;

	i = ft_strlen(s);
	ptr_c = NULL;
	while (i > 0)
	{
		if (s[i] == (char)c)
		{
			ptr_c = (char *)&s[i];
			return (ptr_c);
		}
		i--;
	}
	if (s[i] == (char)c)
	{
		ptr_c = (char *)&s[i];
	}
	return (ptr_c);
}
