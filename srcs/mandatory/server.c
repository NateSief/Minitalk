/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:40:48 by nsiefert          #+#    #+#             */
/*   Updated: 2024/03/06 18:59:26 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sa_reader(int signum)
{
	static int	cnt = 8;
	static char	v = 0;
	static char	*str = NULL;

	cnt--;
	if (signum == SIGUSR1)
	{
		v <<= 1;
		v |= 0b00000001;
	}
	if (signum == SIGUSR2)
		v <<= 1;
	if (!cnt)
	{
		cnt = 8;
		str = add_str(v, str);
		v = 0;
	}
}

void	setup_action(void)
{
	struct sigaction	sa_action_1;

	sigemptyset(&sa_action_1.sa_mask);
	sa_action_1.sa_handler = sa_reader;
	sa_action_1.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa_action_1, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_action_1, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
}

int	main(void)
{
	printf("To stop the program, just type 'EndOfComm' !\n");
	printf("PID = %d\n", getpid());
	setup_action();
	while (have_status(1) == 1)
		sleep(10);
}
