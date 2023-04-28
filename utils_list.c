/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lazanett <lazanett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:50:42 by lazanett          #+#    #+#             */
/*   Updated: 2023/04/13 15:44:07 by lazanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int ft_already_class(t_liste *lst) // deja trier 
{
    while (lst->next != NULL)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void ft_get_min(t_liste *lst, t_list_param *nb)
{
    int temp;

    temp = lst->content; // temp = 1er elem
    if (!lst)
        return ;
    while (lst->next != NULL) // tant qu'on n'est pas a l'avant dernier
    {
        if (lst->content < temp) // si la valeur du maillon sur lequel on est = + PETITE
            temp = lst->content; //temp = valeur +petite
        lst = lst->next; // on avance
    }
    if (lst->content < temp) // dernier elem est +petit
        temp = lst->content;
    nb->min = temp;
}

void ft_get_max(t_liste *lst, t_list_param *nb)
{
    int temp;

    temp = lst->content; // temp = 1er elem
    if (!lst)
        return ;
    while (lst->next != NULL)// tant qu'on n'est pas a l'avant dernier
    {
        if (lst->content > temp) // si la valeur du maillon sur lequel on est = + GRAND
            temp = lst->content;//temp = valeur +GRAND
        lst = lst->next;// on avance
    }
    if (lst->content > temp) // dernier elem est +grand
        temp = lst->content;
    nb->max = temp;
}

int ft_len(char **tab)
{
    int n;

	n = 0;
    while(tab[n])
        n++;
    return (n);
}

int ft_len_list(t_liste *lst)
{
    int i;

    i = 0;
    while (lst != NULL)
    {
        lst = lst->next;
        i++;
    }
    return (i);
}