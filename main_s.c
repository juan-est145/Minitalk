/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-est145 <juan-est145@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:30:01 by juan-est145       #+#    #+#             */
/*   Updated: 2024/01/23 14:17:19 by juan-est145      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_SOURCE // Erase later in Mac

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_stop(int signal)
{
	if (signal == SIGINT)
		printf("Stop signal received");
}

int	main(void)
{
	struct sigaction	sa;
	int					result;

	sa.sa_handler = &ft_stop;
	sigaction(SIGINT, &sa, NULL);
	result = getpid();
	printf("%d\n", result);
	pause();
	return (0);
}
