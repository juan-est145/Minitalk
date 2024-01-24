/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:49:10 by juestrel          #+#    #+#             */
/*   Updated: 2024/01/24 13:40:57 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_hex_long(unsigned long hexa, int *counter)
{
	if (hexa >= 16)
	{
		ft_putnbr_hex_long(hexa / 16, counter);
		ft_putnbr_hex_long(hexa % 16, counter);
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

int	ft_print_ptr(void *decimal_ptr, unsigned int *i)
{
	int	counter;

	ft_putstr_fd("0x", 1);
	counter = 2;
	if (decimal_ptr == NULL)
	{
		ft_putchar_fd('0', 1);
		counter++;
		(*i) += 2;
		return (counter);
	}
	ft_putnbr_hex_long((unsigned long)decimal_ptr, &counter);
	(*i) += 2;
	return (counter);
}
