/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan_est145 <juan_est145@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:32:10 by juestrel          #+#    #+#             */
/*   Updated: 2023/12/22 11:35:10 by juan_est145      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strlcat_custom(char *dst, char src, size_t dstsize)
{
	size_t	dest_length;

	dest_length = ft_strlen(dst);
	if (dstsize < dest_length)
	{
		return ;
	}
	dst[dest_length] = src;
	dest_length++;
	dst[dest_length] = '\0';
}

static void	ft_putnbr(int nb, char *result)
{
	char	current_number;

	if (nb == -2147483648)
	{
		ft_strlcpy(result, "-2", sizeof("-2"));
		ft_putnbr(147483648, result);
	}
	else if (nb < 0)
	{
		ft_strlcpy(result, "-", sizeof("-"));
		nb = -nb;
		ft_putnbr(nb, result);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10, result);
		ft_putnbr(nb % 10, result);
	}
	else
	{
		current_number = nb + 48;
		ft_strlcat_custom(result, current_number, ft_strlen(result));
	}
}

static char	*ft_fill_string(int n, char *result)
{
	if (n == 0)
	{
		ft_strlcpy(result, "0", sizeof("0"));
		return (result);
	}
	else
	{
		ft_putnbr(n, result);
	}
	return (result);
}

static int	ft_amount_of_numbers(int n)
{
	int	counter;

	counter = 0;
	if (n == 0)
	{
		counter = 1;
		return (counter);
	}
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size_of_int;

	size_of_int = ft_amount_of_numbers(n);
	if (n < 0)
	{
		size_of_int++;
	}
	result = (char *)malloc((size_of_int + 1) * sizeof(char));
	if (result == NULL)
	{
		return (NULL);
	}
	*result = '\0';
	result = ft_fill_string(n, result);
	return (result);
}
