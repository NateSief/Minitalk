/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:29:38 by nsiefert          #+#    #+#             */
/*   Updated: 2024/03/06 19:28:55 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	have_status(int a)
{
	static int	return_value = 1;

	if (a == 0)
		return_value = 0;
	return (return_value);
}

void	print_list(char *str)
{
	if (!ft_strncmp(str, "EndOfComm", ft_strlen(str)))
		have_status(0);
	else
		ft_printf("✍️ Message : %s\n", str);
	free (str);
}

char	*add_str(char c, char *str, siginfo_t *info)
{
	size_t	length;
	char	*new_str;

	if (!str)
		length = 0;
	else
		length = ft_strlen(str);
	new_str = (char *)malloc((length + 2) * sizeof(char));
	if (!new_str)
		handle_errors("Memory allocation failed in add_str\n");
	if (str)
	{
		ft_strlcpy(new_str, str, length + 2);
		free(str);
	}
	new_str[length] = c;
	new_str[length + 1] = '\0';
	if (c == 0)
	{
		kill(info->si_pid, SIGUSR1);
		return (print_list(new_str), NULL);
	}
	else
		return (new_str);
}

void	encoding_send(int c, pid_t pid)
{
	int	bits;

	bits = 8;
	while (bits--)
	{
		if (c & 0b10000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c <<= 1;
		usleep(WAIT_TIME);
	}
}

void	handle_errors(char *s)
{
	ft_putstr_fd(s, 2);
	exit(0);
}
