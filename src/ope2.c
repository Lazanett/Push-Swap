/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:06:15 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/03 15:53:46 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_liste **src, t_liste **dest)
{
	t_liste	*push_b;

	if (src == NULL)
		return ;
	push_b = ft_lstnew_p((*src)->content);
	push_b->index = (*src)->index;
	ft_lstadd_front_p(dest, push_b);
	push_b = (*src)->next;
	ft_lstdelone_p(*src);
	*src = push_b;
}

void	ft_pa(t_liste **liste_a, t_liste **liste_b)
{
	push(liste_b, liste_a);
	ft_putstr("pa\n");
}

void	ft_pb(t_liste **liste_a, t_liste **liste_b)
{
	push(liste_a, liste_b);
	ft_putstr("pb\n");
}
