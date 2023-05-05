/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:50:50 by lazanett          #+#    #+#             */
/*   Updated: 2023/05/03 18:24:08 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_swap(t_liste **lst1, t_liste **lst2, t_list_param *nb)
{
	if (nb->size == 2 && ft_already_class((*lst1)) == 0)
		ft_sa((*lst1));
	else if (nb->size == 3 && ft_already_class((*lst1)) == 0)
		ft_sort_3(lst1);
	else if ((nb->size > 3 && ft_already_class((*lst1)) == 0))
		ft_sort(lst1, lst2, nb);
}

int	main(int ac, char **av)
{
	t_list_param	argument;
	t_liste			*a;
	t_liste			*b;

	a = NULL;
	b = NULL;
	argument.size = 0;
	ft_check_args(ac, av, &argument);
	while (argument.tab[argument.size])
	{
		ft_lstadd_back_p(&a, ft_lstnew_p(ft_atoi(argument.tab[argument.size])));
		argument.size++;
	}
	if (argument.split == 1)
		ft_free(argument.tab);
	else
		free(argument.tab);
	ft_push_swap(&a, &b, &argument);
	free_lst(&a);
	free_lst(&b);
	return (0);
}
