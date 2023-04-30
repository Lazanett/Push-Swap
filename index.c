/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:11:47 by lazanett          #+#    #+#             */
/*   Updated: 2023/04/30 12:29:42 by marvin           ###   ########.fr       */
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