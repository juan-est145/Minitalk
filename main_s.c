/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juestrel <juestrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:30:01 by juan-est145       #+#    #+#             */
/*   Updated: 2024/01/24 15:26:50 by juestrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void	ft_stop(int signal)
{
	if (signal == SIGINT)
		printf("Stop signal received\n");
}

int	main(void)
{
	struct sigaction	sa;
	int					result;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
	sa.sa_handler = &ft_stop;
	sigaction(SIGINT, &sa, NULL);
	result = getpid();
	printf("%d\n", result);
	while (1)
	{
		pause();
		sigaction(SIGINT, &sa, NULL);
	}
	return (0);
}

//Everytime that the signal has been handled by a custom handler, 
//the default handler is restored. 
//In order to avoid this, we need to redifine later in the 
//code the custom signal handler with sigaction.

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