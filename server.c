/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 17:51:42 by amorcill          #+#    #+#             */
/*   Updated: 2021/12/29 03:27:27 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

/****
 *  Char = 8 bits
 *  examplo 10101101 = 'x'
 * 
 */

static char	*ft_append_bit(char *start, char c)
{
	size_t	i;
	char	*tmp;

	tmp = malloc(ft_strlen(start) + 2);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	while (start[i] != '\0')
	{
		tmp[i] = start[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(start);
	return (tmp);
}

// converts binary to ascii and prints it
static void	ft_print_bit(char *s)
{
	int				pow;
	unsigned char	c;
	size_t			i;

	pow = 1;
	c = 0;
	i = ft_strlen(s) - 1;
	while (i + 1 != 0)
	{
		c += pow * (s[i] - '0');
		pow *= 2;
		i--;
	}
	write(1, &c, 1);
}

static void ft_handler_minitalk(int sig)
{

	// if (sig == SIGUSR1)
	// 	ft_printf("signal usr1\n");
	// if (sig == SIGUSR2)
	// 	ft_printf("signal usr2\n");
	
	static char	*bits;
	static int	bit_received;

	bit_received++;
	if (bits == NULL)
	{
		bits = ft_strdup("");
		bit_received = 1;
	}
	if (sig == SIGUSR2)
		bits = ft_append_bit(bits, '0');
	else
		bits = ft_append_bit(bits, '1');
	if (bit_received == 8)
	{
		ft_print_bit(bits);
		free(bits);
		bits = NULL;
	}
	
}


int main(void)
{
	pid_t	pid;
	
	pid = getpid();
	ft_printf("Server pid is: %d \n", pid);
	signal(SIGUSR2, ft_handler_minitalk);
	signal(SIGUSR1, ft_handler_minitalk);
	while(1)
	{
		//pause();
		sleep(1);
	}
	return (0);	
}
