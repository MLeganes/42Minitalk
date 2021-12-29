/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:51:42 by amorcill          #+#    #+#             */
/*   Updated: 2021/12/29 17:40:55 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_minitalk	g_mt;

static void	ft_init_char(void)
{
	g_mt.character = 0;
	g_mt.bits = 0;
	g_mt.mask = 128;
}

static void	ft_handler_minitalk(int sig)
{
	g_mt.bits++;
	if (sig == SIGUSR1)
	{
		g_mt.character = g_mt.character | g_mt.mask;
		g_mt.mask = g_mt.mask / 2;
	}
	else
	{
		g_mt.mask = g_mt.mask / 2;
	}	
	if (g_mt.bits == 8)
	{
		if (g_mt.character == 255)
			write(1, "\n", 1);
		else
			write(1, &g_mt.character, 1);
		ft_init_char();
	}
}

void	server(void)
{
	ft_init_char();
	signal(SIGUSR2, ft_handler_minitalk);
	signal(SIGUSR1, ft_handler_minitalk);
	while (1)
	{
		sleep(1);
	}
	return ;
}

int	main(void)
{
	g_mt.pid = getpid();
	ft_printf("Server pid is: %d \n", g_mt.pid);
	server();
	return (0);
}
