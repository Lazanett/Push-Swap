/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:46:35 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/03 15:53:23 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_get_cost(t_liste **a, t_liste **b)
{
	t_liste	*tmp_a;
	t_liste	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *a;
	tmp_b = *b;
	size_a = ft_len_list(tmp_a);
	size_b = ft_len_list(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->best_pos;
		if (tmp_b->best_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->best_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

void	ft_least_comb(t_liste **a, t_liste **b)
{
	t_liste	*tmp;
	int		comb_least;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	comb_least = INT_MAX;
	while (tmp)
	{
		if (ft_nb_conv(tmp->cost_a) + ft_nb_conv(tmp->cost_b)
			< ft_nb_conv(comb_least))
		{
			comb_least = ft_nb_conv(tmp->cost_b) + ft_nb_conv(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	ft_move(a, b, cost_a, cost_b);
}

int	ft_nb_conv(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
