/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 10:17:30 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/03 15:53:37 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rev_rotate_both(t_liste **a, t_liste **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		ft_rrr(a, b);
	}
}

void	ft_rotate_both(t_liste **a, t_liste **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		ft_rr((*a), (*b));
	}
}

void	ft_rotate_a(t_liste **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_ra((*a));
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rra(a);
			(*cost)++;
		}
	}
}

void	ft_rotate_b(t_liste **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ft_rb((*b));
			(*cost)--;
		}
		else if (*cost < 0)
		{
			ft_rrb(b);
			(*cost)++;
		}
	}
}

void	ft_move(t_liste **a, t_liste **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		ft_rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		ft_rotate_both(a, b, &cost_a, &cost_b);
	ft_rotate_a(a, &cost_a);
	ft_rotate_b(b, &cost_b);
	ft_pa(a, b);
}
