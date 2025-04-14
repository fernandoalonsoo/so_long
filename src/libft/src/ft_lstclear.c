/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:11:22 by fealonso          #+#    #+#             */
/*   Updated: 2024/09/25 15:06:52 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	aux = NULL;
	while (*lst != NULL)
	{
		aux = *lst;
		*lst = aux -> next;
		if (del)
			del(aux -> content);
		free(aux);
	}
}
