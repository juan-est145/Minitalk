/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percentage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:33:18 by juestrel          #+#    #+#             */
/*   Updated: 2024/01/24 13:40:37 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_percentage(char c, unsigned int *i)
{
	int	counter;

	counter = 1;
	ft_putchar_fd(c, 1);
	(*i) += 2;
	return (counter);
}
