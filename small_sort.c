/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:04:08 by lazanett          #+#    #+#             */
/*   Updated: 2023/04/28 22:28:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void ft_sort_3(t_liste **lst)
{
    if (!lst || ft_already_class((*lst)) == 1)
        return ;
    else if (ft_already_class((*lst)) == 0)
        ft_posibility_sort_3(lst);
}

void ft_posibility_sort_3(t_liste **lst) // cas 3 non trier
{    
    int val1; 
    int val2; 
    int val3;

    val1 = (*lst)->content;
    val2 = (*lst)->next->content;
    val3 = (*lst)->next->next->content;
    if ((val1 < val2) && (val2 > val3 && val3 > val1)) // 1 3 2
    {
        ft_rra(lst);
        ft_sa((*lst));
    }
    else if ((val1 > val2) && (val2 > val3)) // 3 2 1 
    {
        ft_ra((*lst));
        ft_sa((*lst));
    }
    else if (val1 > val2 && (val2 < val3 && val3 < val1)) // 3 1 2
        ft_ra((*lst));
    else if (val1 > val2 && (val3 > val1 && val3 > val2)) // 2 1 3 
        ft_sa((*lst));
    else if (val1 < val2 && (val3 < val1 && val3 < val2)) // 2 3 1
        ft_rra(lst);
}

void ft_sort_5(t_liste **lst1, t_liste **lst2, t_list_param *nb)
{
    if (!lst1 || ft_already_class((*lst1)) == 1)
        return ;
    else if (ft_already_class((*lst1)) == 0)
    {
        ft_push_b_sort_5(lst1, lst2, nb);
        ft_sort_3(lst1);
        while (ft_len_list((*lst2)) != 0)
            ft_pa(lst1, lst2); 
    }
}

void ft_push_b_sort_5(t_liste **lst1, t_liste **lst2, t_list_param *nb)
{
    int i;
    
    i = nb->size;
    while (i != 3) // tant que liste a n'est pas composer de 3
    {
        ft_get_min((*lst1), nb);
        if ((*lst1)->content == nb->min) // min == index 0
            ft_pb(lst1, lst2);
        else if ((*lst1)->next->content == nb->min) // min == index 1
        {
            ft_sa((*lst1));
            ft_pb(lst1, lst2);
        }
        else
        {
            while ((*lst1)->content != nb->min) //tant que min n'est pas a l'index 0
                ft_rra(lst1);
            ft_pb(lst1, lst2);
        }
        i--;
    } 
}