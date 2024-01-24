/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns_base10.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:45:11 by juestrel          #+#    #+#             */
/*   Updated: 2024/01/24 13:41:47 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_uns_base10(unsigned int number, unsigned int *i)
{
	char	*str_number;
	int		counter;

	str_number = ft_itoa_uns(number);
	counter = ft_print_string(str_number, i);
	if (str_number != NULL)
	{
		free(str_number);
	}
	return (counter);
}
