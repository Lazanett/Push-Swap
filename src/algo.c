/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 07:47:02 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/03 15:52:49 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_all_save_three(t_liste **lst1, t_liste **lst2, t_list_param *nb)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (nb->size > 6 && i < nb->size && pushed < nb->size / 2)
	{
		if ((*lst1)->index <= (nb->size / 2))
		{
			ft_pb(lst1, lst2);
			pushed++;
		}
		else
			ft_ra((*lst1));
		i++;
	}
	while (nb->size - pushed > 3)
	{
		ft_pb(lst1, lst2);
		pushed++;
	}	
}

void	ft_final_sort(t_liste **lst1, t_list_param *nb)
{
	int	lowest_pos;

	lowest_pos = get_lowest_index_position(lst1);
	if (lowest_pos > nb->size / 2)
	{
		while (lowest_pos < nb->size)
		{
			ft_rra(lst1);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ft_ra((*lst1));
			lowest_pos--;
		}
	}
}

void	ft_sort(t_liste **lst1, t_liste **lst2, t_list_param *nb)
{
	ft_assign_index((*lst1), nb);
	push_all_save_three(lst1, lst2, nb);
	ft_sort_3(lst1);
	while (*lst2)
	{
		ft_best_pos(lst1, lst2);
		ft_get_cost(lst1, lst2);
		ft_least_comb(lst1, lst2);
	}
	if (ft_already_class((*lst1)) == 0)
		ft_final_sort(lst1, nb);
}
