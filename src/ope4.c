/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:39:42 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/10 11:54:06 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_reverse_rotate(t_liste **lst)
{
	t_liste	*last;
	t_liste	*tmp;
	t_liste	*before_last;

	if (!(*lst))
		return ;
	last = ft_lstlast_p((*lst));
	before_last = ft_lst_before_last((*lst));
	tmp = (*lst);
	(*lst) = last;
	(*lst)->next = tmp;
	before_last->next = NULL;
}

void	ft_rra(t_liste **liste_a)
{
	ft_reverse_rotate(liste_a);
	ft_putstr("rra\n");
}

void	ft_rrb(t_liste **liste_b)
{
	ft_reverse_rotate(liste_b);
	ft_putstr("rrb\n");
}

void	ft_rrr(t_liste **liste_a, t_liste **liste_b)
{
	ft_reverse_rotate(liste_a);
	ft_reverse_rotate(liste_b);
	ft_putstr("rrr\n");
}
