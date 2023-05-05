/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:45:02 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/03 15:54:02 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_assign_position(t_liste **lst)
{
	t_liste	*temp;
	int		i;

	temp = *lst;
	i = 0;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

int	get_postion_elem(t_liste **a, int b_index, int best_index, int best_pos)
{
	t_liste	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_index && tmp_a->index < best_index)
		{
			best_index = tmp_a->index;
			best_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (best_index != INT_MAX)
		return (best_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < best_index)
		{
			best_index = tmp_a->index;
			best_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (best_pos);
}

void	ft_best_pos(t_liste **a, t_liste **b)
{
	t_liste	*temp_b;
	int		best_pos;

	temp_b = *b;
	ft_assign_position(a);
	ft_assign_position(b);
	best_pos = 0;
	while (temp_b)
	{
		best_pos = get_postion_elem(a, temp_b->index, INT_MAX, best_pos);
		temp_b->best_pos = best_pos;
		temp_b = temp_b->next;
	}
}

int	get_lowest_index_position(t_liste **lst)
{
	t_liste	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *lst;
	lowest_index = INT_MAX;
	ft_assign_position(lst);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}
