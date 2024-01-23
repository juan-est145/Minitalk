/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:02:02 by juestrel          #+#    #+#             */
/*   Updated: 2023/11/29 13:24:47 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_fbackspace(char *string, int *i)
{
	while (string[*i] != '\0')
	{
		if (string[*i] == ' ' || string[*i] == '\t')
		{
			(*i)++;
		}
		else if (string[*i] == '\n' || string[*i] == '\v')
		{
			(*i)++;
		}
		else if (string[*i] == '\f' || string[*i] == '\r')
		{
			(*i)++;
		}
		else
		{
			break ;
		}
	}
	return (*i);
}

static int	ft_minusoperator(char *string, int *i)
{
	if (string[*i] == '+')
	{
		(*i)++;
	}
	else if (string[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		result;
	int		minus_operator;
	char	*string;

	i = 0;
	result = 0;
	string = (char *)str;
	ft_fbackspace(string, &i);
	minus_operator = ft_minusoperator(string, &i);
	while (string[i] != '\0')
	{
		if (string[i] >= '0' && string[i] <= '9')
		{
			result = (result * 10) + (str[i] - 48);
		}
		else if (!(string[i] >= '0' && string[i] <= '9'))
		{
			return (result *= minus_operator);
		}
		i++;
	}
	return (result *= minus_operator);
}
