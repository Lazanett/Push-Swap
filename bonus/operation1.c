/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:29:22 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/10 13:52:32 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_liste *liste_a)
{
	if (!liste_a)
		return ;
	ft_swap(liste_a);
}

void	sb(t_liste *liste_b)
{
	if (!liste_b)
		return ;
	ft_swap(liste_b);
}

void	ss(t_liste *liste_a, t_liste *liste_b)
{
	ft_swap(liste_a);
	ft_swap(liste_b);
}

void	pa(t_liste **liste_a, t_liste **liste_b)
{
	push(liste_b, liste_a);
}

void	pb(t_liste **liste_a, t_liste **liste_b)
{
	push(liste_a, liste_b);
}
