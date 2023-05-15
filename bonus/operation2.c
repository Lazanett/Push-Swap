/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:37:07 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/15 15:28:27 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_liste *liste_a)
{
	ft_rotate(liste_a);
}

void	rb(t_liste *liste_b)
{
	ft_rotate(liste_b);
}

void	rr(t_liste *liste_a, t_liste *liste_b)
{
	ft_rotate(liste_a);
	ft_rotate(liste_b);
}

void	rra(t_liste **liste_a)
{
	ft_reverse_rotate(liste_a);
}

void	rrb(t_liste **liste_b)
{
	ft_reverse_rotate(liste_b);
}
