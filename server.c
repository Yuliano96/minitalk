/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypacileo <ypacileo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:21:59 by yuliano           #+#    #+#             */
/*   Updated: 2024/10/26 15:19:52 by ypacileo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signal)
{
	static unsigned char	c_accumulator = 0;
	static int				bit_count = 0;

	if (signal == SIGUSR2)
		c_accumulator = c_accumulator | 1;
	bit_count++;
	if (bit_count == ONE_BYTE)
	{
		write(1, &c_accumulator, 1);
		bit_count = 0;
		c_accumulator = '\0';
	}
	c_accumulator = c_accumulator << 1;
}

int	main(void)
{
	ft_printf("The ID of the server is: %i\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
