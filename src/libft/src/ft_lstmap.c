/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fealonso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:25:06 by fealonso          #+#    #+#             */
/*   Updated: 2024/09/25 15:08:44 by fealonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;
	t_list	*list;

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
		aux = ft_lstnew(lst -> content);
		if (!aux)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		aux -> content = f(aux -> content);
		ft_lstadd_back(&list, aux);
		lst = lst-> next;
	}
	return (list);
}
