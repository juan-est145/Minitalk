/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:49:44 by juan-est145       #+#    #+#             */
/*   Updated: 2024/01/24 17:37:58 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

// SIGUSR1 means that the bit is 0 and SIGUSR2 means that the bit is 1

static void	invalid_pid(void)
{
	ft_printf("Invalid PID received, terminating program\n");
	exit(1);
}

static void	bit_converter(unsigned char c, int pid)
{
	int	byte;
	int	sentinel;

	byte = 128;
	while (byte != 0)
	{
		if ((c & byte) == 0)
		{
			sentinel = kill(pid, SIGUSR1);
			ft_printf("Bit equal 0\n");
		}
		else if ((c & byte) != 0)
		{
			sentinel = kill(pid, SIGUSR2);
			ft_printf("Bit equal 1\n");
		}
		if (sentinel == -1)
			invalid_pid();
		byte >>= 1;
		sleep(1);
	}
}

int	main(int argc, char *argv[])
{
	unsigned int	i;
	int				pid;

	i = 0;
	pid = 0;
	if (argc != 3)
	{
		ft_printf("Incorrect number of arguments, need two in total\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
		invalid_pid();
	while (argv[2][i] != '\0')
	{
		bit_converter(argv[2][i], pid);
		i++;
	}
	return (0);
}
