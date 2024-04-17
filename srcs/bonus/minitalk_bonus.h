/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:29:48 by nsiefert          #+#    #+#             */
/*   Updated: 2024/03/06 18:56:27 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define WAIT_TIME 1000

# include <signal.h>
# include "../libft/include/libft.h"

int		have_status(int a);
char	*add_str(char c, char *str, siginfo_t *info);
void	print_list(char *str);
void	encoding_send(int c, pid_t pid);
void	handle_errors(char *s);

#endif