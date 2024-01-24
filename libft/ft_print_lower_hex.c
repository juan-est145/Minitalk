/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:42:54 by juestrel          #+#    #+#             */
/*   Updated: 2024/01/24 13:40:13 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_hex(unsigned int hexa, int *counter)
{
	if (hexa >= 16)
	{
		ft_putnbr_hex(hexa / 16, counter);
		ft_putnbr_hex(hexa % 16, counter);
	}
	else if (hexa <= 15)
	{
		if (hexa <= 9)
		{
			ft_putchar_fd(hexa + '0', 1);
			(*counter)++;
		}
		else if (hexa >= 10)
		{
			ft_putchar_fd((hexa - 10) + 'a', 1);
			(*counter)++;
		}
	}
}

int	ft_print_lower_hex(unsigned int hexa, unsigned int *i)
{
	int	counter;

	counter = 0;
	ft_putnbr_hex(hexa, &counter);
	(*i) += 2;
	return (counter);
}
