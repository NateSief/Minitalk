/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsiefert <nsiefert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:36:52 by nsiefert          #+#    #+#             */
/*   Updated: 2024/03/05 07:38:36 by nsiefert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*to_return;
	void	*value;

	to_return = NULL;
	to_return = (t_list *)malloc(sizeof(t_list));
	value = ft_strdup((const char *)content);
	if (!to_return || !value)
		return (NULL);
	to_return->content = value;
	to_return->next = NULL;
	return (to_return);
}
