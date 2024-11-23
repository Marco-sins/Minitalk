/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmembril <mmembril@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:43:18 by marco             #+#    #+#             */
/*   Updated: 2024/10/04 17:52:09 by mmembril         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*aux;
	void	*cont_node;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		cont_node = f(lst->content);
		if (!cont_node)
			return (ft_lstclear(&new, del), NULL);
		aux = ft_lstnew(cont_node);
		if (!aux)
			return (del(cont_node), ft_lstclear(&new, del), NULL);
		ft_lstadd_back(&new, aux);
		lst = lst->next;
	}
	return (new);
}
