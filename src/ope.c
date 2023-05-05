/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:43:39 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/03 15:53:42 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_liste *lst)
{
	int	temp;

	if ((!lst->content) || (!lst->next->content))
		return ;
	temp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = temp;
	temp = lst->index;
	lst->index = lst->next->index;
	lst->next->index = temp;
}

void	ft_sa(t_liste *liste_a)
{
	if (!liste_a)
		return ;
	ft_swap(liste_a);
	write (1, "sa\n", 3);
}

void	ft_sb(t_liste *liste_b)
{
	if (!liste_b)
		return ;
	ft_swap(liste_b);
	write (1, "sb\n", 3);
}

void	ft_ss(t_liste *liste_a, t_liste *liste_b)
{
	ft_swap(liste_a);
	ft_swap(liste_b);
	write(1, "ss\n", 3);
}
