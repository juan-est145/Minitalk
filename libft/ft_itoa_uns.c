/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:48:40 by juestrel          #+#    #+#             */
/*   Updated: 2024/01/24 13:43:37 by juestrel         ###   ########.fr       */
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

static void	ft_putnbr(unsigned int nb, char *result)
{
	char	current_number;

	if (nb > 9)
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

static char	*ft_fill_string(unsigned int n, char *result)
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

static unsigned int	ft_amount_of_numbers(unsigned int n)
{
	unsigned int	counter;

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

char	*ft_itoa_uns(unsigned int n)
{
	char			*result;
	unsigned int	size_of_int;

	size_of_int = ft_amount_of_numbers(n);
	result = (char *)malloc((size_of_int + 1) * sizeof(char));
	if (result == NULL)
	{
		return (NULL);
	}
	*result = '\0';
	result = ft_fill_string(n, result);
	return (result);
}
