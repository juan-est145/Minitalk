/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base10.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:16:28 by juestrel          #+#    #+#             */
/*   Updated: 2024/01/24 13:39:14 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_base10(int number, unsigned int *i)
{
	char	*str_number;
	int		counter;

	str_number = ft_itoa(number);
	counter = ft_print_string(str_number, i);
	if (str_number != NULL)
	{
		free(str_number);
	}
	return (counter);
}
