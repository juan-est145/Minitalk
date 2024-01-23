/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:49:44 by juan-est145       #+#    #+#             */
/*   Updated: 2024/01/23 19:40:23 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

//SIGUSR1 means that the bit is 0 and SIGUSR2 means that the bit is 1

static void	bit_converter(unsigned char c, int pid)
{
	int	byte;

	byte = 128;
	while (byte != 0)
	{
		if ((c & byte) == 0)
			kill(pid, SIGUSR1);
		else if ((c & byte) != 0)
			kill(pid, SIGUSR2);
		byte >>= 1;
	}
}

int	main(int argc, char *argv[])
{
	unsigned int	i;
	int				pid;

	i = 0;
	pid = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			bit_converter(argv[2][i], pid);
			i++;
		}
	}
	return (0);
}
