/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:42:22 by nsiefert          #+#    #+#             */
/*   Updated: 2024/03/06 19:14:12 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	sa_reader(int signum, siginfo_t *info, void *context)
{
	static int	cnt = 8;
	static char	v = 0;
	static char	*str = NULL;

	(void) context;
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
		str = add_str(v, str, info);
		v = 0;
	}
}

void	setup_action(void)
{
	struct sigaction	sa_action_1;

	sigemptyset(&sa_action_1.sa_mask);
	sa_action_1.sa_sigaction = sa_reader;
	sa_action_1.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_action_1, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_action_1, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
}

int	main(void)
{
	setup_action();
	write(1, "PID = ", 6);
	ft_printf("To stop the communication, type 'EndOfComm'\n");
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (have_status(1) == 1)
		sleep(10);
}
