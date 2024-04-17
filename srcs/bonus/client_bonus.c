/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:42:50 by nsiefert          #+#    #+#             */
/*   Updated: 2024/03/06 19:13:53 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	client_recep(int signum)
{
	(void)signum;
	ft_printf("Sended and printed !\n");
	exit(0);
}

void	setup_action_client(void)
{
	struct sigaction	sa_client_action;

	sigemptyset(&sa_client_action.sa_mask);
	sa_client_action.sa_handler = client_recep;
	sa_client_action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_client_action, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
}

int	main(int ac, char **av)
{
	char	*s;
	pid_t	pid;

	if (ac != 3)
		return (1);
	pid = ft_atoi(av[1]);
	s = av[2];
	if (!pid)
		return (1);
	setup_action_client();
	while (*s)
	{
		encoding_send(*(s++), pid);
		usleep(WAIT_TIME);
	}
	encoding_send(0, pid);
	sleep(10);
	return (0);
}
