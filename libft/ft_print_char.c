/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:32:46 by juestrel          #+#    #+#             */
/*   Updated: 2024/01/24 13:39:46 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(unsigned int args, unsigned int *i)
{
	int	counter;

	counter = 1;
	ft_put_uns_char_fd(args, 1);
	(*i) += 2;
	return (counter);
}
