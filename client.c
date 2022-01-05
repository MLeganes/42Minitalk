/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 09:53:46 by amorcill          #+#    #+#             */
/*   Updated: 2021/12/30 20:29:46 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_exit_failure(void)
{
	ft_printf("Run the Client with \"./client SERVER_PID MESSAGE\" \n");
	exit (EXIT_FAILURE);
}

static void	ft_post_char(pid_t pid, unsigned char c)
{
	int		i;
	int		mask;

	mask = 128;
	i = 0;
	while (i < 8)
	{
		if ((c & mask) > 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		mask = mask / 2;
		i++;
		usleep(200);
	}
}

void	client(pid_t pid, char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		ft_post_char(pid, (unsigned char)message[i]);
		i++;
	}
	ft_post_char (pid, 255);
}

int	main(int argc, char *argv[])
{	
	pid_t	pid;
	int		res;

	pid = 0;
	if (argc != 3)
		ft_exit_failure();
	else
	{	
		res = ft_atoi_ext(argv[1], &pid);
		if (res == 0)
		{		
			ft_printf("Error to read the server pid\n");
			ft_exit_failure();
		}
		if (ft_strlen(argv[2]) == 0)
		{
			ft_exit_failure();
		}
		ft_printf("Client sending massage to server with pid %d\n", (int)pid);
		client(pid, argv[2]);
	}
	return (0);
}
