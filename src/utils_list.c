/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:13:01 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/03 17:23:23 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_liste	*ft_lstnew_p(int content)
{
	t_liste	*new;

	new = (t_liste *)malloc(sizeof(t_liste));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_liste	*ft_lstlast_p(t_liste *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_liste	*ft_lst_before_last(t_liste *lst)
{
	while (lst && lst->next && lst->next->next != NULL)
		lst = lst->next;
	return (lst);
}

t_liste	*get_stack_bottom(t_liste *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_p(t_liste **lst, t_liste *new)
{
	t_liste	*nv;

	if (!*lst)
		*lst = new;
	else
	{
		nv = ft_lstlast_p(*lst);
		nv->next = new;
	}
}
