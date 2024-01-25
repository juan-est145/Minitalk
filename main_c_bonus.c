/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:49:44 by juan-est145       #+#    #+#             */
/*   Updated: 2024/01/25 14:49:13 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

int signal_received = 0;
// SIGUSR1 means that the bit is 0 and SIGUSR2 means that the bit is 1

static void	ft_signal_handler(int signum)
{
	if (signum == SIGUSR1)
		signal_received = 1;
	if (signum == SIGUSR2)
	{
		ft_printf("Error from server, exiting\n");
		exit(1);
	}		
}

static void	invalid_pid(void)
{
	ft_printf("Invalid PID received, terminating program\n");
	exit(1);
}

static void	bit_converter(unsigned char c, int pid)
{
	int	byte;
	int	sentinel;
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_handler = &ft_signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	byte = 128;
	while (byte != 0)
	{
		if ((c & byte) == 0)
			sentinel = kill(pid, SIGUSR1);
		else if ((c & byte) != 0)
			sentinel = kill(pid, SIGUSR2);
		if (sentinel == -1)
			invalid_pid();
		byte >>= 1;
		while (signal_received != 1)
		{
			//pause();
			sigaction(SIGUSR1, &sa, NULL);
			sigaction(SIGUSR2, &sa, NULL);
		}
		signal_received = 0;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	unsigned int		i;
	int					pid;
	
	//signal(SIGUSR1, ft_signal_handler);
	//signal(SIGUSR2, ft_signal_handler);
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
	/*while (1)
	{
		pause();
		sigaction(SIGUSR1, &sa, NULL);
		//sigaction(SIGUSR2, &sa, NULL);
	}*/
	return (0);
}
