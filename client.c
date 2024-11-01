/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:43:27 by yuliano           #+#    #+#             */
/*   Updated: 2024/10/26 18:49:35 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *s)
{
	size_t	i;
	long	number;
	int		sign;

	i = 0;
	sign = 1;
	number = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\r' || s[i] == '\v' || s[i] == '\f' )
		i++;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		number = number * 10 + s[i] - 48;
		i++;
	}
	return (number * sign);
}

void	check_kill(int pid, int signal)
{
	if (kill(pid, signal) == -1)
	{
		ft_printf("Error, delivering signal\n");
		exit(EXIT_FAILURE);
	}
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			check_kill(pid, SIGUSR2);
		else
			check_kill(pid, SIGUSR1);
		usleep(1500);
		i--;
	}
}

void	send_message(int pid, char *message)
{
	while (*message)
	{
		send_char(pid,*message);
		message++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Error, wrong number of arguments\n");
		return (1);
	}
	else
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			ft_printf("Error, wrong process ID\n");
			return (1);
		}
		send_message(pid, argv[2]);
		send_char(pid, '\n');
	}
	return (0);
}
