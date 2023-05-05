/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:11:47 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/03 17:27:07 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_assign_index(t_liste *lst, t_list_param *nb)
{
	t_liste	*temp;
	t_liste	*highest;
	long	valeur;
	int		size_list;

	size_list = nb->size + 1;
	valeur = INT_MAX;
	while (--size_list > 0)
	{
		temp = lst;
		highest = NULL;
		highest = ft_index(temp, highest, valeur);
		if (highest != NULL)
		{
			highest->index = size_list;
			valeur = highest->content;
		}
	}
}

t_liste	*ft_index(t_liste *temp, t_liste *highest, long valeur)
{
	int	lowest;

	lowest = INT_MIN;
	while (temp)
	{
		if (temp->content == INT_MIN)
			temp->index = 1;
		else if (temp->content > lowest && temp->content < valeur)
		{
			lowest = temp->content;
			highest = temp;
		}
		temp = temp->next;
	}
	return (highest);
}
