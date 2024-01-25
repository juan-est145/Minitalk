/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:30:01 by juan-est145       #+#    #+#             */
/*   Updated: 2024/01/25 12:53:15 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

// SIGUSR1 means that the bit is 0 and SIGUSR2 means that the bit is 1

static void	ft_signal_handler(int signal)
{
	static unsigned int		counter = 0;
	static int				bits = 128;
	static unsigned char	letter = '\0';

	if (signal == SIGUSR1)
	{
		counter++;
	}
	else if (signal == SIGUSR2)
	{
		letter = (bits >> counter) ^ letter;
		counter++;
	}
	if (counter == 8)
	{
		write(1, &letter, 1);
		counter = 0;
		letter = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					result;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_handler = &ft_signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	result = getpid();
	ft_printf("%d\n", result);
	while (1)
	{
		pause();
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
	}
	return (0);
}

// Everytime that the signal has been handled by a custom handler,
// the default handler is restored.
// In order to avoid this, we need to redifine later in the
// code the custom signal handler with sigaction.

/*
sigaction(SIGINT, &sa, NULL);
	while (1)
	{
		pause();
		sigaction(SIGINT, &sa, NULL);
		//sleep(2);
	}
	return (0);
}*/