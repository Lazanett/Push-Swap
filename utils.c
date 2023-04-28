/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:44:12 by lazanett          #+#    #+#             */
/*   Updated: 2023/04/21 16:07:35 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_lstadd_front_p(t_liste **lst, t_liste *new) 
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}


void	ft_lstdelone_p(t_liste *lst) 
{
	if (lst == NULL)
		return ;
	if (lst)
		free(lst);
}

void	ft_free(char **free_me)
{
	int		i;

	i = 0;
	while (free_me[i])
	{
		free(free_me[i]);
		i++;
	}
	free(free_me);
}

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}