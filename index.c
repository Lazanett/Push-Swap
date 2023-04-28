/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:11:47 by lazanett          #+#    #+#             */
/*   Updated: 2023/04/28 22:47:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assign_index(t_liste *lst, t_list_param *nb)
{
	t_liste	*temp;
	t_liste	*highest;
	int		valeur;
    int     size_list;
    size_list = nb->size;
    size_list++;
    ft_printf("%d\n", size_list);
	while (--size_list > 0)
	{
		temp = lst;
		valeur = INT_MIN;
		highest = NULL;
		while (temp)
		{
			if (temp->content == INT_MIN && temp->index == 0)
				temp->index = 1;
			if (temp->content > valeur && temp->index == 0)
			{
				valeur = temp->content;
				highest = temp;
				temp = lst;
			}
			else
				temp = temp->next;
		}
		if (highest != NULL)
			highest->index = size_list;
	}
}
/*void ft_assign_index(t_liste **lst, t_list_param *nb)
{
    t_liste *head;
    int i;

    head = *lst;
    i = ft_len_list(*lst);
    ft_get_max(*lst, nb);
    ft_get_min(*lst, nb);
    while ((*lst)->next != NULL)
    {
        if ((*lst)->content == nb->max)
            (*lst)->index = i;
        *lst = (*lst)->next;
    }
    *lst = head;
    i--;
    while (i)
    {
        ft_printf("%d = new max\n", nb->max);
        ft_get_new_max(*lst, nb);
        while ((*lst)->content != nb->new_max)
            *lst = (*lst)->next;
        (*lst)->index = i;
        //printf("i=%d, index=%d, content=%d\n", i, (*lst)->index, (*lst)->content);
        nb->max = nb->new_max;
        ft_printf("%d = new max\n", nb->max);
        i--;
        *lst = head;
    }
}

void ft_get_new_max(t_liste *lst, t_list_param *nb)
{
    int temp;
    t_liste *head;
    
    head = lst;
    ft_get_min(lst, nb);
    temp = nb->min - 1 ;
    
    while (lst->next != NULL)
    {
        if (lst->content < nb->max && lst->content > temp)
            temp = lst->content;
        lst = lst->next;
        
    }
    if (lst->content < nb->max && lst->content > temp)
        temp = lst->content;
    lst = head;    
    nb->new_max = temp;
}*/