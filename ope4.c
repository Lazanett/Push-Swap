/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:39:42 by lazanett          #+#    #+#             */
/*   Updated: 2023/04/13 17:01:44 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_reverse_rotate(t_liste **lst)
{
	t_liste *last;
	t_liste	*tmp;
	t_liste *before_last;

    if (!(*lst))
		return ;
    last = ft_lstlast_p((*lst)); //prend le dernier elem qui va etre le 1er
	before_last = ft_lst_before_last((*lst));// avant dernier 
	tmp = (*lst); // conserver l'ancien 1er elem
	(*lst) = last; // liste commence par last (nv 1er)
	(*lst)->next = tmp; 
	before_last->next = NULL; //dernier pointe sur null
}

void	ft_rra(t_liste **liste_a)//vers le bas tous les élements de A. dernier = premier.
{
	ft_reverse_rotate(liste_a);
	ft_putstr("rra\n");
}

void	ft_rrb(t_liste **liste_b)//reverse_rotate liste b
{
	ft_reverse_rotate(liste_b);
	ft_putstr("rrb\n");
}

void	ft_rrr(t_liste **liste_a, t_liste **liste_b)//reverse_rotate liste A ET B
{
	ft_reverse_rotate(liste_a);
    ft_reverse_rotate(liste_b);
	ft_putstr("rrr\n");
}
