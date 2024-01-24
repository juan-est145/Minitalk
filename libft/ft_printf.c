/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:26:26 by juestrel          #+#    #+#             */
/*   Updated: 2024/01/24 13:42:40 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_var(unsigned int *i, int *counter, char const *str,
		va_list args)
{
	if (str[*i] == '%' && str[*i + 1] == 'c')
		*counter += ft_print_char(va_arg(args, unsigned int), i);
	else if (str[*i] == '%' && str[*i + 1] == 's')
		*counter += ft_print_string(va_arg(args, char *), i);
	else if (str[*i] == '%' && (str[*i + 1] == 'i' || str[*i + 1] == 'd'))
		*counter += ft_print_base10(va_arg(args, int), i);
	else if (str[*i] == '%' && (str[*i + 1] == 'u'))
		*counter += ft_print_uns_base10(va_arg(args, unsigned int), i);
	else if (str[*i] == '%' && str[*i + 1] == 'x')
		*counter += ft_print_lower_hex(va_arg(args, unsigned int), i);
	else if (str[*i] == '%' && str[*i + 1] == 'X')
		*counter += ft_print_upper_hex(va_arg(args, unsigned int), i);
	else if (str[*i] == '%' && str[*i + 1] == 'p')
		*counter += ft_print_ptr(va_arg(args, void *), i);
	else if (str[*i] == '%' && str[*i + 1] == '%')
		*counter += ft_print_percentage('%', i);
}

int	ft_printf(char const *str, ...)
{
	va_list			args;
	unsigned int	i;
	int				counter;

	va_start(args, str);
	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_print_var(&i, &counter, str, args);
		}
		else if (str[i] != '\0' && str[i] != '%')
		{
			ft_put_uns_char_fd(str[i], 1);
			counter++;
			i++;
		}
	}
	va_end(args);
	return (counter);
}
