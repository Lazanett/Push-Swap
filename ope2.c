/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:06:15 by lazanett          #+#    #+#             */
/*   Updated: 2023/04/28 19:30:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_liste **src, t_liste **dest)
{
	t_liste	*push_b;

	if (src == NULL)
		return ;
	push_b = ft_lstnew_p((*src)->content);
	push_b->index = (*src)->index;
	ft_lstadd_front_p(dest, push_b);
	push_b = (*src)->next; // sauvegarde un pointeur sur le 2 de B; //enlver pointeur sur src
	ft_lstdelone_p(*src);
	*src = push_b; //premier de src est egal au pointeur du 2
}

void	ft_pa(t_liste **liste_a, t_liste **liste_b)//1er elem au sommet de b et le met sur a
{
	push(liste_b, liste_a);
	ft_putstr("pa\n");
}

void	ft_pb(t_liste **liste_a, t_liste **liste_b)//1er elem au sommet de a et le met sur b
{
	push(liste_a, liste_b);
	ft_putstr("pb\n");
}