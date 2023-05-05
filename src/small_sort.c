/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:04:08 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/03 15:54:06 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_3(t_liste **lst)
{
	if (!lst || ft_already_class((*lst)) == 1)
		return ;
	else if (ft_already_class((*lst)) == 0)
		ft_posibility_sort_3(lst);
}

void	ft_posibility_sort_3(t_liste **lst)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = (*lst)->content;
	val2 = (*lst)->next->content;
	val3 = (*lst)->next->next->content;
	if ((val1 < val2) && (val2 > val3 && val3 > val1))
	{
		ft_rra(lst);
		ft_sa((*lst));
	}
	else if ((val1 > val2) && (val2 > val3))
	{
		ft_ra((*lst));
		ft_sa((*lst));
	}
	else if (val1 > val2 && (val2 < val3 && val3 < val1))
		ft_ra((*lst));
	else if (val1 > val2 && (val3 > val1 && val3 > val2))
		ft_sa((*lst));
	else if (val1 < val2 && (val3 < val1 && val3 < val2))
		ft_rra(lst);
}
