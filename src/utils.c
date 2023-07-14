/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:44:12 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/03 17:22:40 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(char *msg, t_list_param *argument)
{
	ft_putendl_fd(msg, 2);
	if (argument->split == 1)
		ft_free(argument->tab);
	else
		free(argument->tab);
	exit(0);
}

int	nb_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	ft_lstadd_front_p(t_liste **lst, t_liste *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstdelone_p(t_liste *lst)
{
	if (lst == NULL)
		return ;
	if (lst)
		free(lst);
}
