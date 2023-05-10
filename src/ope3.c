/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:02:10 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/09 14:34:35 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate(t_liste *lst)
{
	int	temp;
	int	temp_index;

	temp = lst->content;
	temp_index = lst->index;
	while (lst->next != NULL)
	{
		lst->content = lst->next->content;
		lst->index = lst->next->index;
		lst = lst->next;
	}
	lst->content = temp;
	lst->index = temp_index;
}

void	ft_ra(t_liste *liste_a)
{
	ft_rotate(liste_a);
	ft_putstr("ra\n");
}

void	ft_rb(t_liste *liste_b)
{
	ft_rotate(liste_b);
	ft_putstr("rb\n");
}

void	ft_rr(t_liste *liste_a, t_liste *liste_b)
{
	ft_rotate(liste_a);
	ft_rotate(liste_b);
	ft_putstr("rr\n");
}
