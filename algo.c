/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 07:47:02 by lazanett          #+#    #+#             */
/*   Updated: 2023/04/30 12:28:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	push_all_save_three(t_liste **lst1, t_liste **lst2, t_list_param *nb)
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
    //ft_printf("%i = size push all save 3\n", nb->size);
	while (nb->size > 6 && i < nb->size && pushed < nb->size / 2)//verif que lst1 
	{
		if ((*lst1)->index <= (nb->size / 2)) //si petite valeur envoie dans B (pres tri)
		{
			ft_pb(lst1, lst2);
			pushed++;
		}
		else //sinon envoie valeur vers la fin de A
			ft_ra((*lst1));
		i++;
	}
	while (nb->size - pushed > 3) 
	{
		ft_pb(lst1, lst2);
		pushed++;
	}
	
}

void	ft_final_sort(t_liste **lst1, t_list_param *nb)//tant que 1ere valeur n'est pas en 1er pos
{
	int	lowest_pos;

	lowest_pos = get_lowest_index_position(lst1);
	if (lowest_pos > nb->size / 2)
	{
		while (lowest_pos < nb->size) // si le + PETIT nb est parti inferieur de A
		{
			ft_rra(lst1);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0) // si le + PETIT nb est parti supérieur de A
		{
			ft_ra((*lst1));
			lowest_pos--;
		}
	}
}

void ft_sort(t_liste **lst1, t_liste **lst2, t_list_param *nb)
{
	ft_assign_index((*lst1), nb);
    push_all_save_three(lst1, lst2, nb);
    ft_sort_3(lst1);
    while (*lst2)
    {
        ft_best_pos(lst1, lst2);
        ft_get_cost(lst1, lst2);
        ft_least_comb(lst1, lst2);
    }
    if (ft_already_class((*lst1)) == 0)
        ft_final_sort(lst1, nb);
}